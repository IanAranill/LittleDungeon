#include "dungeon.h"

Creature Generate(Mostri_GS1 nome_mostro)
{
    Creature tmp;
    switch (nome_mostro)
    {
        case Mostri_GS1::ragno:
            tmp.AC = 12;
            tmp.HP = randRange(3, 8);
            tmp.GS = 1;
            tmp.nome = "Ragno";
            tmp.res = {Acido};
            tmp.armi = {
                Weapon("Zanne di ragno", Perforante, tmp.GS, 1, 6)
            };
            break;
        case Mostri_GS1::goblin:
            tmp.AC = 14;
            tmp.HP = randRange(2, 6);
            tmp.GS = 1;
            tmp.nome = "Goblin";
            tmp.res = {Tagliente};
            tmp.armi = {
                Weapon("Lancia di legno", Perforante, tmp.GS, 1, 6)
            };
            break;
    }
    return tmp;
}

Creature Generate(Mostri_GS2 nome_mostro)
{
    Creature tmp;
    switch (nome_mostro)
    {
        case Mostri_GS2::scheletro:
            tmp.AC = 12;
            tmp.HP = randRange(4, 12);
            tmp.GS = 2;
            tmp.nome = "Scheletro";
            tmp.res = {Tagliente, Perforante};
            tmp.vuln = {Contundente};
            tmp.armi = {
                Weapon("Artiglio", Tagliente, tmp.GS, 1, 4),
                Weapon("Artiglio", Tagliente, tmp.GS, 1, 4)
            };
            break;
   }
    return tmp;
}

Creature Generate(Mostri_GS3 nome_mostro)
{
    Creature tmp;
    switch (nome_mostro)
    {
        case Mostri_GS3::drago:
            tmp.AC = 18;
            tmp.HP = randRange(30, 45);
            tmp.GS = 3;
            tmp.nome = "Drago";
            tmp.res = {Tagliente, Contundente, Fuoco};
            tmp.vuln = {Gelo};
            tmp.armi = {
                Weapon("Fauci del Drago", Perforante, tmp.GS+2, 2, 6),
                Weapon("Artiglio del Drago", Tagliente, tmp.GS+1, 1, 6),
                Weapon("Artiglio del Drago", Tagliente, tmp.GS+1, 1, 6)
            };
            break;
    }
    return tmp;
}

Creature RandMostro(int GS)
{
    switch(GS)
    {
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
