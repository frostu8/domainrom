# 1 "data/maps/PalletTown/scripts.pory"

# 2 "data/maps/PalletTown/scripts.pory"
.equ LOCALID_SIGN_LADY, 1
# 3 "data/maps/PalletTown/scripts.pory"
.equ LOCALID_PROF_OAK,  3
# 4 "data/maps/PalletTown/scripts.pory"

# 5 "data/maps/PalletTown/scripts.pory"
.equ SIGN_LADY_READY, VAR_TEMP_2
# 6 "data/maps/PalletTown/scripts.pory"

# 7 "data/maps/PalletTown/scripts.pory"
PalletTown_MapScripts::
# 8 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
# 9 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
# 10 "data/maps/PalletTown/scripts.pory"
	.byte 0
# 11 "data/maps/PalletTown/scripts.pory"

# 12 "data/maps/PalletTown/scripts.pory"
PalletTown_OnTransition::
# 13 "data/maps/PalletTown/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
# 14 "data/maps/PalletTown/scripts.pory"
	call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_TryReadySignLady
# 15 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0, PalletTown_EventScript_SetSignLadyPos
# 16 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SetSignLadyDone
# 17 "data/maps/PalletTown/scripts.pory"
	end
# 18 "data/maps/PalletTown/scripts.pory"

# 19 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TryReadySignLady::
# 20 "data/maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_OPENED_START_MENU, EventScript_Return
# 21 "data/maps/PalletTown/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, EventScript_Return
# 22 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 23 "data/maps/PalletTown/scripts.pory"
	return
# 24 "data/maps/PalletTown/scripts.pory"

# 25 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SetSignLadyDone::
# 26 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
# 27 "data/maps/PalletTown/scripts.pory"
	return
# 28 "data/maps/PalletTown/scripts.pory"

# 29 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SetSignLadyPos::
# 30 "data/maps/PalletTown/scripts.pory"
	goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_MoveSignLadyToRouteEntrance
# 31 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_SIGN_LADY, 5, 15
# 32 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
# 33 "data/maps/PalletTown/scripts.pory"
	return
# 34 "data/maps/PalletTown/scripts.pory"

# 35 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_MoveSignLadyToRouteEntrance::
# 36 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_SIGN_LADY, 12, 2
# 37 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
# 38 "data/maps/PalletTown/scripts.pory"
	setvar SIGN_LADY_READY, TRUE
# 39 "data/maps/PalletTown/scripts.pory"
	return
# 40 "data/maps/PalletTown/scripts.pory"

# 41 "data/maps/PalletTown/scripts.pory"
PalletTown_OnFrame::
# 42 "data/maps/PalletTown/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
# 43 "data/maps/PalletTown/scripts.pory"
	.2byte 0
# 44 "data/maps/PalletTown/scripts.pory"

# 45 "data/maps/PalletTown/scripts.pory"
@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
# 46 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakRatingScene::
# 47 "data/maps/PalletTown/scripts.pory"
	lockall
# 48 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 49 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 14, 14
# 50 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
# 51 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 52 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
# 53 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 54 "data/maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
# 55 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakLetMeSeePokedex
# 56 "data/maps/PalletTown/scripts.pory"
	setvar VAR_0x8004, 0
# 57 "data/maps/PalletTown/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 58 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 59 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 60 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 61 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 62 "data/maps/PalletTown/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
# 63 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
# 64 "data/maps/PalletTown/scripts.pory"
	closemessage
# 65 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 66 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
# 67 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
# 68 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 69 "data/maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 70 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 71 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 72 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 73 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 74 "data/maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 75 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 76 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
# 77 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 78 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 79 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 80 "data/maps/PalletTown/scripts.pory"
	waitstate
# 81 "data/maps/PalletTown/scripts.pory"
	releaseall
# 82 "data/maps/PalletTown/scripts.pory"
	end
# 83 "data/maps/PalletTown/scripts.pory"

# 84 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_EndOakRatingScene::
# 85 "data/maps/PalletTown/scripts.pory"
	closemessage
# 86 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakExit
# 87 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 88 "data/maps/PalletTown/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 89 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 90 "data/maps/PalletTown/scripts.pory"
	releaseall
