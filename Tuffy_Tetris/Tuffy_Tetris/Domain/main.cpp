/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		main.cpp
Purpose:	Includes main entry point for program and an inline factory class
			for creating polymorphic UI and Game objects
*******************************************************************************/


#ifdef _WIN32
#include "../UI/Windows/UI_console_win.h"
#else
#include "../UI/Linux/UI_console_linux.h"
#include "Game/Linux/Game_linux.h"
#endif

#include "Game/GameTetris.h"
#include "../Services/PaymentFactory.h"
#include "../Services/SimpleDB.h"
#include "../Services/IPayment.h"

class MainFactory
{
public:
	static UI::UI_console* create_UI()
	{
#ifdef _WIN32
		return new UI::UI_console_win();
#else
		return new UI::UI_console_linux();
#endif			
	}
};

int main(void) 
{
	// pointer to an instance of the parent UI class
	UI::UI_console * game_UI = MainFactory::create_UI();
	// pointer to an instance of the parent Domain class
	Domain::Game * game = new Domain::GameTetris();
	// pointer to an instance of the Services class
	Services::PersistenceHandler * server = new Services::SimpleDB();


	//set pointer references inside objects
	game->set_Server(server);
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
	delete server;

	std::cout << "Press enter to continue...";
	std::cin.get(); std::cin.get();
	return 0;
}