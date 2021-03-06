IslandCave_MapScripts:: @ 8238E2A
	map_script MAP_SCRIPT_ON_RESUME, IslandCave_MapScript1_238E3A
	map_script MAP_SCRIPT_ON_LOAD, IslandCave_MapScript1_238E58
	map_script MAP_SCRIPT_ON_TRANSITION, IslandCave_MapScript1_238E99
	.byte 0

IslandCave_MapScript1_238E3A: @ 8238E3A
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IslandCave_EventScript_238E44
	end

IslandCave_EventScript_238E44:: @ 8238E44
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

IslandCave_MapScript1_238E58: @ 8238E58
	call_if_unset FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_238E62
	end

IslandCave_EventScript_238E62:: @ 8238E62
	setmetatile 7, 19, 553, 1
	setmetatile 8, 19, 553, 1
	setmetatile 9, 19, 553, 1
	setmetatile 7, 20, 565, 1
	setmetatile 8, 20, 565, 1
	setmetatile 9, 20, 565, 1
	return

IslandCave_MapScript1_238E99: @ 8238E99
	setflag FLAG_LANDMARK_ISLAND_CAVE
	call IslandCave_EventScript_238F45
	call_if_unset FLAG_DEFEATED_REGICE, IslandCave_EventScript_238EAB
	end

IslandCave_EventScript_238EAB:: @ 8238EAB
	clearflag FLAG_HIDE_REGICE
	return

IslandCave_EventScript_238EAF:: @ 8238EAF
	setmetatile 7, 19, 554, 1
	setmetatile 8, 19, 555, 1
	setmetatile 9, 19, 556, 1
	setmetatile 7, 20, 562, 1
	setmetatile 8, 20, 563, 0
	setmetatile 9, 20, 564, 1
	special DrawWholeMapView
	playse SE_BAN
	setflag FLAG_SYS_BRAILLE_REGICE_COMPLETED
	end

IslandCave_EventScript_238EEF:: @ 8238EEF
	lockall
	call_if_set FLAG_TEMP_3, IslandCave_EventScript_238F45
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_238F13
	braillemessage IslandCave_Braille_2A6CD4
	setflag FLAG_TEMP_2
	special ShouldDoBrailleRegicePuzzle
	goto IslandCave_EventScript_238F41
	end

IslandCave_EventScript_238F13:: @ 8238F13
	msgbox gUnknown_0827304E, MSGBOX_DEFAULT
	releaseall
	end

IslandCave_EventScript_238F1D:: @ 8238F1D
	lockall
	call_if_set FLAG_TEMP_3, IslandCave_EventScript_238F45
	braillemessage IslandCave_Braille_2A6CD4
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_238F41
	setflag FLAG_TEMP_2
	special ShouldDoBrailleRegicePuzzle
	goto IslandCave_EventScript_238F41
	end

IslandCave_EventScript_238F41:: @ 8238F41
	waitbuttonpress
	hidebox2
	releaseall
	end

IslandCave_EventScript_238F45:: @ 8238F45
	setvar VAR_REGICE_STEPS_1, 0
	setvar VAR_REGICE_STEPS_2, 0
	setvar VAR_REGICE_STEPS_3, 0
	clearflag FLAG_TEMP_3
	return

IslandCave_EventScript_238F58:: @ 8238F58
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGICE, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGICE, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq IslandCave_EventScript_238F9F
	compare VAR_RESULT, 4
	goto_if_eq IslandCave_EventScript_238FA8
	compare VAR_RESULT, 5
	goto_if_eq IslandCave_EventScript_238FA8
	setflag FLAG_DEFEATED_REGICE
	release
	end

IslandCave_EventScript_238F9F:: @ 8238F9F
	setflag FLAG_DEFEATED_REGICE
	goto IslandCave_EventScript_27376D
	end

IslandCave_EventScript_238FA8:: @ 8238FA8
	setvar VAR_0x8004, 402
	goto IslandCave_EventScript_273776
	end
