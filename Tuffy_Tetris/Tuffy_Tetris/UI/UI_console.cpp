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

// stores the username: (Might not need?)
std::string UI_console::getUserName()
{
	return username;
}

// stores the password: (Might not need?)
std::string UI_console::getPassword()
{
	return password;
}

// stores the email: (Might not need?)
std::string UI_console::getEmail()
{
	return email;
}

bool UI::UI_console::getHasSubscription()
{
	return hasSubscription;
}

void UI::UI_console::setHasSubscription(bool s)
{
	hasSubscription = s;
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

Domain::Game * UI::UI_console::get_Game()
{
	return game;
}

void UI::UI_console::set_Game(Domain::Game * g)
{
	game = g;
}

UI_console::~UI_console() 
{
}