/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		main_win.cpp
Purpose:	main for Windows OS
*******************************************************************************/
#pragma once

#include "../UI/Windows/UI_console_win.h"
#include "Game/Windows/Game_win.h"

int main(void) 
{
	// pointer to an instance of the parent UI class
	UI::UI_console * game_UI = new UI::UI_console_win();
	// pointer to an instance of the parent Domain class
	Domain::Game * game = new Domain::Game_win(game_UI);
	// pointer to an instance of the parent Services class
	Services::Game_server * server = new Services::Game_server();
	
	game->set_game_Server(server);
	game_UI->set_Game(game);
	game_UI->set_Server(server);

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
	delete server;

	system("pause");
	return 0;
}