#include "dungeon.h"

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