#include "dungeon.h"

const vector<Weapon> Treasure::weapons({
    Weapon::Arco_Corto, Weapon::Lancia, Weapon::Mazzafrusto, Weapon::Pergamena_Fulmine,
    Weapon::Alabarda, Weapon::Arco_Lungo, Weapon::Spada_Lunga, Weapon::Ascia_Bipenne,
    Weapon::Pergamena_Raggio_Gelo
});

Weapon Treasure::randWeapon() {
    return Treasure::weapons[randRange(0, Treasure::weapons.size()-1)];
}

//TODO rarità