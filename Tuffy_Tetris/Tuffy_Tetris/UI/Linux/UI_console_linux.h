/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console_linux.h
Purpose:	Concrete class for UI_console interface declares member functions and 
			member variables for Linux OS
*******************************************************************************/

#ifndef UI_CONSOLE_LINUX_H
#define UI_CONSOLE_LINUX_H

#include "../UI_console.h"

//forward declaration for Game_win class
namespace Domain
{
	class Player;
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
		// kbhit for ncurses
		int kbhit(void);

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
		void viewHighScore() override;

		// helper functions
		void displayLogin() override;
		void displayRegister() override;
		void clear_screen() override;

		// menu functionality
		bool login() override;
		bool mainMenu() override;
		bool accountMenu() override;
		bool pauseMenu() override;
		void hsMenu() override;

		// get user data
		char getMenuChoice() override;

		// setters
		void set_Game(Domain::Game *) override;
		void set_Player(Domain::Player *) override;

	private:
		std::string username;
		std::string password;
		std::string email;
		int highScore;
		Domain::Game* game;
		Domain::Player* player;
	
	};
}

#endif