#include "headers/dungeon.h"

Weapon Treasure::randWeapon() {
    return weapons[randRange(0, weapons.size()-1)];
}

Treasure::Treasure()
{
    /*Lootable weapons*/
    vector<Weapon> data = {
    db.getWeapon("Arco_Corto"), db.getWeapon("Lancia"), db.getWeapon("Mazzafrusto_Leggero"), db.getWeapon("Bacchetta_Fulmine"),
    db.getWeapon("Alabarda"), db.getWeapon("Arco_Lungo"), db.getWeapon("Spada_Lunga"), db.getWeapon("Ascia_Bipenne"),
    db.getWeapon("Bacchetta_Raggio_Gelo"), db.getWeapon("Bacchetta_Gelo_Profondo"), db.getWeapon("Spadone"),
    db.getWeapon("Mazza_Leggera"), db.getWeapon("Lancia_Corta"), db.getWeapon("Martello_Guerra"), db.getWeapon("Bacchetta_Raggio_Fuoco"),
    db.getWeapon("Bacchetta_Freccia_Melf"), db.getWeapon("Balestra_Leggera"), db.getWeapon("Balestra_Pesante"), db.getWeapon("Gran_Martello"),
    db.getWeapon("Pugnale"), db.getWeapon("Scimitarra"), db.getWeapon("Mazzafrusto_Pesante"), db.getWeapon("Morning_Star")};

    for(Weapon w: data)
        for(int i = 0; i < 10 - w.rarity; ++i)
            weapons.push_back(w);
    
}