# 91 "data/maps/PalletTown/scripts.pory"
	end
# 92 "data/maps/PalletTown/scripts.pory"

# 93 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotEnoughMonsForNationalDex::
# 94 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
# 95 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 96 "data/maps/PalletTown/scripts.pory"
	end
# 97 "data/maps/PalletTown/scripts.pory"

# 98 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotBeenToOneIslandYet::
# 99 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
# 100 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 101 "data/maps/PalletTown/scripts.pory"
	end
# 102 "data/maps/PalletTown/scripts.pory"

# 103 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToPlayersDoor::
# 104 "data/maps/PalletTown/scripts.pory"
	walk_left
# 105 "data/maps/PalletTown/scripts.pory"
	walk_left
# 106 "data/maps/PalletTown/scripts.pory"
	walk_left
# 107 "data/maps/PalletTown/scripts.pory"
	walk_up
# 108 "data/maps/PalletTown/scripts.pory"
	walk_up
# 109 "data/maps/PalletTown/scripts.pory"
	walk_up
# 110 "data/maps/PalletTown/scripts.pory"
	walk_up
# 111 "data/maps/PalletTown/scripts.pory"
	walk_up
# 112 "data/maps/PalletTown/scripts.pory"
	walk_left
# 113 "data/maps/PalletTown/scripts.pory"
	walk_left
# 114 "data/maps/PalletTown/scripts.pory"
	walk_left
# 115 "data/maps/PalletTown/scripts.pory"
	walk_left
# 116 "data/maps/PalletTown/scripts.pory"
	walk_left
# 117 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 118 "data/maps/PalletTown/scripts.pory"
	step_end
# 119 "data/maps/PalletTown/scripts.pory"

# 120 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakExit::
# 121 "data/maps/PalletTown/scripts.pory"
	walk_right
# 122 "data/maps/PalletTown/scripts.pory"
	walk_right
# 123 "data/maps/PalletTown/scripts.pory"
	walk_right
# 124 "data/maps/PalletTown/scripts.pory"
	walk_right
# 125 "data/maps/PalletTown/scripts.pory"
	walk_right
# 126 "data/maps/PalletTown/scripts.pory"
	walk_down
# 127 "data/maps/PalletTown/scripts.pory"
	walk_down
# 128 "data/maps/PalletTown/scripts.pory"
	walk_down
# 129 "data/maps/PalletTown/scripts.pory"
	walk_down
# 130 "data/maps/PalletTown/scripts.pory"
	walk_down
# 131 "data/maps/PalletTown/scripts.pory"
	walk_right
# 132 "data/maps/PalletTown/scripts.pory"
	walk_right
# 133 "data/maps/PalletTown/scripts.pory"
	walk_right
# 134 "data/maps/PalletTown/scripts.pory"
	step_end
# 135 "data/maps/PalletTown/scripts.pory"

# 136 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabFromHouse::
# 137 "data/maps/PalletTown/scripts.pory"
	walk_right
# 138 "data/maps/PalletTown/scripts.pory"
	walk_right
# 139 "data/maps/PalletTown/scripts.pory"
	walk_right
# 140 "data/maps/PalletTown/scripts.pory"
	walk_right
# 141 "data/maps/PalletTown/scripts.pory"
	walk_right
# 142 "data/maps/PalletTown/scripts.pory"
	walk_down
# 143 "data/maps/PalletTown/scripts.pory"
	walk_down
# 144 "data/maps/PalletTown/scripts.pory"
	walk_down
# 145 "data/maps/PalletTown/scripts.pory"
	walk_down
# 146 "data/maps/PalletTown/scripts.pory"
	walk_down
# 147 "data/maps/PalletTown/scripts.pory"
	walk_right
# 148 "data/maps/PalletTown/scripts.pory"
	walk_right
# 149 "data/maps/PalletTown/scripts.pory"
	walk_right
# 150 "data/maps/PalletTown/scripts.pory"
	walk_right
# 151 "data/maps/PalletTown/scripts.pory"
	walk_right
# 152 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 153 "data/maps/PalletTown/scripts.pory"
	step_end
# 154 "data/maps/PalletTown/scripts.pory"

