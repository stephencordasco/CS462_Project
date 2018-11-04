/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console.cpp
Purpose:	defines default constructor and setters for member variables
*******************************************************************************/


#include "UI_console.h"

using UI::UI_console;

/*******************************************************************************
Name:		UI_console
Parameters:	none
Purpose:	default constructor: initializes an instance of a UI_console object
*******************************************************************************/
UI_console::UI_console()
{
	username = " ";
	password = " ";
	email = " ";
	hasSubscription = false;
	game = nullptr;
	server = nullptr;
}

/*******************************************************************************
Name:		clear_screen
Parameters:	none
Purpose:	Helper function that simply prints 100 newlines to clear console screen
*******************************************************************************/
void UI::UI_console::clear_screen()
{
	std::cout << std::string(100, '\n');
}

/*******************************************************************************
Name:		setUserName
Parameters:	none
Purpose:	gets string input for username from the keyboard and stores it
			in memory
*******************************************************************************/
void UI_console::setUserName()
{
	std::getline(std::cin, username);
}

/*******************************************************************************
Name:		setPassword
Parameters:	none
Purpose:	gets string input for password from the keyboard and stores it
			in memory
*******************************************************************************/
void UI::UI_console::setPassword()
{
	std::getline(std::cin, password);
}

/*******************************************************************************
Name:		setEmail
Parameters:	none
Purpose:	gets string input for email from the keyboard and stores it
			in memory
*******************************************************************************/
void UI_console::setEmail()
{
	std::getline(std::cin, email);
}

UI::UI_console::~UI_console()
{
}
