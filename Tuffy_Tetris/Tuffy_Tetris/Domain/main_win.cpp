//main for windows app
#pragma once

#include "../UI/Windows/UI_console_win.h"
#include "Game/Windows/Game_win.h"

int main(void) 
{
	UI::UI_console_win * game_UI = new UI::UI_console_win();
	Domain::Game * game = new Domain::Game_win(game_UI);
	
	game_UI->set_Game(game);

	bool cont = true;
	while (cont) 
	{
		cont = game_UI->mainMenu();
	}

	return 0;
}