#pragma once

#include "../UI_console.h"

namespace Domain 
{
	class Game_win;
}

namespace UI
{
	class UI_console_win : public UI_console 
	{
	public:
		// constructor
		// print board

		void print_Frame(std::string);

		// printing menus to screen
		void displayLoginScreen();
		void displayMainMenu();
		void displayAccountMenu();
		void displayPurchaseSubscriptionScreen() override;
		void displayPauseMenu();
		void displayHighScoreScreen(int);
		void saveNewHighScoreScreen(int);

		// helper functions
		void displayLogin();
		void displayRegister();

		// menu functionality
		bool login();
		bool mainMenu();
		bool accountMenu();
		bool pauseMenu();

		// get user data
		char getMenuChoice() override;

	private:
		
	};
}