//main for windows app
#pragma once

#include "../UI/Windows/UI_console_win.h"
#include "Game/Windows/Game_win.h"

int main(void) 
{
	UI::UI_console * game_UI = new UI::UI_console_win();
	Domain::Game * game = new Domain::Game_win(game_UI);
	
	game_UI->set_Game(game);

	bool cont = true;
	while (cont) 
	{
		// login first
		cont = game_UI->login();
		// if cont is still true (user did not choose to quit application), continue execution
		while (cont)
		{
			// now print main menu
			cont = game_UI->mainMenu();
		}
	}

	delete game_UI;
	delete game;
	system("pause");
	return 0;
}