# 155 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabFromHouse::
# 156 "data/maps/PalletTown/scripts.pory"
	walk_down
# 157 "data/maps/PalletTown/scripts.pory"
	walk_right
# 158 "data/maps/PalletTown/scripts.pory"
	walk_right
# 159 "data/maps/PalletTown/scripts.pory"
	walk_right
# 160 "data/maps/PalletTown/scripts.pory"
	walk_right
# 161 "data/maps/PalletTown/scripts.pory"
	walk_right
# 162 "data/maps/PalletTown/scripts.pory"
	walk_down
# 163 "data/maps/PalletTown/scripts.pory"
	walk_down
# 164 "data/maps/PalletTown/scripts.pory"
	walk_down
# 165 "data/maps/PalletTown/scripts.pory"
	walk_down
# 166 "data/maps/PalletTown/scripts.pory"
	walk_down
# 167 "data/maps/PalletTown/scripts.pory"
	walk_right
# 168 "data/maps/PalletTown/scripts.pory"
	walk_right
# 169 "data/maps/PalletTown/scripts.pory"
	walk_right
# 170 "data/maps/PalletTown/scripts.pory"
	walk_right
# 171 "data/maps/PalletTown/scripts.pory"
	step_end
# 172 "data/maps/PalletTown/scripts.pory"

# 173 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerLeft::
# 174 "data/maps/PalletTown/scripts.pory"
	lockall
# 175 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 0
# 176 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 177 "data/maps/PalletTown/scripts.pory"
	end
# 178 "data/maps/PalletTown/scripts.pory"

# 179 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerRight::
# 180 "data/maps/PalletTown/scripts.pory"
	lockall
# 181 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 1
# 182 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 183 "data/maps/PalletTown/scripts.pory"
	end
# 184 "data/maps/PalletTown/scripts.pory"

# 185 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTrigger::
# 186 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 187 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 188 "data/maps/PalletTown/scripts.pory"
	delay 30
# 189 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_OAK, 0
# 190 "data/maps/PalletTown/scripts.pory"
	message PalletTown_Text_OakDontGoOut
# 191 "data/maps/PalletTown/scripts.pory"
	waitmessage
# 192 "data/maps/PalletTown/scripts.pory"
	delay 85
# 193 "data/maps/PalletTown/scripts.pory"
	closemessage
# 194 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 195 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 196 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 197 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 198 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 199 "data/maps/PalletTown/scripts.pory"
	delay 30
# 200 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 201 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 14, 8
# 202 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
# 203 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
# 204 "data/maps/PalletTown/scripts.pory"
	delay 30
# 205 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
# 206 "data/maps/PalletTown/scripts.pory"
	closemessage
# 207 "data/maps/PalletTown/scripts.pory"
	delay 30
# 208 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
# 209 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
# 210 "data/maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 211 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 212 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 213 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 214 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 215 "data/maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 216 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 217 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 218 "data/maps/PalletTown/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 219 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 220 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 221 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 222 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 223 "data/maps/PalletTown/scripts.pory"
	waitstate
# 224 "data/maps/PalletTown/scripts.pory"
	releaseall
# 225 "data/maps/PalletTown/scripts.pory"
	end
# 226 "data/maps/PalletTown/scripts.pory"

# 227 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FrostTrigger::
# 228 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 229 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 230 "data/maps/PalletTown/scripts.pory"
	delay 30
# 231 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_OAK, 0
# 232 "data/maps/PalletTown/scripts.pory"
	message PalletTown_Text_FrostDontGoOut
# 233 "data/maps/PalletTown/scripts.pory"
	waitmessage
# 234 "data/maps/PalletTown/scripts.pory"
	delay 85
# 235 "data/maps/PalletTown/scripts.pory"
	closemessage
# 236 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 237 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 238 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 239 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 240 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 241 "data/maps/PalletTown/scripts.pory"
	delay 30
# 242 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 243 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_FrostEnterUp
# 244 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_FrostEnterDown
# 245 "data/maps/PalletTown/scripts.pory"
	delay 30
# 246 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_FrostGrass
# 247 "data/maps/PalletTown/scripts.pory"
	closemessage
