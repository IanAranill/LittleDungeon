#include "headers/dungeon.h"


Creature Generate(Mostri_GS1 nome_mostro)
{
    int difference = randRange(-1, 1);
    Creature tmp;
    switch (nome_mostro)
    {
        case Mostri_GS1::ragno:
            tmp.AC = 12 + difference;
            tmp.HP = randRange(4, 10);
            tmp.GS = 1;
            tmp.nome = "Ragno";
            tmp.res = {Acido};
            tmp.armi = {
                Weapon("Zanne di ragno", Perforante, 0, 1, 6)
            };
            break;
        case Mostri_GS1::goblin:
        {
            tmp.AC = 14 + difference;
            tmp.HP = randRange(4, 8);
            tmp.GS = 1;
            tmp.nome = "Goblin";
            tmp.res = {Contundente};
            vector<Weapon> GoblinWeapons = {Weapon::Lancia_Corta, Weapon::Arco_Corto, Weapon::Mazza_Leggera};
            tmp.armi.push_back(GoblinWeapons[randRange(0, GoblinWeapons.size()-1)]);
            break;
        }
        case Mostri_GS1::ratto_gigante:
            tmp.AC = 11 + difference;
            tmp.HP = randRange(4, 9);
            tmp.GS = 1;
            tmp.nome = "Ratto Gigante";
            tmp.res = {Acido, Perforante};
            tmp.armi = {
                Weapon("Zanne di ratto", Perforante, 1, 1, 4)
            };
            break;
        case Mostri_GS1::bandito:
        {
            tmp.AC = 13 + difference;
            tmp.HP = randRange(5, 10);
            tmp.GS = 1;
            tmp.nome = "Bandito";
            tmp.res = {};
            vector<Weapon> BanditWeapons = {Weapon::Lancia, Weapon::Arco_Corto, Weapon::Mazza_Leggera, Weapon::Scimitarra, Weapon::Balestra_Leggera};
            tmp.armi.push_back(BanditWeapons[randRange(0, BanditWeapons.size()-1)]);
            break;
        }
    }
    return tmp;
}

Creature Generate(Mostri_GS2 nome_mostro)
{
    int difference = randRange(-1, 1);
    Creature tmp;
    switch (nome_mostro)
    {
        case Mostri_GS2::scheletro:
            tmp.AC = 12 + difference;
            tmp.HP = randRange(6, 14);
            tmp.GS = 2;
            tmp.nome = "Scheletro";
            tmp.res = {Tagliente, Perforante, Gelo};
            tmp.vuln = {Contundente};
            tmp.armi = {
                Weapon("Artiglio", Tagliente, 0, 1, 4),
                Weapon("Artiglio", Tagliente, 0, 1, 4)
            };
            break;
        case Mostri_GS2::zombie:
            tmp.AC = 10 + difference;
            tmp.HP = randRange(10, 20);
            tmp.GS = 2;
            tmp.nome = "Zombie";
            tmp.res = {Contundente, Perforante, Gelo};
            tmp.vuln = {Tagliente};
            tmp.armi = {
                Weapon("Morso", Perforante, -1, 1, 6),
                Weapon("Bava infetta", Acido, -1, 1, 4)
            };
            break;
        case Mostri_GS2::hobgoblin:
        {
            tmp.AC = 14 + difference;
            tmp.HP = randRange(9, 15);
            tmp.GS = 2;
            tmp.nome = "Hobgoblin";
            tmp.res = {Contundente};
            vector<Weapon> HobgoblinWeapons = {Weapon::Lancia, Weapon::Spada_Lunga, Weapon::Mazza_Leggera, Weapon::Alabarda};
            tmp.armi.push_back(HobgoblinWeapons[randRange(0, HobgoblinWeapons.size()-1)]);
            break;
        }
        case Mostri_GS2::gnoll:
        {
            tmp.AC = 14 + difference;
            tmp.HP = randRange(10, 18);
            tmp.GS = 2;
            tmp.nome = "Gnoll";
            vector<Weapon> GnollWeapons = {Weapon::Mazzafrusto, Weapon::Martello_Guerra, Weapon::Alabarda};
            tmp.armi.push_back(GnollWeapons[randRange(0, GnollWeapons.size()-1)]);
            break;
        }

   }
    return tmp;
}

Creature Generate(Mostri_GS3 nome_mostro)
{
    int difference = randRange(-1, 1);
    Creature tmp;
    switch(nome_mostro)
    {
        case Mostri_GS3::bugbear:
        {
            tmp.AC = 16 + difference;
            tmp.HP = randRange(12, 22);
            tmp.GS = 3;
            tmp.nome = "Bugbear";
            vector<Weapon> BugbearWeapons = {Weapon::Mazzafrusto, Weapon::Alabarda, Weapon::Ascia_Bipenne, Weapon::Spadone};
            tmp.armi.push_back(BugbearWeapons[randRange(0, BugbearWeapons.size()-1)]);
            break;
        }
        case Mostri_GS3::orco:
        {
            tmp.AC = 13 + difference;
            tmp.HP = randRange(16, 22);
            tmp.GS = 3;
            tmp.nome = "Orco";
            tmp.res = {Tagliente, Contundente, Perforante};
            tmp.vuln = {Fuoco, Acido, Elettrico, Gelo};
            vector<Weapon> OrcWeapons = {Weapon::Ascia_Bipenne, Weapon::Gran_Martello};
            tmp.armi.push_back(OrcWeapons[randRange(0, OrcWeapons.size()-1)]);
            break;
        }
        case Mostri_GS3::goblin_stregone:
            tmp.AC = 17 + difference;
            tmp.HP = randRange(5, 10);
            tmp.GS = 3;
            tmp.nome = "Goblin Stregone";
            tmp.multiAttack = false;
            tmp.armi = {
                Weapon("Dardo di Fuoco", Fuoco, +2, 1, 10),
                Weapon("Gelo Profondo", Gelo, +2, 1, 10),
                Weapon("Fulmine", Elettrico, +3, 2, 6),
                Weapon("Eruzione di Acido", Acido, +2, 3, 4)
            };
            break;
    }
    return tmp;
}

