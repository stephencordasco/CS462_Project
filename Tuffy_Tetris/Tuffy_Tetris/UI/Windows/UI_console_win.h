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
		UI_console_win();

		// print board

		void print_Frame(std::string);

		// printing menus to screen
		void displayLoginScreen();
		void displayMainMenu();
		void displayAccountMenu();
		void displayPurchaseSubscriptionScreen() override;
		void displayPauseMenu();

		// helper functions
		void displayLogin();
		void displayRegister();

		// menu functionality
		bool login();
		bool mainMenu();
		bool accountMenu();
		bool pauseMenu();

		// get user data
		char getMenuChoice();
		std::string getUserName();
		std::string getPassword();
		std::string getEmail();
		void setUserName();
		void setPassword();
		void setEmail();

	private:
		// member values
		char menuChoice;
		std::string username;
		std::string password;
		std::string email;
		bool hasSubscription;
		
	};
}