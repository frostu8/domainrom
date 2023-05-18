#include "global.h"
#include "event_data.h"
#include "troll_tower.h"
#include "constants/event_objects.h"

#define TROLL_TOWER_FLOOR_NORMAL 0
#define TROLL_TOWER_FLOOR_SPECIAL 1

struct TrollTowerOpponent
{
    u8 name[11];
    u8 objGfx;
    u8 facilityClass;
};

static const struct TrollTowerOpponent sTrollTowerFloors[] = {
    {
        .name = _("BRUH"),
        .objGfx = OBJ_EVENT_GFX_SUPER_NERD,
        //.objGfx = OBJ_EVENT_GFX_WORKER_M,
        .facilityClass = FACILITY_CLASS_SUPER_NERD,
    }
};

void InitTrollTowerFloor(void)
{
    u8 floor = gSaveBlock1Ptr->trollTowerFloor;

    if (floor >= NELEMS(sTrollTowerFloors))
        floor = NELEMS(sTrollTowerFloors) - 1;

    VarSet(VAR_OBJ_GFX_ID_0, sTrollTowerFloors[floor].objGfx);
}
