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
	closemessage
# 24 "data/maps/Route4/scripts.pory"
	waitmessage
# 25 "data/maps/Route4/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route4_Movement_BackOff
# 26 "data/maps/Route4/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 27 "data/maps/Route4/scripts.pory"
	releaseall
# 28 "data/maps/Route4/scripts.pory"
	end
# 29 "data/maps/Route4/scripts.pory"

# 30 "data/maps/Route4/scripts.pory"
Route4_Movement_BackOff::
# 31 "data/maps/Route4/scripts.pory"
	walk_left
# 32 "data/maps/Route4/scripts.pory"
	step_end
# 33 "data/maps/Route4/scripts.pory"

# 34 "data/maps/Route4/scripts.pory"
Route4_Movement_LTGThrowOff::
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
	walk_right
# 50 "data/maps/Route4/scripts.pory"
	walk_up
# 51 "data/maps/Route4/scripts.pory"
	jump_up
# 52 "data/maps/Route4/scripts.pory"
	step_end
# 53 "data/maps/Route4/scripts.pory"

# 54 "data/maps/Route4/scripts.pory"
Route4_Movement_PlayerFall::
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
	walk_right
# 70 "data/maps/Route4/scripts.pory"
	walk_up
# 71 "data/maps/Route4/scripts.pory"
	jump_2_right
# 72 "data/maps/Route4/scripts.pory"
	step_end
# 73 "data/maps/Route4/scripts.pory"

# 74 "data/maps/Route4/scripts.pory"
Route4_EventScript_Unused::
# 75 "data/maps/Route4/scripts.pory"
	end
# 76 "data/maps/Route4/scripts.pory"

# 77 "data/maps/Route4/scripts.pory"
Route4_EventScript_Woman::
# 78 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
# 79 "data/maps/Route4/scripts.pory"
	end
# 80 "data/maps/Route4/scripts.pory"

# 81 "data/maps/Route4/scripts.pory"
Route4_EventScript_MtMoonSign::
# 82 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
# 83 "data/maps/Route4/scripts.pory"
	end
# 84 "data/maps/Route4/scripts.pory"

# 85 "data/maps/Route4/scripts.pory"
Route4_EventScript_RouteSign::
# 86 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
# 87 "data/maps/Route4/scripts.pory"
	end
