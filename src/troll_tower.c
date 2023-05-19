#include "global.h"
#include "event_data.h"
#include "troll_tower.h"
#include "constants/event_objects.h"

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

void TrollTowerAddFloorCleared(void)
{
    gSaveBlock1Ptr->trollTowerFloor++;
}
