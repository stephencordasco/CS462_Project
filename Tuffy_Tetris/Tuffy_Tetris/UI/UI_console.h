#pragma once

#include "../Services/Game_server.h"
#include <string>

namespace UI 
{
	class UI_console 
	{
	public:
		UI_console();

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

	private:
		//common fields
		char menuChoice;
		std::string username;
		std::string password;
		std::string email;
		bool hasSubscription;

	};
}