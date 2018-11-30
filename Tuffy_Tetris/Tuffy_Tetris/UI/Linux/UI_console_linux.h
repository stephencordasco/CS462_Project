/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console_linux.h
Purpose:	child class of UI_console declares member functions and member
			variables for Linux OS
*******************************************************************************/

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
		// constructor
		UI_console_linux();

		// print board
		void print_Frame(std::string) override;

		// game loop
		void game_Loop() override;

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
		std::string username;
		std::string password;
		std::string email;
		int highScore;
		bool hasSubscription;
		Domain::Game* game;
		Services::Game_server* server;
		Domain::Player* player;
	
	};
}