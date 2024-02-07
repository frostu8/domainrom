LowTierGodGym_MapScripts::
	.byte 0

LowTierGodGym_EventScript_LTG::
	famechecker FAMECHECKER_BROCK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, LowTierGodGym_EvenScript_LTGPostBattle
	msgbox LowTierGodGym_Text_LTGTroll
	msgbox LowTierGodGym_Text_PayUp, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LowTierGodGym_EventScript_NoPay
	msgbox LowTierGodGym_Text_YesPay, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_BROCK, LowTierGodGym_Text_LTGIntro, LowTierGodGym_Text_LTGDefeat, LowTierGodGym_EventScript_DefeatedLTG, NO_MUSIC
	goto_if_unset FLAG_GOT_TM39_FROM_BROCK, LowTierGodGym_EventScript_GiveTM39
	release
	end

LowTierGodGym_EvenScript_LTGPostBattle::
	msgbox LowTierGodGym_Text_BrockPostBattle
	release
	end

LowTierGodGym_EventScript_NoPay::
	msgbox LowTierGodGym_Text_NoPay, MSGBOX_DEFAULT
	release
	end

LowTierGodGym_EventScript_DefeatedLTG::
	famechecker FAMECHECKER_BROCK, 1
	setflag FLAG_DEFEATED_BROCK
	setflag FLAG_BADGE01_GET
	setvar VAR_0x808C, 1
	setvar VAR_MAP_SCENE_PEWTER_CITY, 1
	setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	set_gym_trainers 1
	goto LowTierGodGym_EventScript_GiveTM39
	end

LowTierGodGym_EventScript_GiveTM39::
	msgbox LowTierGodGym_Text_TakeThisWithYou
	checkitemspace ITEM_TM39
	goto_if_eq VAR_RESULT, FALSE, LowTierGodGym_EventScript_NoRoomForTM39
	giveitem_msg LowTierGodGym_Text_ReceivedTM39FromBrock, ITEM_TM39
	setflag FLAG_GOT_TM39_FROM_BROCK
	msgbox LowTierGodGym_Text_ExplainTM39
	release
	end

LowTierGodGym_EventScript_NoRoomForTM39::
	msgbox LowTierGodGym_Text_DontHaveRoomForThis
	release
	end

