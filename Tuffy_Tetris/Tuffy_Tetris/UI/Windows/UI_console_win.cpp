#pragma once

#include "UI_console_win.h"
#include <iostream>

using UI::UI_console_win;

UI_console_win::UI_console_win()
{
	username = " ";
	password = " ";
	email = " ";
	hasSubscription = false;
}

// displays the first menu on application startup
void UI_console_win::displayLoginScreen() const
{
	std::cout << "============================\n";
	std::cout << "1.) Login\n";
	std::cout << "2.) Register\n";
	std::cout << "3.) Quit\n";
	std::cout << "============================\n";
}

// displays a new menu on "Login" selection
void displayLogin()
{
	std::cout << "Username: ";
	std::cout << "Password: ";
	std::cout << "email: ";
}

// displays a new menu on "Register" selection
void displayRegister()
{
	std::cout << "Please fill in the following fields:\n";
	std::cout << "\tUsername: ";
	std::cout << "\tPassword: ";
	std::cout << "\tCSUF email: ";
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
			return false;

		default:	// user entered an invalid key
			cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

// displays the main menu after user has logged in successfully or registered an account successfully
void UI_console_win::displayMainMenu() const
{
	std::cout << "============================\n";
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
			// call start_game?
			break;

		case '2':	// user chose to access account information
			// display account menu

			break;
			
		case '3':	// user chose to quit
			return false;

		default:	// user entered an invalid key
			cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

// displays the account menu
void UI_console_win::displayAccountMenu() const
{
	cout << "============================\n";
	cout << "1.) Change Username\n";
	cout << "2.) Change Password\n";
	cout << "3.) Purchase Subscription\n";
	cout << "4.) Main Menu\n";
	cout << "============================\n";
}

// displays the purchase subscription screen
//  going to use a stub here so that any values entered will always be accepted
//    and a subscription purchase will be successful
void UI_console_win::displayPurchaseSubscriptionScreen() const
{
	// temp variables to hold the user input
	string cardNumber = " ";
	string accountHolder = " ";
	string securityNumber = " ";
	string expirationDate = " ";
	string billingAddress = " ";
	string zipCode = " ";

	cout << "Card Number: ";
	getline(cin, cardNumber);
	cout << "Account Holder: ";
	getline(cin, accountHolder);
	cout << "Security Number: ";
	getline(cin, securityNumber);
	cout << "Expiration Date: ";
	getline(cin, expirationDate);
	cout << "Billing Address: ";
	getline(cin, billingAddress);
	cout << "Zip Code: ";
	getline(cin, zipCode);

	// stub: payment is successful, hasSubscription assigned true
	cout << "\nPurchase successful!\n";
	hasSubscription = true;

	// if the payment was successful take the user back to the account menu
	if (hasSubscription)
	{
		accountMenu();
	}
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
			break;

		case '2':	// user chose to change password
			// print the change password screen
			break;

		case '3':	// user chose to purchase subscription
			// print the subscription screen
			displayPurchaseSubscriptionScreen();
			break;

		case '4':	// user chose to return to main menu
			return false;
			break;

		default:
			cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

// gets user input for a menu selection
char UI_console_win::getMenuChoice()
{
	std::cin >> menuChoice;
}

// stores the username: (Might not need?)
string UI_console_win::getUserName()
{
	getline(std::cin, username);
}

// stores the password: (Might not need?)
string UI_console_win::getPassword()
{
	getline(std::cin, password);
}

// stores the email: (Might not need?)
string UI_console_win::getEmail()
{
	getline(std::cin, email);
}