#include "headers/dungeon.h"

Weapon Treasure::randWeapon() {
    return weapons[randRange(0, weapons.size()-1)];
}

Treasure::Treasure()
{
    /*Lootable weapons*/
    vector<Weapon> data = {
    /*Weapon::Arco_Corto, Weapon::Lancia, Weapon::Mazzafrusto_Leggero, Weapon::Bacchetta_Fulmine,
    Weapon::Alabarda, Weapon::Arco_Lungo, Weapon::Spada_Lunga, Weapon::Ascia_Bipenne,
    Weapon::Bacchetta_Raggio_Gelo, Weapon::Bacchetta_Gelo_Profondo, Weapon::Spadone,
    Weapon::Mazza_Leggera, Weapon::Lancia_Corta, Weapon::Martello_Guerra, Weapon::Bacchetta_Raggio_Fuoco,
    Weapon::Bacchetta_Freccia_Melf, Weapon::Balestra_Leggera, Weapon::Balestra_Pesante, Weapon::Gran_Martello,
    Weapon::Pugnale, Weapon::Scimitarra, Weapon::Mazzafrusto_Pesante, Weapon::Morning_Star*/
    };

    for(Weapon w: data)
        for(int i = 0; i < 10 - w.rarity; ++i)
            weapons.push_back(w);
    
}