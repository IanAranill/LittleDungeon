#include "headers/dungeon.h"

void Hero::charCreation()
{
    bool Er = false;
    int choice;
    cout << "\nCreazione del Personaggio:" << endl;
    do{
        Er = false;
        cout << "Selezionare una clase" << '\n'
        << "1) Guerriero: 16 HP, 14 AC, 4 armi trasportabili, resistente tagliente" << '\n'
        << "\tarma: " ; Weapon(Weapon::Spada_Lunga).printStats(1);
        cout << "2) Ranger: 15 HP, 15 AC, 4 armi trasportabili, resistente acido" <<'\n'
        << "\tarma: " ; Weapon(Weapon::Arco_Lungo).printStats(1);
        cout << "3) Barbaro: 18 HP, 13 AC, 5 armi trasportabili, resistente contundente e perforante, vulnerabile acido" << '\n'
        << "\tarma: " ; Weapon(Weapon::Ascia_Bipenne).printStats(1);
        cout << "4) Mago: 12 HP, 16 AC, 4 armi trasportabili, resistente fuoco e gelo, vulnerabile perforante" << '\n'
        << "\tarma: " ; Weapon(Weapon::Bacchetta_Raggio_Gelo).printStats(1);
        cout << "5) Bardo: 14 HP, 15 AC, 5 armi trasportabili, resitente fuoco, vulnerabile gelo" << '\n'
        << "\tarma: " ; Weapon(Weapon::Liuto).printStats(1);
        cout << "Scegi il tuo eroe: ";
        if(!get_int(choice))
            Er = true;

        system(CLEAR);
    }while(Er || (choice <= 0 && choice > 5));
    
    dataClass(choice);
    do{
        Er = false;
        cout << "Selezionare una razza" << '\n'
        << "1) Un agile elfo delle foreste: -1 HP, +2 AC, -1 numero armi trasportabili, vulnerabile acido, resitente elettrico" << '\n'
        << "2) Un prode umano: +3 HP" <<'\n'
        << "3) Un cocciuto nano delle montagne: -1 AC, +1 numero armi trasportabili, vulnerabile fuoco, resistente contundente" << '\n'
        << "Scegi il tuo eroe: ";
        if(!get_int(choice))
            Er = true;

        system(CLEAR);
    }while(Er || choice <= 0 || choice > 3);

    dataRace(choice);
    printStats();
    do
    {
        cout << "\nVuoi inoltrarti nel dungeon con questo eroe?\n"
        << "1) Che l'avventura abbia inizio!\n"
        << "2) Voglio ricominciare la creazione del personaggio\n"
        << "Scegli con cautela: ";
        if(!get_int(choice))
            Er = true;
        if(choice == 2)
        {
            charCreation();
            return;
        }
        system(CLEAR);
    }while(Er || choice != 1);
    cout << "Come si chiama il tuo eroe?" << endl;
    cin.ignore(9999, '\n');
    getline(cin, nome);
    cin.ignore(0);
    system(CLEAR);
}

void Hero::dataRace(int choice)
{
    switch(choice)
    {
        case 1:
            HP -= 1;
            AC += 2;
            inventario.numArmi -= 1;
            vuln.push_back(Acido);
            res.push_back(Elettrico);
            break;
        case 2:
            HP += 3;
            break;
        case 3:
            AC -= 1;
            inventario.numArmi += 1;
            vuln.push_back(Fuoco);
            res.push_back(Contundente);
    }
}

void Hero::dataClass(int choice)
{
    switch(choice)
    {
        case 1:
            HP = 16;
            AC = 14;
            inventario.numArmi = 4;
            vuln = {};
            res = {Tagliente};
            inventario.armi = {Weapon::Spada_Lunga};
            break;
        case 2:
            HP = 15;
            AC = 15;
            inventario.numArmi = 4;
            vuln = {};
            res = {Acido};
            inventario.armi = {Weapon::Arco_Lungo};
            break;
        case 3:
            HP = 18;
            AC = 13;
            inventario.numArmi = 5;
            vuln = {Acido};
            res = {Contundente, Perforante};
            inventario.armi = {Weapon::Ascia_Bipenne};
            break;
        case 4:
            HP = 12;
            AC = 16;
            inventario.numArmi = 4;
            vuln = {Perforante};
            res = {Fuoco, Gelo};
            inventario.armi = {Weapon::Bacchetta_Raggio_Gelo};
            break;
        case 5:
            HP = 14;
            AC = 15;
            inventario.numArmi = 5;
            vuln = {Gelo};
            res = {Fuoco};
            inventario.armi = {Weapon::Liuto};
            break;
    }
}

void Hero::defense(bool& isDefensive)
{
    unsigned int cura = randRange(1, 3) * livello;
    AC += max(1, livello * 2/3);
    cout << "\nTieni la guardia alta (+" << max(1, livello*2/3) << " AC) e guarisci le tue ferite di " << cura << endl;
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
        return;
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
    << "3) Osservare " << nemico << " per ottenere più informazioni" << endl;
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
    cout << "Le statistiche dell'eroe selezionato sono le seguenti:" << endl;
    cout << "\nHP: " << HP
    << "\nAC: " << AC 
    << "\nLivello: " << livello
    << "\nExp: " << exp
    << "\nDimensione Inventario: " << inventario.numArmi << endl;

    cout << "Armi: ";
    for(int i = 0; i < inventario.armi.size(); ++i)
        cout << inventario.armi[i].description << (i < inventario.armi.size()-1 ? ", " : "");
    
    cout <<"\nResistenze: ";
    for(int i = 0; i < res.size(); ++i)
        cout << dmg_type_to_string(res[i]) << (i < res.size()-1 ? ", " : "");

    cout <<"\nVulnerabilità: ";
    for(int i = 0; i < vuln.size(); ++i)
        cout << dmg_type_to_string(vuln[i]) << (i < vuln.size()-1 ? ", " : "");

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