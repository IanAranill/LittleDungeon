#include "dungeon.h"

int main()
{
    srand(time(NULL));
    char ingr;
    int nPiani = randRange(3, 5);
    cout << "Benvenuto avventuriero, sei pronto ad affrontare il piccolo Dungeon? \n (y/n): ";
    cin >> ingr;
    if (ingr != 'y')
    {
        cout << "Addio avventuriero, torna se vuoi conquistare il titolo di Eroe!"<< endl;
        return 0;
    }
    Hero PG = intro();
    cout << "Scendendo nel dungeon ..." << endl;
    
    for(int piano = 1; piano <= nPiani; ++piano){
        int nStanze;
        if(piano == nPiani)
            nStanze = 1;
        else
            nStanze = randRange(1, nPiani);

        cout << "\n\n" << PG.nome << ", sei sceso al piano -" << piano << endl;
        for(int i = 0; i < nStanze; ++i){
            srand(time(NULL));
            int maxGS = 3;
            float percDiff = piano/(nPiani-1) * maxGS;
            float percGSvecchio = (ceil(percDiff) - percDiff) * (i+1) / nStanze;
            //TODO dare l'effettivo gs del mostro in questione in base a numeri precedenti
            int gs = piano; 
            Creature mostro = RandMostro(gs);

            //TODO implementare mostri multipli, rendere colpibili con armi melee solo il primo e con le ranged tutti a scelta
            bool isTreasure = true;
            if(piano == 1)
                isTreasure = (bool)randRange(0, 1);

            cout << "In questo piano del dungeon ci sono " << nStanze << " stanze" << endl
                << "dopo essere entrato vedi che nella "<< i+1 << "-esima stanza del piano " 
                << (isTreasure ? "ci sono un " + mostro.nome + " e una cassa con dentro del tesoro" : "c'è un " + mostro.nome) << endl;
        //combattimento

            cout << '\n' + mostro.nome + " ti attacca" << endl;
            do{
                turn(PG, mostro);
            }while(PG.currentDmg < PG.HP && mostro.currentDmg < mostro.HP);

            if(PG.HP <= PG.currentDmg)
            {
                cout << "\e[31mSei stato sconfitto!\e[0m" << endl << "Oggi le tenebre hanno trionfato e il signore del Piccolo Dungeon regna sovrano nelle sue caverne" << endl;
                return 0;
            }
            if(piano == nPiani)
            {
                cout << "\e[32mHai Vinto!\e[0m" << endl << "Oggi la luce ha trionfato e il signore del Piccolo Dungeon è caduto davanti alla tua forza" << endl;
                return 0;
            }
            cout << "Hai vinto!" << endl << "Hai sconfitto il " << mostro.nome << "!" << endl;
        //ricompense
            PG.exp += mostro.GS;
            //tesoro
            if(isTreasure)
            {
                cout << "Aprendo la cassa trovi: ";
                //int typeLoot = randRange(1,3); //per ora il tesoro sono solo armi
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
            if(PG.exp >= (int)PG.livello*1.5)
            {
                cout <<"\n\nHai accumulato abbastanza esperienza per passare di livello!" << endl << "liv " << PG.livello << " -> " << PG.livello + 1 << "\n\n" << endl;
                PG.exp -= PG.livello;
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