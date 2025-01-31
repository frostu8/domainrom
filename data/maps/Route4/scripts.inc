
Route4_MapScripts::
	.byte 0

Route4_EventScript_LTGThrow::
	lockall
	goto_if_eq VAR_0x808C, 1, Route4_EventScript_LTGYes
	goto_if_eq VAR_0x808C, 0, Route4_EventScript_LTGNO
	release
	end

Route4_EventScript_LTGYes::
	setobjectxyperm OBJ_EVENT_GFX_BROCK, 26, 6
	setobjectmovementtype OBJ_EVENT_GFX_BROCK, MOVEMENT_TYPE_FACE_LEFT
	applymovement OBJ_EVENT_GFX_BROCK, Route4_Movement_LTGThrowOff
	applymovement OBJ_EVENT_ID_PLAYER, Route4_Movement_PlayerFall
	setvar VAR_0x808C, 2
	releaseall
	end

Route4_EventScript_LTGNO::
	msgbox Route4_EventScript_LTGNope, MSGBOX_DEFAULT
	closemessage
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Route4_Movement_BackOff
	waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

Route4_Movement_BackOff::
	walk_left
	step_end

Route4_Movement_LTGThrowOff::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	jump_up
	step_end

Route4_Movement_PlayerFall::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	jump_2_right
	step_end

Route4_EventScript_Unused::
	end

Route4_EventScript_Woman::
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end
