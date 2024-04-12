#include "headers/dungeon.h"

int randRange(int min, int max)
{
    return rand()%(max - min + 1)+min;
}

void turn(Hero& PG, Creature& mostro)
{
    bool isDefensive = false;
    
    switch(PG.chooseAct(mostro.nome))
    {
    case 1://attacco
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
        mostro.currentDmg -= mostro.GS;
        mostro.currentDmg = max(0, mostro.currentDmg);
        if(mostro.isChecked)
            cout << "Noti con orrore che le ferite inflitte al Troll si richiudono a vista d'occhio" << endl;
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