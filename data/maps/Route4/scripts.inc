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
	goto_if_eq VAR_0x808C, 1, Route4_EventScript_LTGYes
# 8 "data/maps/Route4/scripts.pory"
	goto_if_eq VAR_0x808C, 0, Route4_EventScript_LTGNO
# 9 "data/maps/Route4/scripts.pory"
	release
# 10 "data/maps/Route4/scripts.pory"
	end
# 11 "data/maps/Route4/scripts.pory"

# 12 "data/maps/Route4/scripts.pory"
Route4_EventScript_LTGYes::
# 13 "data/maps/Route4/scripts.pory"
	setobjectxyperm OBJ_EVENT_GFX_BROCK, 26, 6
# 14 "data/maps/Route4/scripts.pory"
	setobjectmovementtype OBJ_EVENT_GFX_BROCK, MOVEMENT_TYPE_FACE_LEFT
# 15 "data/maps/Route4/scripts.pory"
	applymovement OBJ_EVENT_GFX_BROCK, Route4_Movement_LTGThrowOff
# 16 "data/maps/Route4/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route4_Movement_PlayerFall
# 17 "data/maps/Route4/scripts.pory"
	setvar VAR_0x808C, 2
# 18 "data/maps/Route4/scripts.pory"
	releaseall
# 19 "data/maps/Route4/scripts.pory"
	end
# 20 "data/maps/Route4/scripts.pory"

# 21 "data/maps/Route4/scripts.pory"
Route4_EventScript_LTGNO::
# 22 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_LTGNope, MSGBOX_DEFAULT
# 23 "data/maps/Route4/scripts.pory"
	waitmessage
# 24 "data/maps/Route4/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route4_Movement_BackOff
# 25 "data/maps/Route4/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 26 "data/maps/Route4/scripts.pory"
	releaseall
# 27 "data/maps/Route4/scripts.pory"
	end
# 28 "data/maps/Route4/scripts.pory"

# 29 "data/maps/Route4/scripts.pory"
Route4_Movement_BackOff::
# 30 "data/maps/Route4/scripts.pory"
	walk_left
# 31 "data/maps/Route4/scripts.pory"
	step_end
# 32 "data/maps/Route4/scripts.pory"

# 33 "data/maps/Route4/scripts.pory"
Route4_Movement_LTGThrowOff::
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
	walk_right
# 45 "data/maps/Route4/scripts.pory"
	walk_right
# 46 "data/maps/Route4/scripts.pory"
	walk_right
# 47 "data/maps/Route4/scripts.pory"
	walk_right
# 48 "data/maps/Route4/scripts.pory"
	walk_right
# 49 "data/maps/Route4/scripts.pory"
	walk_up
# 50 "data/maps/Route4/scripts.pory"
	jump_up
# 51 "data/maps/Route4/scripts.pory"
	step_end
# 52 "data/maps/Route4/scripts.pory"

# 53 "data/maps/Route4/scripts.pory"
Route4_Movement_PlayerFall::
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
	walk_right
# 65 "data/maps/Route4/scripts.pory"
	walk_right
# 66 "data/maps/Route4/scripts.pory"
	walk_right
# 67 "data/maps/Route4/scripts.pory"
	walk_right
# 68 "data/maps/Route4/scripts.pory"
	walk_right
# 69 "data/maps/Route4/scripts.pory"
	walk_up
# 70 "data/maps/Route4/scripts.pory"
	jump_2_right
# 71 "data/maps/Route4/scripts.pory"
	step_end
# 72 "data/maps/Route4/scripts.pory"

# 73 "data/maps/Route4/scripts.pory"
Route4_EventScript_Unused::
# 74 "data/maps/Route4/scripts.pory"
	end
# 75 "data/maps/Route4/scripts.pory"

# 76 "data/maps/Route4/scripts.pory"
Route4_EventScript_Woman::
# 77 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
# 78 "data/maps/Route4/scripts.pory"
	end
# 79 "data/maps/Route4/scripts.pory"

# 80 "data/maps/Route4/scripts.pory"
Route4_EventScript_MtMoonSign::
# 81 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
# 82 "data/maps/Route4/scripts.pory"
	end
# 83 "data/maps/Route4/scripts.pory"

# 84 "data/maps/Route4/scripts.pory"
Route4_EventScript_RouteSign::
# 85 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
# 86 "data/maps/Route4/scripts.pory"
	end
