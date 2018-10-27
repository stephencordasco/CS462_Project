#pragma once

#include "../Domain/Game/Game.h"
#include "../Services/Game_server.h"

namespace UI 
{
	class UI_console 
	{
	public:
		UI_console();

		// printing menus to screen
		virtual void displayLoginScreen() const = 0;
		virtual void displayMainMenu() const = 0;
		virtual void displayAccountMenu() const = 0;
		virtual void displayPurchaseSubscriptionScreen() const = 0;

		// menu functionality
		virtual bool login() = 0;
		virtual bool mainMenu() = 0;
		virtual bool accountMenu() = 0;

		// get user data
		virtual char getMenuChoice() = 0;
		virtual string getUserName() = 0;
		virtual string getPassword() = 0;
		virtual string getEmail() = 0;

	private:
		//common fields
		char menuChoice;
		string username;
		string password;
		string email;
		bool hasSubscription;

	};
}