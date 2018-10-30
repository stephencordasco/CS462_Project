#pragma once

#include "../UI_console.h"

//forward declaration for Game_win class
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
		UI_console_win();
		// print board

		void print_Frame(std::string) override;

		// printing menus to screen
		void displayLoginScreen() override;
		void displayMainMenu() override;
		void displayAccountMenu() override;
		void displayPurchaseSubscriptionScreen() override;
		void displayPauseMenu() override;
		void displayHighScoreScreen(int) override;
		void saveNewHighScoreScreen(int) override;

		// helper functions
		void displayLogin() override;
		void displayRegister() override;

		// menu functionality
		bool login() override;
		bool mainMenu() override;
		bool accountMenu() override;
		bool pauseMenu() override;

		// get user data
		char getMenuChoice() override;

	private:
		
	};
}