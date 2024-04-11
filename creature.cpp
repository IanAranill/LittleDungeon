#include "dungeon.h"


Creature Generate(Mostri_GS1 nome_mostro)
{
    int difference = randRange(-1, 1);
    Creature tmp;
    switch (nome_mostro)
    {
        case Mostri_GS1::ragno:
            tmp.AC = 12 + difference;
            tmp.HP = randRange(3, 8);
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
            tmp.HP = randRange(2, 6);
            tmp.GS = 1;
            tmp.nome = "Goblin";
            tmp.res = {Contundente};
            vector<Weapon> GoblinWeapons = {Weapon::Lancia_Corta, Weapon::Arco_Corto, Weapon::Mazza_Leggera};
            tmp.armi.push_back(GoblinWeapons[randRange(0,GoblinWeapons.size()-1)]);
            break;
        }
        case Mostri_GS1::ratto_gigante:
            tmp.AC = 11 + difference;
            tmp.HP = randRange(2, 7);
            tmp.GS = 1;
            tmp.nome = "Ratto Gigante";
            tmp.res = {Acido, Perforante};
            tmp.armi = {
                Weapon("Zanne di ratto", Perforante, 1, 1, 4)
            };
            break;
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
            tmp.HP = randRange(4, 12);
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
            tmp.HP = randRange(8, 20);
            tmp.GS = 2;
            tmp.nome = "Zombie";
            tmp.res = {Contundente, Perforante, Gelo};
            tmp.vuln = {Tagliente};
            tmp.armi = {
                Weapon("Morso", Perforante, 0, 1, 6),
                Weapon("Bava infetta", Acido, -1, 1, 4)
            };
            break;
        case Mostri_GS2::hobgoblin:
        {
            tmp.AC = 14 + difference;
            tmp.HP = randRange(5, 9);
            tmp.GS = 2;
            tmp.nome = "Hobgoblin";
            tmp.res = {Contundente};
            vector<Weapon> HobgoblinWeapons = {Weapon::Lancia, Weapon::Spada_Lunga, Weapon::Mazza_Leggera, Weapon::Alabarda};
            tmp.armi.push_back(HobgoblinWeapons[randRange(0,HobgoblinWeapons.size()-1)]);
            break;
        }
        case Mostri_GS2::gnoll:
        {
            tmp.AC = 14 + difference;
            tmp.HP = randRange(5, 13);
            tmp.GS = 2;
            tmp.nome = "Gnoll";
            vector<Weapon> GnollWeapons = {Weapon::Mazzafrusto, Weapon::Martello_Guerra, Weapon::Alabarda};
            tmp.armi.push_back(GnollWeapons[randRange(0,GnollWeapons.size()-1)]);
            break;
        }

   }
    return tmp;
}

Creature Generate(Mostri_GS3 nome_mostro)
{
    int difference = randRange(-1, 1);
    Creature tmp;
    switch (nome_mostro)
    {
        case Mostri_GS3::bugbear:
        {
            tmp.AC = 16 + difference;
            tmp.HP = randRange(8, 20);
            tmp.GS = 3;
            tmp.nome = "Bugbear";
            vector<Weapon> BugbearWeapons = {Weapon::Mazzafrusto, Weapon::Mazzafrusto, Weapon::Ascia_Bipenne, Weapon::Spadone};
            tmp.armi.push_back(BugbearWeapons[randRange(0,BugbearWeapons.size()-1)]);
            break;
        }
        case Mostri_GS3::orco:
            tmp.AC = 13 + difference;
            tmp.HP = randRange(10, 18);
            tmp.GS = 3;
            tmp.nome = "Orco";
            tmp.res = {Tagliente, Contundente, Perforante};
            tmp.vuln = {Fuoco, Acido, Elettrico, Gelo};
            tmp.armi = {Weapon::Ascia_Bipenne};
            break;
        case Mostri_GS3::goblin_stregone:
            tmp.AC = 17 + difference;
            tmp.HP = randRange(3, 8);
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
            tmp.AC = 18 + difference;
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