#include "dungeon.h"

const Weapon Weapon::Arco_Lungo("Arco Lungo", Perforante, 1, 1, 8, false);
const Weapon Weapon::Spada_Lunga("Spada Lunga", Tagliente, 1, 1, 8, true);
const Weapon Weapon::Ascia_Bipenne("Ascia Bipenne", Tagliente, 0, 1, 12, true);
const Weapon Weapon::Flauto("Possente Flauto", Perforante, 3, 1, 6, false);
const Weapon Weapon::Bastoncino("Spada del Destino AKA spada di legno", Contundente, 0, 2, 2, true);

int Weapon::damage()
{
    int tmp = 0;
    for(int i = 0; i < num_dice; ++i)
        tmp += randRange(1, max_dice);
    return tmp;
}