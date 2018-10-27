#pragma once

#include "UI_console_win.h"

using UI::UI_console_win;

UI_console_win::UI_console_win()
{

}

void UI_console_win::displayLoginScreen() const
{
	cout << "============================\n";
	cout << "1.) Login\n";
	cout << "2.) Register\n";
	cout << "3.) Quit\n";
	cout << "============================\n";
}

void displayLogin()
{
	cout << "Username: ";
	cout << "Password: ";
	cout << "email: ";
}

void displayRegister()
{
	cout << "Please fill in the following fields:\n";
	cout << "\tUsername: ";
	cout << "\tPassword: ";
	cout << "\tCSUF email: ";
}

bool UI_console_win::login()
{
	displayLoginScreen();
	switch (menuChoice)
	{
		case '1':
			displayLogin();
			break;

		case '2':
			displayRegister();
			break;

		case '3':
			return false;

		default:
			cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

void UI_console_win::displayMainMenu() const
{
	cout << "============================\n";
	cout << "1.) Play Game\n";
	cout << "2.) Account Information\n";
	cout << "3.) Quit\n";
	cout << "============================\n";
}

char UI_console_win::getMenuChoice()
{
	cin >> menuChoice;
}

string UI_console_win::getUserName()
{
	getline(cin, username);
}

string UI_console_win::getPassword()
{
	getline(cin, password);
}

string UI_console_win::getEmail()
{
	getline(cin, email);
}