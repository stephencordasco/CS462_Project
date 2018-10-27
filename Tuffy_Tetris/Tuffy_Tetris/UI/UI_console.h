#pragma once

#include "../Services/Game_server.h"
#include <string>

namespace Domain 
{
	class Game;
}

namespace UI 
{
	class UI_console 
	{
	public:
		UI_console();

		// print board

		virtual void print_Frame(std::string) = 0;

		// printing menus to screen
		virtual void displayLoginScreen() = 0;
		virtual void displayMainMenu() = 0;
		virtual void displayAccountMenu() = 0;
		virtual void displayPurchaseSubscriptionScreen() = 0;
		virtual void displayPauseMenu() = 0;

		// menu functionality
		virtual bool login() = 0;
		virtual bool mainMenu() = 0;
		virtual bool accountMenu() = 0;
		virtual bool pauseMenu() = 0;

		// get user data
		virtual char getMenuChoice() = 0;
		virtual std::string getUserName() = 0;
		virtual std::string getPassword() = 0;
		virtual std::string getEmail() = 0;
		Domain::Game* get_Game();
		void set_Game(Domain::Game*);

		virtual ~UI_console();
	private:
		//common fields
		char menuChoice;
		std::string username;
		std::string password;
		std::string email;
		bool hasSubscription;
		Domain::Game* game;

	};
}