# 1 "data/maps/Route4/scripts.pory"

# 2 "data/maps/Route4/scripts.pory"
Route4_MapScripts::
# 3 "data/maps/Route4/scripts.pory"
	.byte 0
# 4 "data/maps/Route4/scripts.pory"

# 5 "data/maps/Route4/scripts.pory"
Route4_EventScript_LTGThrow::
# 6 "data/maps/Route4/scripts.pory"
	lockall
# 7 "data/maps/Route4/scripts.pory"
	goto_if_eq VAR_0x808C, 0, Route4_EventScript_LTGNO
# 8 "data/maps/Route4/scripts.pory"
	setobjectxyperm OBJ_EVENT_GFX_BROCK, 26, 6
# 9 "data/maps/Route4/scripts.pory"
	setobjectmovementtype OBJ_EVENT_GFX_BROCK, MOVEMENT_TYPE_FACE_LEFT
# 10 "data/maps/Route4/scripts.pory"
	applymovement OBJ_EVENT_GFX_BROCK, Route4_Movement_LTGThrowOff
# 11 "data/maps/Route4/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route4_Movement_PlayerFall
# 12 "data/maps/Route4/scripts.pory"
	setvar VAR_0x808C, 0
# 13 "data/maps/Route4/scripts.pory"
	releaseall
# 14 "data/maps/Route4/scripts.pory"
	end
# 15 "data/maps/Route4/scripts.pory"

# 16 "data/maps/Route4/scripts.pory"
Route4_EventScript_LTGNO::
# 17 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_LTGNope, MSGBOX_DEFAULT
# 18 "data/maps/Route4/scripts.pory"
	waitmessage
# 19 "data/maps/Route4/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route4_Movement_BackOff
# 20 "data/maps/Route4/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 21 "data/maps/Route4/scripts.pory"
	releaseall
# 22 "data/maps/Route4/scripts.pory"
	end
# 23 "data/maps/Route4/scripts.pory"

# 24 "data/maps/Route4/scripts.pory"
Route4_Movement_BackOff::
# 25 "data/maps/Route4/scripts.pory"
	walk_left
# 26 "data/maps/Route4/scripts.pory"
	step_end
# 27 "data/maps/Route4/scripts.pory"

# 28 "data/maps/Route4/scripts.pory"
Route4_Movement_LTGThrowOff::
# 29 "data/maps/Route4/scripts.pory"
	walk_right
# 30 "data/maps/Route4/scripts.pory"
	walk_right
# 31 "data/maps/Route4/scripts.pory"
	walk_right
# 32 "data/maps/Route4/scripts.pory"
	walk_right
# 33 "data/maps/Route4/scripts.pory"
	walk_right
# 34 "data/maps/Route4/scripts.pory"
	walk_right
# 35 "data/maps/Route4/scripts.pory"
	walk_right
# 36 "data/maps/Route4/scripts.pory"
	walk_right
# 37 "data/maps/Route4/scripts.pory"
	walk_right
# 38 "data/maps/Route4/scripts.pory"
	walk_right
# 39 "data/maps/Route4/scripts.pory"
	walk_right
# 40 "data/maps/Route4/scripts.pory"
	walk_right
# 41 "data/maps/Route4/scripts.pory"
	walk_right
# 42 "data/maps/Route4/scripts.pory"
	walk_right
# 43 "data/maps/Route4/scripts.pory"
	walk_right
# 44 "data/maps/Route4/scripts.pory"
	walk_up
# 45 "data/maps/Route4/scripts.pory"
	jump_up
# 46 "data/maps/Route4/scripts.pory"
	step_end
# 47 "data/maps/Route4/scripts.pory"

# 48 "data/maps/Route4/scripts.pory"
Route4_Movement_PlayerFall::
# 49 "data/maps/Route4/scripts.pory"
	walk_right
# 50 "data/maps/Route4/scripts.pory"
	walk_right
# 51 "data/maps/Route4/scripts.pory"
	walk_right
# 52 "data/maps/Route4/scripts.pory"
	walk_right
# 53 "data/maps/Route4/scripts.pory"
	walk_right
# 54 "data/maps/Route4/scripts.pory"
	walk_right
# 55 "data/maps/Route4/scripts.pory"
	walk_right
# 56 "data/maps/Route4/scripts.pory"
	walk_right
# 57 "data/maps/Route4/scripts.pory"
	walk_right
# 58 "data/maps/Route4/scripts.pory"
	walk_right
# 59 "data/maps/Route4/scripts.pory"
	walk_right
# 60 "data/maps/Route4/scripts.pory"
	walk_right
# 61 "data/maps/Route4/scripts.pory"
	walk_right
# 62 "data/maps/Route4/scripts.pory"
	walk_right
# 63 "data/maps/Route4/scripts.pory"
	walk_right
# 64 "data/maps/Route4/scripts.pory"
	walk_up
# 65 "data/maps/Route4/scripts.pory"
	jump_2_right
# 66 "data/maps/Route4/scripts.pory"
	step_end
# 67 "data/maps/Route4/scripts.pory"

# 68 "data/maps/Route4/scripts.pory"
Route4_EventScript_Unused::
# 69 "data/maps/Route4/scripts.pory"
	end
# 70 "data/maps/Route4/scripts.pory"

# 71 "data/maps/Route4/scripts.pory"
Route4_EventScript_Woman::
# 72 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
# 73 "data/maps/Route4/scripts.pory"
	end
# 74 "data/maps/Route4/scripts.pory"

# 75 "data/maps/Route4/scripts.pory"
Route4_EventScript_MtMoonSign::
# 76 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
# 77 "data/maps/Route4/scripts.pory"
	end
# 78 "data/maps/Route4/scripts.pory"

# 79 "data/maps/Route4/scripts.pory"
Route4_EventScript_RouteSign::
# 80 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
# 81 "data/maps/Route4/scripts.pory"
	end
