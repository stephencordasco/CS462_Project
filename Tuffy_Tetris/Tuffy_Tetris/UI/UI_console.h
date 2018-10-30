#pragma once

#include "../Services/Game_server.h"
#include <string>
#include <iostream>

//forward declaration for Game class
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
		virtual void displayHighScoreScreen(int) = 0;
		virtual void saveNewHighScoreScreen(int) = 0;

		// menu functionality
		virtual bool login() = 0;
		virtual bool mainMenu() = 0;
		virtual bool accountMenu() = 0;
		virtual bool pauseMenu() = 0;

		// helper functions
		virtual void displayLogin() = 0;
		virtual void displayRegister() = 0;

		// get user data
		virtual char getMenuChoice() = 0;
		void setUserName();
		void setPassword();
		void setEmail();

		//trivial properties
		std::string getUserName() { return username; }
		std::string getPassword() { return password; }
		std::string getEmail() { return email; }
		bool getHasSubscription() { return hasSubscription; }
		void setHasSubscription(bool s) { hasSubscription = s; }
		Domain::Game* get_Game() { return game; }
		void set_Game(Domain::Game* g) { game = g; }
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