#include "headers/dungeon.h"

Hero intro(){
    int choice;
    Hero PG;
    bool Er;
    do{
        Er = false;
        do{
            Er = false;
            cout << "Chi sei avventuriero?" << '\n'
            << "1) Un agile elfo delle foreste, un arciere eccellente" << '\n'
            << "2) Un prode umano, uno spadaccino formidabile" << '\n'
            << "3) Un cocciuto nano delle montagne, pochi vogliono affrontare la sua ascia" << '\n'
            << "Scegi il tuo eroe: ";
            if(!get_int(choice))
                Er = true;

            system(CLEAR);
        }while(Er || (choice <= 0 && choice > 3 && choice != 69 && choice != 104));
        stats(choice, PG);
        cout << "\nVuoi inoltrarti nel dungeon con questo eroe?\n"
            << "1) Che l'avventura abbia inizio!\n"
            << "2) Quali sono gli altri?\n"
            << "Scegli con cautela: ";
        if(!get_int(choice))
            Er = true;

        system(CLEAR);
    }while(Er || choice != 1);
    cout << "Come si chiama il tuo eroe?" << endl;
    cin.ignore(9999, '\n');
    getline(cin, PG.nome);
    system(CLEAR);
    return PG;
}

void stats(unsigned int choosen, Hero& PG)
{
    cout << "Le statistiche dell'eroe selezionato sono le seguenti:" << endl;
    switch (choosen)
    {
    case 1:
        PG = Hero::Elfo;
        break;
    case 2:
        PG = Hero::Umano;
        break;
    case 3:
        PG = Hero::Nano;
        break;
    case 69:
        PG = Hero::Omomo;
        break;
    case 104:
        PG = Hero::Cretino;
        break;
    }
    PG.printStats();
    return;
}

void Hero::defense(bool& isDefensive)
{
    unsigned int cura = randRange(livello, livello*6);
    AC += livello;
    cout << "\nTieni la guardia alta (+" << livello*3/2 << " AC) e guarisci le tue ferite di " << cura << endl;
    currentDmg -= cura;
    currentDmg = max(0, currentDmg);
    isDefensive = true;
    return;
}

void Hero::chooseWeapon()
{
    if(inventario.armi.size() == 1)
    {
        currentWeaponIndex = 0;
        return;
    }
    cout << "\nSelezionare un arma con cui attaccare: " << endl;
    for(int i = 0; i < inventario.armi.size(); ++i)
    {
        Weapon arma = inventario.armi[i];
        cout << i+1 << ") " << arma.description << " -> " << "tipo: " << dmg_type_to_string(arma.tipo) << ", danno: " 
            << arma.num_dice << "d" << arma.max_dice << ", colpire: +" << arma.bonus + livello << endl;
    }
    cout << "- ";

    if(!get_int(currentWeaponIndex) || currentWeaponIndex < 1 || currentWeaponIndex > inventario.armi.size())
    {
        cout << "\e[31mL'arma selezionata non esiste, ritentare!\e[0m" << endl;
        chooseWeapon();
    }
    currentWeaponIndex--;
    return;
}

int Hero::chooseAct(const string& nemico)
{
    int chosenAct;
    cout << '\n' << nome <<  ", " << livello << "°liv, ha " << HP - currentDmg << "/" << HP << "hp e " << AC << "ac" << endl;
    cout << "Scegli che azione vuoi fare:\n"
    << "1) Attaccare\n"
    << "2) Difendersi e bendare le proprie ferite\n"
    << "3) Osservare il " << nemico << " per ottenere più informazioni" << endl;
    cout << "- ";
    if(!get_int(chosenAct) || chosenAct <= 0 || chosenAct >= 4)
    {
        cout << "\e[31mL'azione selezionata non esiste, ritentare!\e[0m" << endl;
        return chooseAct(nemico);
    }
    return chosenAct;
}

int Hero::toHit()
{
    return randRange(1, 20) + livello + inventario.armi[currentWeaponIndex].bonus;
}

void Hero::printStats()
{
    cout << "\nHP: " << HP
    << "\nAC: " << AC 
    << "\nLivello: " << livello
    << "\nExp: " << exp
    << "\nDimensione Inventario: " << inventario.numArmi << endl;
    cout << "Armi: ";
    for(Weapon w : inventario.armi)
        cout << w.description << (w.description != inventario.armi.back().description ? ", " : "");
    cout <<"\nResistenze: ";
    for(dmg_type dmg : res)
        cout << dmg_type_to_string(dmg) << (dmg != res.back() ? ", " : "");
    cout <<"\nVulnerabilità: ";
    for(dmg_type dmg : vuln)
        cout << dmg_type_to_string(dmg) << (dmg != vuln.back() ? ", " : "");
    cout << endl;
    return;
}

void Hero::pick_up_weapon(Weapon weaponLoot)
{
    cout << "non puoi trasportare altre armi, cosa vuoi abbandonare?" << endl;
    cout << "\n0) nulla" << endl;
    for(int i = 1; i <= inventario.armi.size(); ++i)
    {
        cout << i << ") "; 
        inventario.armi[i-1].printStats(livello);
    }
    cout << "- ";
    int choice;
    if(!get_int(choice) || choice < 0 || choice > inventario.armi.size())
    {
        cout << "\e[31mL'arma selezionata non esiste, ritentare!\e[0m" << endl;
        pick_up_weapon(weaponLoot);
    }
    if(choice)
        inventario.armi[choice-1] = weaponLoot;
}