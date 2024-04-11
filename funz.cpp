#include "dungeon.h"

int randRange(int min, int max)
{
    return rand()%(max - min + 1)+min;
}

void turn(Hero& PG, Creature& mostro)
{
    bool isDefensive = false;
    int chosenAct, chosenWeapon;
    while(true){
        cout << '\n' << PG.nome <<  ", " << PG.livello << "°liv, ha " << PG.HP-PG.currentDmg << "/" << PG.HP << "hp e " << PG.AC << "ac" << endl;
        cout << "Scegli che azione vuoi fare:\n"
        << "1) Attaccare\n"
        << "2) Difendersi e bendare le proprie ferite\n"
        << "3) Osservare il " << mostro.nome << " per ottenere più informazioni" << endl;
        cout << "- ";
        if(!get_int(chosenAct))
        {
            cout << "Errore, ritentare comando" << endl;
            continue;
        }

        if(chosenAct > 0 && chosenAct < 4)
            break;

        cout << "\e[31mL'azione selezionata non esiste, ritentare!\e[0m" << endl;
            
    }
    switch(chosenAct)
    {
    case 1://attacco
        
        while(true)
        {
            //scelta arma
            if(PG.armi.size() == 1)
            {
                chosenWeapon = 1;
                break;
            }
            cout << "\nSelezionare un arma con cui attaccare: " << endl;
            for(int i = 0; i < PG.armi.size(); ++i)
            {
                Weapon arma = PG.armi[i];
                cout << i+1 << ") " << arma.description << " -> " << "tipo: " << dmg_type_to_string(arma.tipo) << ", danno: " 
                    << arma.num_dice << "d" << arma.max_dice << ", colpire: +" << arma.bonus + PG.livello << endl;
            }
            cout << "- ";
            if(!get_int(chosenWeapon))
            {
                cout << "Errore, ritentare comando" << endl;
                continue;
            }

            if(chosenWeapon >= 1 && chosenWeapon <= PG.armi.size())
                break;

            cout << "\e[31mL'arma selezionata non esiste, ritentare!\e[0m" << endl;
        }
        chosenWeapon--;
        
        //colpire
        if(PG.toHit(chosenWeapon) >= mostro.AC)
        {
            short dmg = PG.armi[chosenWeapon].damage();
            bool resistant = false, vulnerable = false;
            for(dmg_type type : mostro.res)
                if(PG.armi[chosenWeapon].tipo == type)
                {
                    resistant = true;
                    dmg = max(1, dmg/2);
                }
            for(dmg_type type : mostro.vuln)
            {
                if(PG.armi[chosenWeapon].tipo == type)
                {
                    vulnerable = true;
                    dmg *= 2;
                }
            }
            cout << "Colpisci " << mostro.nome << " con forza e gli hai inflitto " << dmg << " danni" 
                << (resistant ? ", ma noti che " + mostro.nome + " ha ridotto una parte dei danni subiti" : "")
                << (vulnerable ? ", ma noti che " + mostro.nome + " ha subito più danni" : "") << endl;

            mostro.currentDmg += dmg;
        }
        else
            cout << "L'hai mancato con " << PG.armi[chosenWeapon].description << endl;
        break;
    case 2://difesa
    {
        unsigned int cura = randRange(PG.livello, PG.livello*6);
        PG.AC += PG.livello;
        cout << "\nTieni la guardia alta (+" << PG.livello << " AC) e guarisci le tue ferite di " << cura << endl;
        PG.currentDmg -= cura;
        PG.currentDmg = max(0, PG.currentDmg);
        isDefensive = true;
        break;
    }
    case 3://osservazione
        if(mostro.isChecked)
            cout << "\nNon osservi nulla di più di quanto avevi già notato, se non che gli rimangono " << mostro.HP - mostro.currentDmg << " pf" << endl;
        cout << "Il " << mostro.nome << " ha:" << endl;
        if(!mostro.isChecked)
            cout << "Tra " << mostro.HP - mostro.GS << " e " << mostro.HP + mostro.GS << "hp" << endl;
        else
            cout << mostro.HP << "hp" << endl;
        cout << "Tra " << mostro.AC - mostro.GS << " e " << mostro.AC + mostro.GS << "AC" << endl
        << "È resistente a: ";
        for(dmg_type i:mostro.res) cout << dmg_type_to_string(i) << " ";
        cout << endl << "È vulnerabile a: ";
        for(dmg_type i:mostro.vuln) cout << dmg_type_to_string(i) << " ";
        cout << endl << "Può attaccare con: ";
        for(Weapon i:mostro.armi) cout << i.description << " ";
        cout << endl;
        mostro.isChecked = true;
        break;
    }
    //turno del mostro gestito automaticamente
    //per ora il mostro attacca e basta, in futuro implementare azioni diverse per i mostri 
    if(mostro.currentDmg >= mostro.HP)
        return;
    vector<Weapon> attackingWith;

    //special feature regeneration
    if(mostro.nome == "Troll" && mostro.currentDmg != 0)
    {
        mostro.currentDmg -= mostro.GS;
        mostro.currentDmg = max(0, mostro.currentDmg);
        if(mostro.isChecked)
            cout << "Noti con orrore che le ferite inflitte al Troll si richiudono a vista d'occhio" << endl;
    }

    if(mostro.multiAttack)
        attackingWith = mostro.armi;
    else
        attackingWith.push_back(mostro.armi[randRange(0, mostro.armi.size()-1)]);

    for(int i = 0; i < attackingWith.size(); ++i)
    {
        bool isHit = false;
        int dmg = attackingWith[i].damage();
        bool resistant = false, vulnerable = false;
        if(randRange(1,20) + attackingWith[i].bonus + mostro.GS >= PG.AC)
        {
            isHit = true;
            for(dmg_type type : PG.res)
                if(attackingWith[i].tipo == type)
                {
                    resistant = true;
                    dmg = max(1, dmg/2);
                }
            for(dmg_type type : PG.vuln)
                if(attackingWith[i].tipo == type)
                {
                    vulnerable = true;
                    dmg *= 2;
                }
            PG.currentDmg += dmg;
        }
        cout << mostro.nome << " ti attacca";
        if(mostro.isChecked)
                cout << " con " << attackingWith[i].description;
        cout << " e ";
        if(isHit)
        {
            cout << "ti colpisce infliggendoti " << dmg << " danni";
            if(resistant)
                cout << ", ma sei resistente (danno dimezzato)";
            if(vulnerable)
                cout << ", ma sei vulnerabile (danno raddoppiato)";
        }
        else
            cout << "ti manca";
        cout << endl;
    }
    if(isDefensive)
    {
        isDefensive = false;
        PG.AC -= PG.livello;
    }
}

bool get_int(int& choice)
{
    string buffer;
    cin >> buffer;
    for(char c : buffer)
        if(!isdigit(c))
            return false;
    choice = stoi(buffer);
    return true;
}

dmg_type string_to_dmg_type(const string& str)
{
    if(str == "Tagliente")
        return Tagliente;
    if(str == "Contundente")
        return Contundente;
    if(str == "Perforante")
        return Perforante;
    if(str == "Fuoco")
        return Fuoco;
    if(str == "Gelo")
        return Gelo;
    if(str == "Acido")
        return Acido;
    if(str == "Elettrico")
        return Elettrico;
}

string dmg_type_to_string(const dmg_type& type)
{
    switch (type)
    {
    case Tagliente:
        return "Tagliente";
    case Contundente:
        return "Contundente";
    case Perforante:
        return "Perforante";
    case Fuoco:
        return "Fuoco";
    case Gelo:
        return "Gelo";
    case Acido:
        return "Acido";
    case Elettrico:
        return "Elettrico";    
    }
    return "";
}