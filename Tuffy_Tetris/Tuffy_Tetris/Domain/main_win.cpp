//main for windows app
#pragma once

#include "Game/Windows/Game_win.h"
#include "../UI/Windows/UI_console_win.h"
int main(void) 
{
	UI::UI_console_win game_UI = UI::UI_console_win();
	Domain::Game_win game = Domain::Game_win::Game_win();

	game.start_Game();

	return 0;
}