Creature Generate(Mostri_Boss nome_mostro)
{
    int difference = randRange(-1, 1);
    Creature tmp;
    switch (nome_mostro)
    {
        case Mostri_Boss::drago:
            tmp.AC = 20 + difference;
            tmp.HP = randRange(30, 45);
            tmp.GS = 4;
            tmp.nome = "Drago";
            tmp.res = {Tagliente, Contundente, Fuoco};
            tmp.vuln = {Gelo};
            tmp.armi = {
                Weapon("Fauci del Drago", Perforante, +4, 2, 6),
                Weapon("Artiglio", Tagliente, +3, 1, 6),
                Weapon("Artiglio", Tagliente, +3, 1, 6),
                Weapon("Colpo di Coda", Contundente, +1, 1, 10)
            };
            break;
        case Mostri_Boss::troll:
            tmp.AC = 16 + difference;
            tmp.HP = randRange(20, 35);
            tmp.GS = 4;
            tmp.nome = "Troll";
            tmp.res = {Perforante, Contundente};
            tmp.vuln = {Fuoco, Acido};
            tmp.armi = {
                Weapon("Fauci", Perforante, +3, 2, 4),
                Weapon("Artiglio", Tagliente, +3, 2, 4),
                Weapon("Artiglio", Tagliente, +3, 2, 4)
            };
            break;
        case Mostri_Boss::orco_capoguerra:
        {
            tmp.AC = 19 + difference;
            tmp.HP = randRange(30, 40);
            tmp.GS = 4;
            tmp.nome = "Orco Capoguerra";
            tmp.res = {Perforante, Contundente, Tagliente};
            tmp.vuln = {};
            tmp.armi = {Weapon("Spadone di Gruumsh", Tagliente, +4, 3, 6)};
            break;
        }
    }
    return tmp;
}

Creature RandMostro(int GS)
{
    switch(GS)
    {
        case 0:
            return Generate(static_cast<Mostri_Boss>(randRange(0, (int)Mostri_Boss::dimensione-1)));
        case 1:
            return Generate(static_cast<Mostri_GS1>(randRange(0, (int)Mostri_GS1::dimensione-1)));
        case 2:
            return Generate(static_cast<Mostri_GS2>(randRange(0, (int)Mostri_GS2::dimensione-1)));
        case 3:
            return Generate(static_cast<Mostri_GS3>(randRange(0, (int)Mostri_GS3::dimensione-1)));
        default:
            throw(string) "Error104 Mostro mal generato";
    }
}

void Creature::observed()
{
    int difference = randRange(1, GS);
    if(isChecked)
            cout << "\nIn più a quello che avevi già osservato noti che gli rimangono " << HP - currentDmg << " pf" << endl;
    cout << "Il " << nome << " ha:" << endl;
    if(!isChecked)
        cout << "Tra " << HP - difference << " e " << HP + difference << "hp" << endl;
    else
        cout << HP << "hp" << endl;
    cout << "Tra " << AC - difference << " e " << AC + difference << "AC" << endl

    << "È resistente a: ";
    for(int i = 0; i < res.size(); ++i)
        cout << dmg_type_to_string(res[i]) << (i < res.size()-1 ? ", " : "");

    cout << endl << "È vulnerabile a: ";
    for(int i = 0; i < vuln.size(); ++i)
        cout << dmg_type_to_string(vuln[i]) << (i < res.size()-1 ? ", " : "");

    cout << endl << "Può attaccare con: ";
    for(int i = 0; i < armi.size(); ++i)
        cout << armi[i].description << (i < res.size()-1 ? ", " : "");

    cout << endl;
    isChecked = true;
    return;
}

void Creature::hit(short& dmg, dmg_type atkType)
{
    bool resistant = false, vulnerable = false;
    for(dmg_type type : res)
        if(atkType == type)
        {
            resistant = true;
            dmg = max(1, dmg/2);
        }
    for(dmg_type type : vuln)
    {
        if(atkType == type)
        {
            vulnerable = true;
            dmg *= 2;
        }
    }
    cout << "Colpisci " << nome << " con forza e gli hai inflitto " << dmg << " danni" 
        << (resistant ? ", ma noti che " + nome + " ha ridotto una parte dei danni subiti" : "")
        << (vulnerable ? ", e noti che " + nome + " ha subito più danni" : "") << endl;

    currentDmg += dmg;
}

void Creature::turn(Hero& PG)
{
    vector<Weapon> attackingWith;
    if(multiAttack)
        attackingWith = armi;
    else
        attackingWith.push_back(armi[randRange(0, armi.size()-1)]);
        
    for(int i = 0; i < attackingWith.size(); ++i)
    {
        bool isHit = false;
        int dmg = attackingWith[i].damage();
        bool resistant = false, vulnerable = false;
        if(randRange(1,20) + attackingWith[i].bonus + GS >= PG.AC)
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
        cout << nome << " ti attacca";
        if(isChecked)
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
}