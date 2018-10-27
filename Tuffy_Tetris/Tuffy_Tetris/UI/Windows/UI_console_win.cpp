#pragma once

#include "UI_console_win.h"
#include <iostream>

using UI::UI_console_win;

UI_console_win::UI_console_win()
{

}

void UI_console_win::displayLoginScreen() const
{
	std::cout << "============================\n";
	std::cout << "1.) Login\n";
	std::cout << "2.) Register\n";
	std::cout << "3.) Quit\n";
	std::cout << "============================\n";
}

void displayLogin()
{
	std::cout << "Username: ";
	std::cout << "Password: ";
	std::cout << "email: ";
}

void displayRegister()
{
	std::cout << "Please fill in the following fields:\n";
	std::cout << "\tUsername: ";
	std::cout << "\tPassword: ";
	std::cout << "\tCSUF email: ";
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
			std::cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

void UI_console_win::displayMainMenu() const
{
	std::cout << "============================\n";
	std::cout << "1.) Play Game\n";
	std::cout << "2.) Account Information\n";
	std::cout << "3.) Quit\n";
	std::cout << "============================\n";
}

char UI_console_win::getMenuChoice()
{
	std::cin >> menuChoice;
}

std::string UI_console_win::getUserName()
{
	getline(std::cin, username);
}

std::string UI_console_win::getPassword()
{
	getline(std::cin, password);
}

std::string UI_console_win::getEmail()
{
	getline(std::cin, email);
}