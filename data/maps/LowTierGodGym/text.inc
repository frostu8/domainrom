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
    .string "I took you for granted, and so\n"
    .string "I lost.\p"
    .string "As proof of your victory, I confer\n"
    .string "on you this…the official POKéMON\l"
    .string "LEAGUE BOULDERBADGE.\p"
    .string "{FONT_NORMAL}{PLAYER} received the BOULDERBADGE\n"
    .string "from BROCK!{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}\p"
    .string "{FONT_MALE}Just having the BOULDERBADGE makes\n"
    .string "your POKéMON more powerful.\p"
    .string "It also enables the use of the\n"
    .string "move FLASH outside of battle.\p"
    .string "Of course, a POKéMON must know the\n"
    .string "move FLASH to use it.$"

LowTierGodGym_Text_TakeThisWithYou::
    .string "Wait!\n"
    .string "Take this with you.$"

LowTierGodGym_Text_ReceivedTM39FromBrock::
    .string "{PLAYER} received TM39\n"
    .string "from BROCK.$"

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
    .string "There are all kinds of TRAINERS in\n"
    .string "this huge world of ours.\p"
    .string "You appear to be very gifted as a\n"
    .string "POKéMON TRAINER.\p"
    .string "So let me make a suggestion.\p"
    .string "Go to the GYM in CERULEAN and test\n"
    .string "your abilities.$"

LowTierGodGym_Text_DontHaveRoomForThis::
    .string "You don't have room for this.$"
