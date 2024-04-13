#include "headers/dungeon.h"



int main()
{
    const int maxPiani = 6;
    const int minPiani = 4;
    const int maxStanze = 4;
    const int minStanze = 2;

    system(CHCP);
    system(CLEAR);

    //ASCII art, DON'T TOUCH!!!
    cout <<
    "   __ _ _   _   _           ___\n"    
    "  / /(_) |_| |_| | ___     /   \\_   _ _ __   __ _  ___  ___  _ __  \n"
    " / / | | __| __| |/ _ \\   / /\\ / | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\ \n"
    "/ /__| | |_| |_| |  __/  / /_//| |_| | | | | (_| |  __/ (_) | | | |\n"
    "\\____/_|\\__|\\__|_|\\___| /___,'  \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|\n"
    "                                            |___/                  \n"<< endl;

    srand(time(NULL));
    char ingr;
    int nPiani = randRange(minPiani, maxPiani);
    cout << "Benvenuto avventuriero, sei pronto ad affrontare il piccolo Dungeon? \n (y/n): ";
    cin >> ingr;
    if (ingr != 'y')
    {
        cout << "Addio avventuriero, torna se vuoi conquistare il titolo di Eroe!"<< endl;
        return 0;
    }
    Hero PG = chooseHero();
    cout << "Scendendo nel dungeon ..." << endl;
    
    bool stanzeMin = false;
    bool stanzeMax = false;
    for(int piano = 1; piano <= nPiani; ++piano){
        int nStanze;
        bool isBoss = false;

        //calcolo stanze
        if(piano == nPiani)
        {
            nStanze = 1;
            isBoss = true;
        }
        else
        {
            nStanze = randRange(minStanze, maxStanze);
            if(stanzeMin)
            {
                nStanze = min(nPiani, nStanze+1);
                stanzeMin = false;
            }
            if(stanzeMax)
            {
                nStanze = max(2, nStanze-1);
                stanzeMax = false;
            }
            if(nStanze == 2)
                stanzeMin = true;
            if(nStanze == nPiani)
                stanzeMax = true;
        }

        cout << "\n\n" << PG.nome << ", sei sceso al piano -" << piano << endl;
        cout << "In questo piano del dungeon ci sono " << nStanze << " stanze" << endl;
        for(int i = 0; i < nStanze; ++i){
            srand(time(NULL));
            Creature mostro;

            //calcolo gs
            int maxGS = 3;
            float maxGsPiano = piano/(nPiani-1.0) * maxGS;
            float percGSmin = 1 - (ceil(maxGsPiano) - maxGsPiano) * (i+1) / nStanze;
            if(percGSmin == 1)
                percGSmin = 0;
            int gs = max(1, (int)ceil(maxGsPiano) - (randRange(0, 100)/100.0 <= percGSmin));

            //controllo Boss
            if(isBoss)
                mostro = RandMostro(0);
            else
                mostro = RandMostro(gs);
                //TODO implementare mostri multipli, rendere colpibili con armi melee solo il primo e con le ranged tutti a scelta
            float probTreasure = gs / maxGS * 2;
            bool isTreasure = randRange(0, 100)/100.0 <= probTreasure && piano != nPiani;
            if(isBoss)
                cout << "\nSei arrivato alla tana del \e[31mSignore del Piccolo Dungeon\e[0m, ora devi dimostrare chi sei veramente, affrontalo e scopri se hai veramente la stoffa dell'\e[32mEroe\e[0m" << endl;
            else
                cout << "\nEntri nella "<< i+1 << "-esima stanza del piano dove " 
                    << (isTreasure ? "ci sono un " + mostro.nome + " e una cassa con dentro del tesoro" : "c'è un " + mostro.nome) << endl;
        //combattimento

            cout << '\n' + mostro.nome + " ti attacca" << endl;
            do{
                turn(PG, mostro);
            }while(PG.currentDmg < PG.HP && mostro.currentDmg < mostro.HP);

            if(PG.HP <= PG.currentDmg)
            {
                cout << "\e[31mSei stato sconfitto!\e[0m" << endl << "Oggi le tenebre hanno trionfato e il Signore del Piccolo Dungeon regna sovrano nelle sue caverne" << endl;
                system(PAUSE);
                return 0;
            }
            if(piano == nPiani)
            {
                cout << "\e[32mComplimenti Eroe Hai Vinto!\e[0m" << endl << "Oggi la luce ha trionfato e il signore del Piccolo Dungeon è caduto davanti alla tua forza" << endl;
                system(PAUSE);
                return 0;
            }
            cout << "Hai vinto!" << endl << "Hai sconfitto " << mostro.nome << "!" << endl;
        //ricompense
            PG.exp += mostro.GS;
            //tesoro
            if(isTreasure)
            {
                cout << "\nAprendo la cassa trovi: ";
                //int typeLoot = randRange(1,3); //per ora il tesoro sono solo armi, poi anche armature e oggetti uso singolo
                int typeLoot = 1;
                switch(typeLoot)
                {
                    case 1: //treasure is a weapon
                    {
                        bool alreadyFound = false;
                        Weapon weaponLoot = Treasure().randWeapon();
                        for(Weapon w : PG.inventario.armi)
                        {
                            if(w.description == weaponLoot.description)
                            {
                                alreadyFound = true;
                                break;
                            }
                        }
                        if(alreadyFound)
                            cout << weaponLoot.description << " ma ce l'hai già, quindi lo lasci indietro";
                        else
                        {
                            if(PG.inventario.numArmi == PG.inventario.armi.size())
                            {
                                weaponLoot.printStats(PG.livello);
                                PG.pick_up_weapon(weaponLoot);
                            }
                            else
                            {
                                cout << weaponLoot.description;
                                PG.inventario.armi.push_back(weaponLoot);
                                cout << " e lo raccogli" << endl;
                            }
                                
                        } 
                        cout << endl;
                    }

                }
                
            }
            //passaggio livello
            int nextLevel = PG.livello*1.5+1;
            if(PG.exp >= nextLevel)
            {
                cout <<"\n\nHai accumulato abbastanza esperienza per passare di livello!" << endl << "liv " << PG.livello << " -> " << PG.livello + 1 << "\n\n" << endl;
                PG.exp -= nextLevel;
                PG.HP*=5.0/4.0;
                PG.AC++;
                PG.currentDmg -= PG.livello*4; 
                if (PG.currentDmg < 0)
                    PG.currentDmg = 0;
                PG.livello++;
            }
        }
    }
}