# 248 "data/maps/PalletTown/scripts.pory"
	delay 30
# 249 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
# 250 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
# 251 "data/maps/PalletTown/scripts.pory"
	opendoor 6, 8
# 252 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 253 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 254 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 255 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 256 "data/maps/PalletTown/scripts.pory"
	closedoor 6, 8
# 257 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 258 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 259 "data/maps/PalletTown/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 260 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 261 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 262 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 263 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 264 "data/maps/PalletTown/scripts.pory"
	waitstate
# 265 "data/maps/PalletTown/scripts.pory"
	releaseall
# 266 "data/maps/PalletTown/scripts.pory"
	end
# 267 "data/maps/PalletTown/scripts.pory"

# 268 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FrostTriggerUp::
# 269 "data/maps/PalletTown/scripts.pory"
	lockall
# 270 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 0
# 271 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_FrostTrigger
# 272 "data/maps/PalletTown/scripts.pory"
	end
# 273 "data/maps/PalletTown/scripts.pory"

# 274 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FrostTriggerDown::
# 275 "data/maps/PalletTown/scripts.pory"
	lockall
# 276 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 1
# 277 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_FrostTrigger
# 278 "data/maps/PalletTown/scripts.pory"
	end
# 279 "data/maps/PalletTown/scripts.pory"

# 280 "data/maps/PalletTown/scripts.pory"

# 281 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterLeft::
# 282 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLeft
# 283 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 284 "data/maps/PalletTown/scripts.pory"
	return
# 285 "data/maps/PalletTown/scripts.pory"

# 286 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterRight::
# 287 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterRight
# 288 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 289 "data/maps/PalletTown/scripts.pory"
	return
# 290 "data/maps/PalletTown/scripts.pory"

# 291 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FrostEnterUp::
# 292 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLeft
# 293 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 294 "data/maps/PalletTown/scripts.pory"
	return
# 295 "data/maps/PalletTown/scripts.pory"

# 296 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FrostEnterDown::
# 297 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterRight
# 298 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 299 "data/maps/PalletTown/scripts.pory"
	return
# 300 "data/maps/PalletTown/scripts.pory"

# 301 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabLeft::
# 302 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
# 303 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
# 304 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 305 "data/maps/PalletTown/scripts.pory"
	return
# 306 "data/maps/PalletTown/scripts.pory"

# 307 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabRight::
# 308 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
# 309 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
# 310 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 311 "data/maps/PalletTown/scripts.pory"
	return
# 312 "data/maps/PalletTown/scripts.pory"

# 313 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLeft::
# 314 "data/maps/PalletTown/scripts.pory"
	set_visible
# 315 "data/maps/PalletTown/scripts.pory"
	walk_right
# 316 "data/maps/PalletTown/scripts.pory"
	walk_right
# 317 "data/maps/PalletTown/scripts.pory"
	walk_right
# 318 "data/maps/PalletTown/scripts.pory"
	walk_right
# 319 "data/maps/PalletTown/scripts.pory"
	walk_right
# 320 "data/maps/PalletTown/scripts.pory"
	walk_right
# 321 "data/maps/PalletTown/scripts.pory"
	walk_right
# 322 "data/maps/PalletTown/scripts.pory"
	walk_right
# 323 "data/maps/PalletTown/scripts.pory"
	step_end
# 324 "data/maps/PalletTown/scripts.pory"

# 325 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterRight::
# 326 "data/maps/PalletTown/scripts.pory"
	set_visible
# 327 "data/maps/PalletTown/scripts.pory"
	walk_down
# 328 "data/maps/PalletTown/scripts.pory"
	walk_right
# 329 "data/maps/PalletTown/scripts.pory"
	walk_right
# 330 "data/maps/PalletTown/scripts.pory"
	walk_right
# 331 "data/maps/PalletTown/scripts.pory"
	walk_right
# 332 "data/maps/PalletTown/scripts.pory"
	walk_right
# 333 "data/maps/PalletTown/scripts.pory"
	walk_right
# 334 "data/maps/PalletTown/scripts.pory"
	walk_right
# 335 "data/maps/PalletTown/scripts.pory"
	walk_right
# 336 "data/maps/PalletTown/scripts.pory"
	step_end
