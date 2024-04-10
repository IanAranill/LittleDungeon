#include "dungeon.h"

const Hero Hero::Elfo(15, 16, {Weapon::Arco_Lungo}, {Elettrico}, {Acido});
const Hero Hero::Umano(18, 16, {Weapon::Spada_Lunga}, {}, {});
const Hero Hero::Nano(20, 14, {Weapon::Ascia_Bipenne}, {Contundente}, {Fuoco});
const Hero Hero::Omomo(15, 15, {Weapon::Flauto}, {Perforante}, {Tagliente});
const Hero Hero::Cretino(15, 14, {Weapon::Bastoncino}, {}, {});

Hero intro(){
    unsigned int choice;
    Hero PG;
    do{
        do{
            cout << "Chi sei avventuriero?" << '\n'
            << "1) Un agile elfo delle foreste, un arciere eccellente" << '\n'
            << "2) Un prode umano, uno spadaccino fomidabile" << '\n'
            << "3) Un cocciuto nano delle montagne, pochi vogliono affrontare la sua ascia" << '\n'
            << "Scegi il tuo eroe: ";
            cin >> choice;
            system("clear");
        }while(choice != 0 && choice > 3 && choice != 69 && choice != 104);
        stats(choice, PG);
        cout << "\nVuoi inoltrarti nel dungeon con questo eroe?\n"
            << "1) Che l'avventura abbia inizio!\n"
            << "2) Quali è che sono gli altri?\n"
            << "Scegli con cautela: ";
        cin >> choice;
        system("clear");
    }while(choice != 1);
    cout << "Come si chiama il tuo eroe?" << endl;
    cin.ignore(9999, '\n');
    getline(cin, PG.nome);
    system("clear");
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

int Hero::toHit(int WeaponIndex)
{
    return randRange(1, 20) + livello + armi[WeaponIndex].bonus;
}

void Hero::printStats()
{
    cout << "\nHP: " << HP
    << "\nAC: " << AC 
    << "\nLivello: " << livello
    << "\nExp: " << exp << endl;
    cout << "Armi: ";
    for(Weapon w : armi)
        cout << w.description << (w.description != armi.back().description ? ", " : "");
    cout <<"\nResistenze: ";
    for(dmg_type dmg : res)
        cout << dmg_type_to_string(dmg) << (dmg != res.back() ? ", " : "");
    cout <<"\nVulnerabilità: ";
    for(dmg_type dmg : vuln)
        cout << dmg_type_to_string(dmg) << (dmg != vuln.back() ? ", " : "");
    cout << endl;
    return;
}