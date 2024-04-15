#include "headers/dungeon.h"

int randRange(int min, int max)
{
    return rand()%(max - min + 1)+min;
}

int diffSelection(int& minPiani, int& maxPiani, int& minStanze, int& maxStanze, int& maxGS)
{
    int choice;
    bool er;
    do{
        er = false;
        cout << "Selezionare la difficoltà desiderata:\n"
            << "1) Bimbo (nemici semplici, Dungeon grande, niente Boss)\n"
            << "2) Scudiero (nemici semplici, Dungeon standard)\n"
            << "3) Avventuriero (tutti i nemici, Dungeon stanard)\n"
            << "4) Veterano (tutti i nemici, Dungeon grande, Boss multipli)\n"
            << "5) Eroe (tutti i nemici, Dungeon piccolo)\n"
            << "6) Eroe Grandioso (tutti i nemici, Dungeon piccolo, Boss multipli)\n";
        if(!get_int(choice))
            er = true;
    }while(er || choice < 1 || choice > 6);
    
    //return 0 se non c'è il boss, 1 se c'è 1 boss, 2 se ci sono randRange(2,3) boss
    minPiani = 5;
    maxPiani = 7;
    minStanze = 2;
    maxStanze = 4;
    maxGS = 4;
    switch(choice)
    {
        case 1:
            minStanze ++;
            maxStanze ++;
            maxGS --;
            return 0;
        case 2:
            maxGS --;
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            minPiani --;
            maxPiani -= 2;
            maxStanze --;
            return 1;
        case 6:
            minPiani --;
            maxPiani -= 2;
            maxStanze --;
            return 2;
    }
}

void turn(Hero& PG, Creature& mostro)
{
    bool isDefensive = false;
    
    switch(PG.chooseAct(mostro.nome))
    {
    case 1://attacco0
        //scelta arma
        PG.chooseWeapon();
        //colpire
        if(PG.toHit() >= mostro.AC)
        {
            short dmg = PG.inventario.armi[PG.currentWeaponIndex].damage();
            mostro.hit(dmg, PG.inventario.armi[PG.currentWeaponIndex].tipo);
        }
        else
            cout << "L'hai mancato con " << PG.inventario.armi[PG.currentWeaponIndex].description << endl;
        break;
    case 2://difesa
        PG.defense(isDefensive);
        break;
    case 3://osservazione
        mostro.observed();
        break;
    }
    //turno del mostro gestito automaticamente
    //per ora il mostro attacca e basta, in futuro implementare azioni diverse per i mostri 
    if(mostro.currentDmg >= mostro.HP)
        return;

    mostro.turn(PG);

    //special feature regeneration
    if(mostro.nome == "Troll" && mostro.currentDmg > 0)
    {
        mostro.currentDmg -= 2;
        mostro.currentDmg = max(0, mostro.currentDmg);
        if(mostro.isChecked)
            cout << "Noti con orrore che le ferite inflitte al Troll si richiudono a vista d'occhio" << endl;
    }

    if(isDefensive)
    {
        isDefensive = false;
        PG.AC -= max(1, PG.livello * 2/3);
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