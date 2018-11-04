/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console.h
Purpose:	interface class declares virtual member functions and member
			variables
*******************************************************************************/
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
		// constructor
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
		virtual void saveNewHighScoreScreen() = 0;

		// menu functionality
		virtual bool login() = 0;
		virtual bool mainMenu() = 0;
		virtual bool accountMenu() = 0;
		virtual bool pauseMenu() = 0;
		virtual void hsMenu() = 0;

		// helper functions
		virtual void displayLogin() = 0;
		virtual void displayRegister() = 0;
		void clear_screen();

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
		Services::Game_server* get_Server() { return server; }
		void set_Server(Services::Game_server* s) { server = s; }

		virtual ~UI_console();
	private:
		//common fields
		char menuChoice;
		std::string username;
		std::string password;
		std::string email;
		bool hasSubscription;
		Domain::Game* game;
		Services::Game_server* server;

	};
}