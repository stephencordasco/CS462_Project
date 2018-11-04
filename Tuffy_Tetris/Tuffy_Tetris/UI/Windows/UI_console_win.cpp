/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console_win.cpp
Purpose:	defines member functions for UI_console_win class
*******************************************************************************/
#pragma once

#ifdef _WIN32

#include "UI_console_win.h"
#include "../../Domain/Game/Game.h"
#include <iostream>
#include <conio.h>

using UI::UI_console_win;

UI::UI_console_win::UI_console_win() : UI_console() {}

/*******************************************************************************
Name:		print_Frame
Parameters:	string object
Purpose:	clears the screen and prints a frame
*******************************************************************************/
void UI::UI_console_win::print_Frame(std::string frame)
{
	// stub
	//todo
	clear_screen();
	std::cout << frame;
}

/*******************************************************************************
Name:		displayLoginScreen
Parameters:	none
Purpose:	clears the screen and prints the startup menu or login screen
*******************************************************************************/
void UI_console_win::displayLoginScreen()
{
	clear_screen();
	std::cout << "======= WELCOME USER =======\n";
	std::cout << "1.) Login\n";
	std::cout << "2.) Register\n";
	std::cout << "3.) Quit\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		displayLogin
Parameters:	none
Purpose:	prints the fields for the user to enter information in order to
			log into the application
*******************************************************************************/
void UI_console_win::displayLogin()
{
	// prevent "new line" capture
	std::cin.get();
	// print the login fields
	std::cout << "Username: ";
	setUserName();
	std::cout << "Password: ";
	setPassword();
	std::cout << "email: ";
	setEmail();
	
	// greet the user if login successful
	if (get_Server()->login(getUserName(), getPassword(), getEmail()))
	{	// print welcome message
		std::cout << "\nWelcome, " << getUserName() << "\n\n";
	}
	// login failed
	else
	{
		// print a message that login failed...
		std::cout << "Login failed. Please try again.\n";
		std::cout << "Press enter to continue...";
		std::cin.get();
		// ...print the login screen again
		login();
	}
}

/*******************************************************************************
Name:		displayRegister
Parameters:	none
Purpose:	prints the fields for the user to enter information in order to
			register a new account for the application
*******************************************************************************/
void UI_console_win::displayRegister()
{
	// prevent "new line" capture
	std::cin.get();
	// print the register fields
	std::cout << "\nPlease fill in the following fields:\n";
	std::cout << "\tUsername: ";
	setUserName();
	std::cout << "\tPassword: ";
	setPassword();
	std::cout << "\tCSUF email: ";
	setEmail();

	// greet the user if registration successful
	if (get_Server()->register_acct(getUserName(), getPassword(), getEmail()))
	{	// print welcome message
		//std::cout << "\nWelcome, " << getUserName() << "\n\n";
	}
	else
	// registration failed
	{
		// print a message that registration failed...
		std::cout << "Registration failed. Please try again.";
		std::cout << "Press enter to continue...";
		std::cin.get();
		// ...print the login screen again
		login();
	}
}

/*******************************************************************************
Name:		login
Parameters:	none
Purpose:	prints the startup menu or login screen, gets a menu choice from
			the user, and determines what to do next
*******************************************************************************/
bool UI_console_win::login()
{
	// print the first menu
	displayLoginScreen();

	// store the menu choice
	char choice = getMenuChoice();
	switch (choice)
	{
		case '1':	// user chose to login
			displayLogin();
			break;

		case '2':	// user chose to register
			displayRegister();
			break;

		case '3':	// user chose to quit
			std::cout << "Goodbye!\n\n";
			return false;

		default:	// user entered an invalid key
			std::cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

/*******************************************************************************
Name:		displayMainMenu
Parameters:	none
Purpose:	clears the screen, greets the user, and prints the main menu
*******************************************************************************/
void UI_console_win::displayMainMenu()
{
	clear_screen();
	// display username
	std::cout << "\nWelcome, " << getUserName() << "\n";
	// print main menu
	std::cout << "\n========== MAIN MENU =======\n";
	std::cout << "1.) Play Game\n";
	std::cout << "2.) Account Information\n";
	std::cout << "3.) Quit\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		mainMenu
Parameters:	none
Purpose:	prints the main menu, gets a menu choice from the user, and
			determines what to do next
*******************************************************************************/
bool UI_console_win::mainMenu()
{
	// print the main menu
	displayMainMenu();

	// store the menu choice
	char choice = getMenuChoice();
	switch (choice)
	{
		case '1':	// user chose to play game
			if (!(get_Game()->is_Started()))
			{
				get_Game()->start_Game();
			}
			break;

		case '2':	// user chose to access account information
			// display account menu
			accountMenu();
			break;
			
		case '3':	// user chose to quit
			std::cout << "\nLogging out...\n";
			if(get_Server()->logout(getUserName()))
			{
				std::cout << "...Log out successful!\n";
			}
			else 
			{
				std::cout << "...Log out unsuccessful, quitting.\n";
			}
			std::cout << "Goodbye!\n\n";
			return false;

		default:	// user entered an invalid key
			std::cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

/*******************************************************************************
Name:		displayAccountMenu
Parameters:	none
Purpose:	clears the scree, prints the current username and email of the
			user, and prints the account menu
*******************************************************************************/
void UI_console_win::displayAccountMenu()
{
	clear_screen();
	std::cout << "\n======= ACCOUNT MENU =======\n";
	std::cout << "Current Username: " << this->getUserName() << "\n";
	std::cout << "Current e-mail: " << this->getEmail() << "\n";
	std::cout << "============================\n";
	std::cout << "1.) Change Username\n";
	std::cout << "2.) Change Password\n";
	std::cout << "3.) Purchase Subscription\n";
	//std::cout << "4.) High Score\n";
	std::cout << "4.) Main Menu\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		displayPurchaseSubscriptionScreen
Parameters:	none
Purpose:	displays the purchase subscription screen going to use a stub here
			so that any values entered will always be accepted and a
			subscription purchase will be successful
*******************************************************************************/
void UI_console_win::displayPurchaseSubscriptionScreen()
{
	//setHasSubscription(get_Server()->check_sub());
	// check if the user already has a subscription
	if (this->getHasSubscription())
	{
		// inform user they already have a subscription
		std::cout << "\nYou already have a subscription!\n";
		std::cout << "Press enter to continue...";
		std::cin.get();
		// return to the account menu
		accountMenu();
		return;
	}

	// temp variables to hold the user input
	std::string cardNumber = " ";
	std::string accountHolder = " ";
	std::string securityNumber = " ";
	std::string expirationDate = " ";
	std::string billingAddress = " ";
	std::string zipCode = " ";

	// prevent "new line" capture
	std::cin.get();
	// print the card information fields
	std::cout << "\nPlease enter your card information:\n";
	std::cout << "Card Number: ";
	getline(std::cin, cardNumber);
	std::cout << "Account Holder: ";
	getline(std::cin, accountHolder);
	std::cout << "Security Number: ";
	getline(std::cin, securityNumber);
	std::cout << "Expiration Date: ";
	getline(std::cin, expirationDate);
	std::cout << "Billing Address: ";
	getline(std::cin, billingAddress);
	std::cout << "Zip Code: ";
	getline(std::cin, zipCode);

	// stub: payment is successful, hasSubscription assigned true
	if(get_Server()->update_sub(cardNumber, accountHolder, securityNumber,
								expirationDate, billingAddress, zipCode))
	{
		std::cout << "\nPurchase successful!\n";
		std::cout << "You now have access to online scores!\n";
		setHasSubscription(true);
	}
	else 
	{
		std::cout << "Transaction denied. Please try again.\n";
		std::cout << "Press enter to continue...";
		std::cin.get();
		accountMenu();
	}
	// if the payment was successful take the user back to the account menu
	if (getHasSubscription())
	{
		std::cout << "Press enter to continue...";
		std::cin.get();
		accountMenu();
	}
}

/*******************************************************************************
Name:		displayPauseMenu
Parameters:	none
Purpose:	clears the screen and displays the pause menu
*******************************************************************************/
void UI::UI_console_win::displayPauseMenu()
{
	clear_screen();
	std::cout << "\n======== PAUSE MENU ========\n";
	std::cout << "1.) Continue Game\n";
	std::cout << "2.) Exit to Main Menu\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		displayHighScoreScreen
Parameters:	integer value
Purpose:	clears the scree and displays the high score menu
*******************************************************************************/
void UI::UI_console_win::displayHighScoreScreen(int score)
{
	clear_screen();
	std::cout << "\n======== New High Score ========\n";
	std::cout << "\n======== " << score << " ========\n";
	std::cout << "1.) Save New High Score\n";
	std::cout << "2.) Exit to Main Menu\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		saveNewHighScoreScreen
Parameters:	integer value
Purpose:	checks if user has a subscription; if true, user enters in a
			nickname and the score is saved, message is printed to screen,
			otherwise the user is informed to purchase a subscription in order
			to save a score
*******************************************************************************/
void UI::UI_console_win::saveNewHighScoreScreen(int score)
{	

	if( getHasSubscription() )
	{
		std::cin.get();
		std::string nickname = " ";
		std::cout << "\nPlease enter a name for your score: ";
		getline(std::cin, nickname);
		std::cout << "\nsaving Score...\n";
		if (get_Server()->save_hs(get_Game()->get_Score()))
		{
			std::cout << "\n======== Congratulations " << nickname << " ========\n";
			std::cout << "\nYour score has been saved.\n";
			std::cout << "Enter any button to exit to Main Menu\n";
			std::cout << "============================\n";
		}
		else
		{
			std::cout << "Unable to save score. Please try again.\n";
		}
	}
	else 
	{
		std::cout << "You must purchase a subscription to use this feature.\n";
	}
	
}

/*******************************************************************************
Name:		accountMenu
Parameters:	none
Purpose:	displays the account menu, gets a menu choice from the user, and
			determines what to do next
*******************************************************************************/
bool UI_console_win::accountMenu()
{
	// print the account menu
	displayAccountMenu();

	// store the menu choice
	char choice = getMenuChoice();
	switch (choice)
	{
		case '1':	// user chose to change username
			// print the change username screen
			std::cin.get();
			// print current username
			std::cout << "\nYour current username: " << this->getUserName() << "\n";
			std::cout << "Enter a new username: ";
			setUserName();
			// print new username
			std::cout << "\nThank you! Your new username is " << this->getUserName() << "\n";
			std::cout << "Press enter to continue...";
			std::cin.get();
			// in this case, take user back to account menu
			accountMenu();
			break;

		case '2':	// user chose to change password
			// print the change password screen
			std::cin.get();
			// print current password
			std::cout << "\nYour current password: " << this->getPassword() << "\n";
			std::cout << "Enter a new password: ";
			setPassword();
			// print new password
			std::cout << "\nThank your! Your new password is " << this->getPassword() << "\n\n";
			std::cout << "Press enter to continue...";
			std::cin.get();
			// in this case, take user back to account menu
			accountMenu();
			break;

		case '3':	// user chose to purchase subscription
			// print the subscription screen
			displayPurchaseSubscriptionScreen();
			break;

		case '4':	// user chose to return to main menu
			std::cout << "\nGoing back to main menu...\n";
			std::cout << "Press enter to continue...";
			std::cin.get();
			return false;
			break;

		default:
			std::cout << "\nINVALID MENU CHOICE\n";
			std::cout << "Press enter to continue...";
			std::cin.get();
	}
	return true;
}

/*******************************************************************************
Name:		pauseMenu
Parameters:	none
Purpose:	displays the pause menu, gets a menu choice from the user, and
			determines what to do next
*******************************************************************************/
bool UI::UI_console_win::pauseMenu()
{
	// display pause menu
	displayPauseMenu();
	// store the user menu choice
	char inputchar = getMenuChoice();
	switch (inputchar)
	{
	case '1':	// user chose to continue game
		return true;
	case '2':	// user chose to quit game
		return false;
	default:
		return true;
	}
}

/*******************************************************************************
Name:		hsMenu
Parameters:	none
Purpose:	displays the high score screen with the user's score, gets a menu
			choice from the user and determines what to do next
*******************************************************************************/
void UI::UI_console_win::hsMenu()
{
	// print the high score screen with user score
	displayHighScoreScreen(get_Game()->get_Score());
	// get menu choice from the user
	char inputchar = getMenuChoice();
	switch (inputchar)
	{
		//save high score screen
	case '1':
		saveNewHighScoreScreen(get_Game()->get_Score());
		//enter key to go to main menu
		std::cout << "Press enter to continue...";
		std::cin.get();
		break;
		//go directly to main menu
	case '2':
		break;
	}
}

/*******************************************************************************
Name:		getMenuChoice
Parameters:	none
Purpose:	prompts the user to enter a menu choice, gets the menu choice,
			and returns it to the calling function
*******************************************************************************/
char UI_console_win::getMenuChoice()
{
	std::cout << "Enter a menu choice: ";
	std::string choice = "";
	std::cin >> choice;
	return choice[0];

}

#endif

