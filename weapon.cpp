#include "dungeon.h"

int Weapon::damage()
{
    int tmp = 0;
    for(int i = 0; i < num_dice; ++i)
        tmp += randRange(1, max_dice);
    return tmp;
}
