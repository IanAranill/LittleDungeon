#include "headers/dungeon.h"

int Weapon::damage()
{
    int tmp = 0;
    for(int i = 0; i < num_dice; ++i)
        tmp += randRange(1, max_dice);
    return tmp;
}

void Weapon::printStats(const int livello)
{
    cout << description << " -> " << "tipo: " << dmg_type_to_string(type) << ", danno: " 
        << num_dice << "d" << max_dice << ", colpire: +" << bonus + livello << endl;
    return;
}

