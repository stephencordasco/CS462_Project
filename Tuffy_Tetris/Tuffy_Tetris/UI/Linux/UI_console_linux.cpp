#pragma once

#include "UI_console_linux.h"

using UI::UI_console_linux;

UI_console_linux::UI_console_linux() : UI_console() {}
{
}

void UI::UI_console_linux::print_Frame(std::string)
{
}

void UI::UI_console_linux::displayLoginScreen()
{
}

void UI::UI_console_linux::displayMainMenu()
{
}

void UI::UI_console_linux::displayAccountMenu()
{
}

void UI::UI_console_linux::displayPurchaseSubscriptionScreen()
{
}

void UI::UI_console_linux::displayPauseMenu()
{
}

void UI::UI_console_linux::displayHighScoreScreen(int)
{
}

void UI::UI_console_linux::saveNewHighScoreScreen(int)
{
}

void UI::UI_console_linux::displayLogin()
{
}

void UI::UI_console_linux::displayRegister()
{
}

bool UI::UI_console_linux::login()
{
	return true;
}

bool UI::UI_console_linux::mainMenu()
{
	get_Game()->start_Game();
	return true;
}

bool UI::UI_console_linux::accountMenu()
{
	return false;
}

bool UI::UI_console_linux::pauseMenu()
{
	return false;
}

void UI::UI_console_linux::hsMenu()
{
}

char UI::UI_console_linux::getMenuChoice()
{
	return 0;
}
