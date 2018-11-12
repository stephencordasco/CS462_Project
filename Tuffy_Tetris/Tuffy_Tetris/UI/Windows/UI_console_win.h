/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console_win.h
Purpose:	child class of UI_console declares member functions and member
			variables for Windows OS
*******************************************************************************/
#pragma once

#include "../UI_console.h"

//forward declaration for Game_win class
namespace Domain 
{
	class Game_win;
	class Player;
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
		void saveNewHighScoreScreen() override;

		// helper functions
		void displayLogin() override;
		void displayRegister() override;
		bool isAdmin() override;

		// menu functionality
		bool login() override;
		bool mainMenu() override;
		bool accountMenu() override;
		bool pauseMenu() override;
		void hsMenu() override;

		// get user data
		char getMenuChoice() override;

	private:
		Domain::Player* player;
	};
}