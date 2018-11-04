#pragma once

#include "../UI_console.h"

//forward declaration for Game_win class
namespace Domain
{
	class Game_linux;
}

namespace UI 
{
	class UI_console_linux : public UI_console 
	{
	public:
		UI_console_linux();

		void print_Frame(std::string) override;

		// printing menus to screen
		void displayLoginScreen() override;
		void displayMainMenu() override;
		void displayAccountMenu() override;
		void displayPurchaseSubscriptionScreen() override;
		void displayPauseMenu() override;
		void displayHighScoreScreen(int) override;
		void saveNewHighScoreScreen() override;

		// helper functions
		void displayLogin() override;
		void displayRegister() override;

		// menu functionality
		bool login() override;
		bool mainMenu() override;
		bool accountMenu() override;
		bool pauseMenu() override;
		void hsMenu() override;

		// get user data
		char getMenuChoice() override;
	private:
	
	};
}