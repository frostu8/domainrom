#ifndef GUARD_TROLL_TOWER_H
#define GUARD_TROLL_TOWER_H

struct TrollTowerOpponent
{
    u8 name[11];
    u8 objGfx;
    u8 facilityClass;
};

void InitTrollTowerFloors(void);
void TrollTowerAddFloorCleared(void);

#endif