# 337 "data/maps/PalletTown/scripts.pory"

# 338 "data/maps/PalletTown/scripts.pory"
	.macro walk_to_lab
# 339 "data/maps/PalletTown/scripts.pory"
	walk_left
# 340 "data/maps/PalletTown/scripts.pory"
	walk_down
# 341 "data/maps/PalletTown/scripts.pory"
	walk_down
# 342 "data/maps/PalletTown/scripts.pory"
	walk_down
# 343 "data/maps/PalletTown/scripts.pory"
	walk_down
# 344 "data/maps/PalletTown/scripts.pory"
	walk_down
# 345 "data/maps/PalletTown/scripts.pory"
	walk_down
# 346 "data/maps/PalletTown/scripts.pory"
	walk_down
# 347 "data/maps/PalletTown/scripts.pory"
	walk_down
# 348 "data/maps/PalletTown/scripts.pory"
	walk_down
# 349 "data/maps/PalletTown/scripts.pory"
	walk_down
# 350 "data/maps/PalletTown/scripts.pory"
	walk_down
# 351 "data/maps/PalletTown/scripts.pory"
	walk_right
# 352 "data/maps/PalletTown/scripts.pory"
	walk_right
# 353 "data/maps/PalletTown/scripts.pory"
	walk_right
# 354 "data/maps/PalletTown/scripts.pory"
	walk_right
# 355 "data/maps/PalletTown/scripts.pory"
	.endm
# 356 "data/maps/PalletTown/scripts.pory"

# 357 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabLeft::
# 358 "data/maps/PalletTown/scripts.pory"
	set_visible
# 359 "data/maps/PalletTown/scripts.pory"
	walk_left
# 360 "data/maps/PalletTown/scripts.pory"
	walk_left
# 361 "data/maps/PalletTown/scripts.pory"
	walk_left
# 362 "data/maps/PalletTown/scripts.pory"
	walk_left
# 363 "data/maps/PalletTown/scripts.pory"
	walk_left
# 364 "data/maps/PalletTown/scripts.pory"
	walk_left
# 365 "data/maps/PalletTown/scripts.pory"
	walk_left
# 366 "data/maps/PalletTown/scripts.pory"
	walk_left
# 367 "data/maps/PalletTown/scripts.pory"
	walk_left
# 368 "data/maps/PalletTown/scripts.pory"
	walk_left
# 369 "data/maps/PalletTown/scripts.pory"
	walk_left
# 370 "data/maps/PalletTown/scripts.pory"
	walk_left
# 371 "data/maps/PalletTown/scripts.pory"
	walk_down
# 372 "data/maps/PalletTown/scripts.pory"
	walk_left
# 373 "data/maps/PalletTown/scripts.pory"
	walk_left
# 374 "data/maps/PalletTown/scripts.pory"
	walk_left
# 375 "data/maps/PalletTown/scripts.pory"
	walk_left
# 376 "data/maps/PalletTown/scripts.pory"
	step_end
# 377 "data/maps/PalletTown/scripts.pory"

# 378 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabRight::
# 379 "data/maps/PalletTown/scripts.pory"
	set_visible
# 380 "data/maps/PalletTown/scripts.pory"
	walk_left
# 381 "data/maps/PalletTown/scripts.pory"
	walk_left
# 382 "data/maps/PalletTown/scripts.pory"
	walk_left
# 383 "data/maps/PalletTown/scripts.pory"
	walk_left
# 384 "data/maps/PalletTown/scripts.pory"
	walk_left
# 385 "data/maps/PalletTown/scripts.pory"
	walk_left
# 386 "data/maps/PalletTown/scripts.pory"
	walk_left
# 387 "data/maps/PalletTown/scripts.pory"
	walk_left
# 388 "data/maps/PalletTown/scripts.pory"
	walk_left
# 389 "data/maps/PalletTown/scripts.pory"
	walk_left
# 390 "data/maps/PalletTown/scripts.pory"
	walk_left
# 391 "data/maps/PalletTown/scripts.pory"
	walk_left
# 392 "data/maps/PalletTown/scripts.pory"
	walk_left
# 393 "data/maps/PalletTown/scripts.pory"
	walk_left
