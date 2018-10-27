#pragma once

#include "UI_console.h"

using UI::UI_console;

UI_console::UI_console()
{

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
	delete game;
}