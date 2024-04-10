#include "dungeon.h"

/*Base weapons*/
const Weapon Weapon::Arco_Lungo("Arco Lungo", Perforante, 1, 1, 8, false);
const Weapon Weapon::Spada_Lunga("Spada Lunga", Tagliente, 1, 1, 8, true);
const Weapon Weapon::Ascia_Bipenne("Ascia Bipenne", Tagliente, 0, 1, 12, true, 2);
const Weapon Weapon::Flauto("Possente Flauto", Perforante, 3, 1, 6, false, -1);
const Weapon Weapon::Bastoncino("Spada del Destino AKA spada di legno", Contundente, 0, 2, 2, true, -1);
/*New weapons*/
const Weapon Weapon::Lancia("Lancia", Perforante, 1, 1, 8, true);
const Weapon Weapon::Mazzafrusto("Mazzafrusto", Contundente, 0, 1, 10, true, 1);
const Weapon Weapon::Pergamena_Fulmine("Pergamena di Fulmine", Elettrico, 3, 2, 6, false, 3);
const Weapon Weapon::Alabarda("Alabarda", Tagliente, 0, 1, 10, true, 1);
const Weapon Weapon::Arco_Corto("Arco Corto", Perforante, 1, 1, 6, false);
const Weapon Weapon::Pergamena_Raggio_Gelo("Pergamena di Raggio di Gelo", Gelo, 0, 1, 6, false, 2);

int Weapon::damage()
{
    int tmp = 0;
    for(int i = 0; i < num_dice; ++i)
        tmp += randRange(1, max_dice);
    return tmp;
}