# 394 "data/maps/PalletTown/scripts.pory"
	walk_left
# 395 "data/maps/PalletTown/scripts.pory"
	walk_left
# 396 "data/maps/PalletTown/scripts.pory"
	step_end
# 397 "data/maps/PalletTown/scripts.pory"

# 398 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLab::
# 399 "data/maps/PalletTown/scripts.pory"
	walk_up
# 400 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 401 "data/maps/PalletTown/scripts.pory"
	step_end
# 402 "data/maps/PalletTown/scripts.pory"

# 403 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabLeft::
# 404 "data/maps/PalletTown/scripts.pory"
	walk_left
# 405 "data/maps/PalletTown/scripts.pory"
	walk_left
# 406 "data/maps/PalletTown/scripts.pory"
	walk_left
# 407 "data/maps/PalletTown/scripts.pory"
	walk_left
# 408 "data/maps/PalletTown/scripts.pory"
	walk_left
# 409 "data/maps/PalletTown/scripts.pory"
	walk_left
# 410 "data/maps/PalletTown/scripts.pory"
	walk_left
# 411 "data/maps/PalletTown/scripts.pory"
	walk_left
# 412 "data/maps/PalletTown/scripts.pory"
	walk_left
# 413 "data/maps/PalletTown/scripts.pory"
	walk_left
# 414 "data/maps/PalletTown/scripts.pory"
	walk_left
# 415 "data/maps/PalletTown/scripts.pory"
	walk_left
# 416 "data/maps/PalletTown/scripts.pory"
	walk_left
# 417 "data/maps/PalletTown/scripts.pory"
	walk_down
# 418 "data/maps/PalletTown/scripts.pory"
	walk_left
# 419 "data/maps/PalletTown/scripts.pory"
	walk_left
# 420 "data/maps/PalletTown/scripts.pory"
	step_end
# 421 "data/maps/PalletTown/scripts.pory"

# 422 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabRight::
# 423 "data/maps/PalletTown/scripts.pory"
	walk_left
# 424 "data/maps/PalletTown/scripts.pory"
	walk_left
# 425 "data/maps/PalletTown/scripts.pory"
	walk_left
# 426 "data/maps/PalletTown/scripts.pory"
	walk_left
# 427 "data/maps/PalletTown/scripts.pory"
	walk_left
# 428 "data/maps/PalletTown/scripts.pory"
	walk_left
# 429 "data/maps/PalletTown/scripts.pory"
	walk_left
# 430 "data/maps/PalletTown/scripts.pory"
	walk_left
# 431 "data/maps/PalletTown/scripts.pory"
	walk_left
# 432 "data/maps/PalletTown/scripts.pory"
	walk_left
# 433 "data/maps/PalletTown/scripts.pory"
	walk_left
# 434 "data/maps/PalletTown/scripts.pory"
	walk_left
# 435 "data/maps/PalletTown/scripts.pory"
	walk_left
# 436 "data/maps/PalletTown/scripts.pory"
	walk_left
# 437 "data/maps/PalletTown/scripts.pory"
	walk_left
# 438 "data/maps/PalletTown/scripts.pory"
	step_end
# 439 "data/maps/PalletTown/scripts.pory"

# 440 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerEnterLab::
# 441 "data/maps/PalletTown/scripts.pory"
	walk_left
# 442 "data/maps/PalletTown/scripts.pory"
	walk_left
# 443 "data/maps/PalletTown/scripts.pory"
	walk_up
# 444 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 445 "data/maps/PalletTown/scripts.pory"
	step_end
# 446 "data/maps/PalletTown/scripts.pory"

# 447 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLady::
# 448 "data/maps/PalletTown/scripts.pory"
	lock
# 449 "data/maps/PalletTown/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2, PalletTown_EventScript_SignLadyDone
# 450 "data/maps/PalletTown/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SignLadyJustShowedSign
# 451 "data/maps/PalletTown/scripts.pory"
	goto_if_eq SIGN_LADY_READY, TRUE, PalletTown_EventScript_SignLadyStartShowSign
# 452 "data/maps/PalletTown/scripts.pory"
	goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
