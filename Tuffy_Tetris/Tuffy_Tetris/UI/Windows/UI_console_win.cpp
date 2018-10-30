#pragma once

#include "UI_console_win.h"
#include "../../Domain/Game/Game.h"
#include <iostream>

using UI::UI_console_win;

UI::UI_console_win::UI_console_win() : UI_console() {}

void UI::UI_console_win::print_Frame(std::string frame)
{
	// stub
	//todo
	std::cout << frame;
}

// displays the first menu on application startup
void UI_console_win::displayLoginScreen()
{
	std::cout << "======= WELCOME USER =======\n";
	std::cout << "1.) Login\n";
	std::cout << "2.) Register\n";
	std::cout << "3.) Quit\n";
	std::cout << "============================\n";
}

// displays a new menu on "Login" selection
void UI_console_win::displayLogin()
{
	std::cin.get();
	std::cout << "Username: ";
	setUserName();
	std::cout << "Password: ";
	setPassword();
	std::cout << "email: ";
	setEmail();

	// print welcome message
	std::cout << "\nWelcome, " << getUserName() << "\n\n";
}

// displays a new menu on "Register" selection
void UI_console_win::displayRegister()
{
	std::cin.get();
	std::cout << "\nPlease fill in the following fields:\n";
	std::cout << "\tUsername: ";
	setUserName();
	std::cout << "\tPassword: ";
	setPassword();
	std::cout << "\tCSUF email: ";
	setEmail();

	// print welcome message
	std::cout << "\nWelcome, " << getUserName() << "\n\n";
}

// returns true if the user selected "Login" or "Register"; returns false otherwise
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

// displays the main menu after user has logged in successfully or registered an account successfully
void UI_console_win::displayMainMenu()
{
	std::cout << "\n========== MAIN MENU =======\n";
	std::cout << "1.) Play Game\n";
	std::cout << "2.) Account Information\n";
	std::cout << "3.) Quit\n";
	std::cout << "============================\n";
}

// returns true if the user selected "Play Game" or "Account Information"; returns false otherwise
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
			std::cout << "...Log out successful!\n";
			std::cout << "Goodbye!\n\n";
			return false;

		default:	// user entered an invalid key
			std::cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

// displays the account menu
void UI_console_win::displayAccountMenu()
{
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

// displays the purchase subscription screen
//  going to use a stub here so that any values entered will always be accepted
//    and a subscription purchase will be successful
void UI_console_win::displayPurchaseSubscriptionScreen()
{
	// check if the user already has a subscription
	if (this->getHasSubscription())
	{
		// inform user they already have a subscription
		std::cout << "\nYou already have a subscription!\n";
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

	std::cin.get();
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
	//todo
	std::cout << "\nPurchase successful!\n";
	std::cout << "You now have access to online scores!\n";
	setHasSubscription(true);

	// if the payment was successful take the user back to the account menu
	if (getHasSubscription())
	{
		accountMenu();
	}
}

void UI::UI_console_win::displayPauseMenu()
{
	std::cout << "\n======== PAUSE MENU ========\n";
	std::cout << "1.) Continue Game\n";
	std::cout << "2.) Exit to Main Menu\n";
	std::cout << "============================\n";
}

void UI::UI_console_win::displayHighScoreScreen(int score)
{
	std::cout << "\n======== New High Score ========\n";
	std::cout << "\n======== " << score << " ========\n";
	std::cout << "1.)Save New High Score\n";
	std::cout << "2.) Exit to Main Menu\n";
	std::cout << "============================\n";
}

void UI::UI_console_win::saveNewHighScoreScreen(int score)
{
	std::cin.get();
	std::string nickname = " ";
	std::cout << "\nPlease enter a name for your score.";
	getline(std::cin, nickname);
	std::cout << "\nsaving Score...\n";
	std::cout << "\n======== Congratulations " <<nickname<<" ========\n";
	std::cout << "\nYour score has been saved.\n";
	std::cout << "Enter any button to exit to Main Menu\n";
	std::cout << "============================\n";
}

// returns true if the user selected "Change Username", "Change Password", or "Purchase Subscription";
//  returns false otherwise
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
			// in this case, take user back to account menu
			accountMenu();
			break;

		case '3':	// user chose to purchase subscription
			// print the subscription screen
			displayPurchaseSubscriptionScreen();
			break;

		case '4':	// user chose to return to main menu
			std::cout << "\nGoing back to main menu...\n";
			return false;
			break;

		default:
			std::cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}



bool UI::UI_console_win::pauseMenu()
{
	//stub
	//todo
	return true;
}

// gets user input for a menu selection
char UI_console_win::getMenuChoice()
{
	std::cout << "Enter a menu choice: ";
	std::string choice = "";
	std::cin >> choice;
	return choice[0];

}

