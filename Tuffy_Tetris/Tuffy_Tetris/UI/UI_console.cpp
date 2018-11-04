#pragma once

#include "UI_console.h"

using UI::UI_console;

UI_console::UI_console()
{
	username = " ";
	password = " ";
	email = " ";
	hasSubscription = false;
}

void UI::UI_console::clear_screen()
{
	std::cout << std::string(100, '\n');
}

void UI_console::setUserName()
{
	std::getline(std::cin, username);
}

void UI::UI_console::setPassword()
{
	std::getline(std::cin, password);
}

void UI_console::setEmail()
{
	std::getline(std::cin, email);
}