# 453 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_HmmIsThatRight
# 454 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 455 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 456 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 457 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_ExclamationMark
# 458 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 459 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_Delay48
# 460 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 461 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OhLookLook
# 462 "data/maps/PalletTown/scripts.pory"
	closemessage
# 463 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayRight
# 464 "data/maps/PalletTown/scripts.pory"
	call_if_ne VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayLeft
# 465 "data/maps/PalletTown/scripts.pory"
	copyobjectxytoperm LOCALID_SIGN_LADY
# 466 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_TEMP_2
# 467 "data/maps/PalletTown/scripts.pory"
	release
# 468 "data/maps/PalletTown/scripts.pory"
	end
# 469 "data/maps/PalletTown/scripts.pory"

# 470 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayRight::
# 471 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
# 472 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 473 "data/maps/PalletTown/scripts.pory"
	return
# 474 "data/maps/PalletTown/scripts.pory"

# 475 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayLeft::
# 476 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
# 477 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 478 "data/maps/PalletTown/scripts.pory"
	return
# 479 "data/maps/PalletTown/scripts.pory"

# 480 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyDone::
# 481 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 482 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 483 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RaisingMonsToo
# 484 "data/maps/PalletTown/scripts.pory"
	release
# 485 "data/maps/PalletTown/scripts.pory"
	end
# 486 "data/maps/PalletTown/scripts.pory"

# 487 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyGoReadSign::
# 488 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 489 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 490 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_ReadItReadIt
# 491 "data/maps/PalletTown/scripts.pory"
	release
# 492 "data/maps/PalletTown/scripts.pory"
	end
# 493 "data/maps/PalletTown/scripts.pory"

# 494 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyJustShowedSign::
# 495 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 496 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 497 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_SignsAreUsefulArentThey
# 498 "data/maps/PalletTown/scripts.pory"
	release
# 499 "data/maps/PalletTown/scripts.pory"
	end
# 500 "data/maps/PalletTown/scripts.pory"

# 501 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayRight::
# 502 "data/maps/PalletTown/scripts.pory"
	walk_right
# 503 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_left
# 504 "data/maps/PalletTown/scripts.pory"
	step_end
# 505 "data/maps/PalletTown/scripts.pory"

# 506 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayLeft::
# 507 "data/maps/PalletTown/scripts.pory"
	walk_left
# 508 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_right
# 509 "data/maps/PalletTown/scripts.pory"
	step_end
# 510 "data/maps/PalletTown/scripts.pory"

# 511 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FatMan::
# 512 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
# 513 "data/maps/PalletTown/scripts.pory"
	end
# 514 "data/maps/PalletTown/scripts.pory"

# 515 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OaksLabSign::
# 516 "data/maps/PalletTown/scripts.pory"
	lockall
# 517 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, 0
# 518 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakPokemonResearchLab
# 519 "data/maps/PalletTown/scripts.pory"
	releaseall
# 520 "data/maps/PalletTown/scripts.pory"
	end
# 521 "data/maps/PalletTown/scripts.pory"

# 522 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_PlayersHouseSign::
# 523 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
# 524 "data/maps/PalletTown/scripts.pory"
	end
# 525 "data/maps/PalletTown/scripts.pory"

# 526 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_RivalsHouseSign::
# 527 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
# 528 "data/maps/PalletTown/scripts.pory"
	end
# 529 "data/maps/PalletTown/scripts.pory"

# 530 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TownSign::
# 531 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
# 532 "data/maps/PalletTown/scripts.pory"
	end
# 533 "data/maps/PalletTown/scripts.pory"

# 534 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TrainerTips::
# 535 "data/maps/PalletTown/scripts.pory"
	lockall
# 536 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenu
# 537 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 538 "data/maps/PalletTown/scripts.pory"
	releaseall
# 539 "data/maps/PalletTown/scripts.pory"
	end
# 540 "data/maps/PalletTown/scripts.pory"

# 541 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyTrigger::
# 542 "data/maps/PalletTown/scripts.pory"
	lockall
# 543 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_WalkInPlaceFasterRight
# 544 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 545 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 546 "data/maps/PalletTown/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 547 "data/maps/PalletTown/scripts.pory"
	releaseall
