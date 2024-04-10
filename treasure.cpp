#include "dungeon.h"

vector<Weapon> Treasure::weapons({
    Weapon::Arco_Corto, Weapon::Lancia, Weapon::Mazzafrusto, Weapon::Pergamena_Fulmine,
    Weapon::Alabarda, Weapon::Arco_Lungo, Weapon::Spada_Lunga, Weapon::Ascia_Bipenne,
    Weapon::Pergamena_Raggio_Gelo
});

Weapon Treasure::randWeapon() {
    return weapons[randRange(0, weapons.size()-1)];
}

Treasure::Treasure()
{
    vector<Weapon> data = weapons;
    for(Weapon w: data)
        for(int i = 1; i < 10 - w.rarity; ++i)
            weapons.push_back(w);
}