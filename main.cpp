#include "dungeon.h"



int main()
{
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
    int nPiani = randRange(4, 6);
    cout << "Benvenuto avventuriero, sei pronto ad affrontare il piccolo Dungeon? \n (y/n): ";
    cin >> ingr;
    if (ingr != 'y')
    {
        cout << "Addio avventuriero, torna se vuoi conquistare il titolo di Eroe!"<< endl;
        return 0;
    }
    Hero PG = intro();
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
            nStanze = randRange(2, nPiani);
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
            float maxGsPiano = piano/(nPiani-1) * maxGS;
            float percGSmin = (ceil(maxGsPiano) - maxGsPiano) * (i+1) / nStanze;
            int gs = max(1, (int)ceil(maxGsPiano) - (randRange(0, 100)/100 <= percGSmin));

            //controllo Boss
            if(isBoss)
                mostro = RandMostro(0);
            else
                mostro = RandMostro(gs);
                //TODO implementare mostri multipli, rendere colpibili con armi melee solo il primo e con le ranged tutti a scelta

            bool isTreasure = randRange(0, 100)/100 <= gs / maxGS && piano != nPiani;
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
                cout << "Aprendo la cassa trovi: ";
                //int typeLoot = randRange(1,3); //per ora il tesoro sono solo armi, poi anche armature e oggetti uso singolo
                int typeLoot = 1;
                switch(typeLoot)
                {
                    case 1: //treasure is a weapon
                    {
                        bool alreadyFound = false;
                        Weapon weaponLoot = Treasure().randWeapon();
                        cout << weaponLoot.description;
                        for(Weapon w : PG.armi)
                        {
                            if(w.description == weaponLoot.description)
                            {
                                alreadyFound = true;
                                break;
                            }
                        }
                        if(alreadyFound)
                            cout << " di nuovo, quindi lo lasci indietro";
                        else
                            PG.armi.push_back(weaponLoot);
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
                PG.currentDmg -= PG.livello*5; 
                if (PG.currentDmg < 0)
                    PG.currentDmg = 0;
                PG.livello++;
            }
        }
    }
}