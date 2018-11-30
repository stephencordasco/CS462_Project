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
#include "../Domain/Player/Player.h"
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#ifdef _WIN32
#include <conio.h>
#include <Windows.h>
#else
#include "../../../include/ncurses.h"
#include <unistd.h>
#endif

//forward declaration for Game class
namespace Domain 
{
	class Game;
	class Player;
}

namespace UI 
{
	class UI_console 
	{
	public:
		// constructor
		UI_console();

		//main loop
		virtual void game_Loop() = 0;

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
		virtual bool isAdmin() = 0;

		// get user data
		virtual char getMenuChoice() = 0;
		void setUserName();
		void setPassword();
		void setEmail();


		virtual ~UI_console();

	};
}