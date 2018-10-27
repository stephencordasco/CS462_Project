#pragma once

#include "../UI_console.h"

namespace UI
{
	class UI_console_win : UI_console 
	{
	public:
		// constructor
		UI_console_win();

		// printing menus to screen
		void displayLoginScreen() const;
		void displayMainMenu() const;
		void displayAccountMenu() const;
		void displayPurchaseSubscriptionScreen() const;

		// menu functionality
		bool login();
		bool mainMenu();
		bool accountMenu();

		// get user data
		char getMenuChoice();
		std::string getUserName();
		std::string getPassword();
		std::string getEmail();

	private:
		// member values
		char menuChoice;
		std::string username;
		std::string password;
		std::string email;
		bool hasSubscription;
		
	};
}