#include "dungeon.h"

Weapon Treasure::randWeapon() {
    return weapons[randRange(0, weapons.size()-1)];
}

Treasure::Treasure()
{
    /*Lootable weapons*/
    vector<Weapon> data = {
    Weapon::Arco_Corto, Weapon::Lancia, Weapon::Mazzafrusto, Weapon::Pergamena_Fulmine,
    Weapon::Alabarda, Weapon::Arco_Lungo, Weapon::Spada_Lunga, Weapon::Ascia_Bipenne,
    Weapon::Pergamena_Raggio_Gelo, Weapon::Pergamena_Gelo_Profondo, Weapon::Spadone,
    Weapon::Mazza_Leggera, Weapon::Lancia_Corta, Weapon::Martello_Guerra
    };

    for(Weapon w: data)
        for(int i = 0; i < 10 - w.rarity; ++i)
            weapons.push_back(w);
    
}