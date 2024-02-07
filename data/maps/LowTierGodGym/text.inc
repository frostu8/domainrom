LowTierGodGym_Text_LTGIntro::
    .string "If your small brained dumbass\n"
    .string "hasn't noticed yet.\p"
    .string "I'm a straight up fighting type\n"
    .string "gym leader!\p"
    .string "That's right, my team will kick\n"
    .string "your ass into oblivion!\p"
    .string "Be prepared!\n"
    .string "For my BBC Jr!{PLAY_BGM}{MUS_ENCOUNTER_GYM_LEADER}$"

LowTierGodGym_Text_LTGTroll::
    .string "Oh wow. Another worthless bitch\n"
    .string "ass trainer.\p"
    .string "Probably from Kanto, aren't you?\n"
    .string "Damn Kantonian trolls piss me off.\p"
    .string "Wanna fight me stupid ass?\n"
    .string "Pay the fuck up.$"

LowTierGodGym_Text_PayUp::
    .string "{FONT_NORMAL}Pay LowTierGod 5 bucks?$"

LowTierGodGym_Text_YesPay::
    .string "Alright then.$"

LowTierGodGym_Text_NoPay::
    .string "You poor asshole, come back when\n"
    .string "you have some dough.$"


@ NOTE: This defeat text actually causes a buffer overflow. It's too long for the gDisplayedStringBattle
@ buffer that it's put into, and it stomps all over the gBattleTextBuffs after, as well as the otherwise
@ unused array after that, sFlickerArray. Perhaps that's the reason why said array exists.
LowTierGodGym_Text_LTGDefeat::
    .string "GOD DAMMIT!\n"
    .string "I lost....\p"
    .string "You totally cheated right there.\n"
    .string "But since I legally have to,\l"
    .string "here is the HADOUKENBADGE.\p"
    .string "{FONT_NORMAL}{PLAYER} received the HADOUKENBADGE\n"
    .string "from BROCK!{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}\p"
    .string "{FONT_MALE}NOW LEAVE BEFORE I KICK\n"
    .string "YOUR ASS PHYISCALLY!$"

LowTierGodGym_Text_TakeThisWithYou::
    .string "Wait!\n"
    .string "Take this.$"

LowTierGodGym_Text_ReceivedTM39FromBrock::
    .string "{PLAYER} received TM39\n"
    .string "from LowTierGod.$"

LowTierGodGym_Text_ExplainTM39::
    .string "A TM, Technical Machine, contains a\n"
    .string "technique for POKéMON.\p"
    .string "Using a TM teaches the move it\n"
    .string "contains to a POKéMON.\p"
    .string "A TM is good for only one use.\p"
    .string "So, when you use one, pick the\n"
    .string "POKéMON carefully.\p"
    .string "Anyways…\n"
    .string "TM39 contains ROCK TOMB.\p"
    .string "It hurls boulders at the foe and\n"
    .string "lowers its SPEED.$"

LowTierGodGym_Text_BrockPostBattle::
    .string "I told you to FUCK OFF!\n"
    .string "DAMN, GOTTA KEEP SLURPING\p"
    .string "THE MOTHERFUCKING SYRUP!\n"
    .string "LEAVE MY GYM NOW!$"

LowTierGodGym_Text_DontHaveRoomForThis::
    .string "You don't have room for this.$"
