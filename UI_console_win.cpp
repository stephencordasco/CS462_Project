#pragma once

#include "UI_console_win.h"
#include<iostream>
#include<string>

using UI::UI_console_win;

UI_console_win::UI_console_win()
{

}

void UI_console_win::printMainMenu() const
{

	std::cout << "\tMain Menu\t" << std::endl;
	std::cout << "\ta)New Game\t" << std::endl;
	std::cout << "\tb)Display High Scores\t" << std::endl;
	std::cout << "\tc)Login\t" << std::endl;

}

void UI_console_win::login() {
	std::string username;
	std::string password;
	std::cout << "Please enter your username." << std::endl;
	std::cin >> username;
	std::cout << "Please enter your password." << std::endl;
	std::cin >> password;

	std::cout << "Checking for account in database..." << std::endl;
	std::cout << "Account has been successfully found.\n\n" << std::endl;
	std::cout << "Welcome " << username << "." << std::endl;
	std::cout << "\n\n";

}