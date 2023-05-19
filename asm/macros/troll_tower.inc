    @ Initializes the floor of the troll tower.
    .macro tower_initfloor
    callnative InitTrollTowerFloor
    .endm

    @ Adds 1 to the number of floors cleared.
    .macro tower_clearedfloor
    callnative TrollTowerAddFloorCleared
    .endm