# 548 "data/maps/PalletTown/scripts.pory"
	end
# 549 "data/maps/PalletTown/scripts.pory"

# 550 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyShowSign::
# 551 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 552 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_LookCopiedTrainerTipsSign
# 553 "data/maps/PalletTown/scripts.pory"
	closemessage
# 554 "data/maps/PalletTown/scripts.pory"
	delay 20
# 555 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 556 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_OPENED_START_MENU
# 557 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 558 "data/maps/PalletTown/scripts.pory"
	setvar SIGN_LADY_READY, FALSE
# 559 "data/maps/PalletTown/scripts.pory"
	special SetWalkingIntoSignVars
# 560 "data/maps/PalletTown/scripts.pory"
	special DisableMsgBoxWalkaway
# 561 "data/maps/PalletTown/scripts.pory"
	signmsg
# 562 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenuCopy
# 563 "data/maps/PalletTown/scripts.pory"
	normalmsg
# 564 "data/maps/PalletTown/scripts.pory"
	return
# 565 "data/maps/PalletTown/scripts.pory"

# 566 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_FrostEnterUp::
# 567 "data/maps/PalletTown/scripts.pory"
	walk_right
# 568 "data/maps/PalletTown/scripts.pory"
	walk_right
# 569 "data/maps/PalletTown/scripts.pory"
	walk_right
# 570 "data/maps/PalletTown/scripts.pory"
	walk_right
# 571 "data/maps/PalletTown/scripts.pory"
	walk_right
# 572 "data/maps/PalletTown/scripts.pory"
	walk_right
# 573 "data/maps/PalletTown/scripts.pory"
	walk_right
# 574 "data/maps/PalletTown/scripts.pory"
	walk_right
# 575 "data/maps/PalletTown/scripts.pory"
	step_end
# 576 "data/maps/PalletTown/scripts.pory"

# 577 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_FrostLeadPlayerToLabUp::
# 578 "data/maps/PalletTown/scripts.pory"
	walk_right
# 579 "data/maps/PalletTown/scripts.pory"
	walk_right
# 580 "data/maps/PalletTown/scripts.pory"
	walk_right
# 581 "data/maps/PalletTown/scripts.pory"
	walk_right
# 582 "data/maps/PalletTown/scripts.pory"
	walk_right
# 583 "data/maps/PalletTown/scripts.pory"
	walk_right
# 584 "data/maps/PalletTown/scripts.pory"
	walk_right
# 585 "data/maps/PalletTown/scripts.pory"
	walk_right
# 586 "data/maps/PalletTown/scripts.pory"
	step_end
# 587 "data/maps/PalletTown/scripts.pory"

# 588 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_FrostEnterDown::
# 589 "data/maps/PalletTown/scripts.pory"
	walk_down
# 590 "data/maps/PalletTown/scripts.pory"
	walk_right
# 591 "data/maps/PalletTown/scripts.pory"
	walk_right
# 592 "data/maps/PalletTown/scripts.pory"
	walk_right
# 593 "data/maps/PalletTown/scripts.pory"
	walk_right
# 594 "data/maps/PalletTown/scripts.pory"
	walk_right
# 595 "data/maps/PalletTown/scripts.pory"
	walk_right
# 596 "data/maps/PalletTown/scripts.pory"
	walk_right
# 597 "data/maps/PalletTown/scripts.pory"
	walk_right
# 598 "data/maps/PalletTown/scripts.pory"
	step_end
# 599 "data/maps/PalletTown/scripts.pory"

# 600 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyStartShowSign::
# 601 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 602 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 603 "data/maps/PalletTown/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 604 "data/maps/PalletTown/scripts.pory"
	release
# 605 "data/maps/PalletTown/scripts.pory"
	end

PalletTown_EventScript_PurgatorySign::
# 609 "data/maps/PalletTown/scripts.pory"
	lockall
# 610 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_EventScript_PurgatorySign_Text_0
# 611 "data/maps/PalletTown/scripts.pory"
	releaseall
	return


PalletTown_EventScript_PurgatorySign_Text_0:
# 610 "data/maps/PalletTown/scripts.pory"
	.string "Welcome to Purgatory$"
