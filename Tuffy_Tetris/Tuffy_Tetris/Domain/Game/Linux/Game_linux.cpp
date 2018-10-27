#pragma once

#include "./Game_linux.h"

using Domain::Game_linux;

Game_linux::Game_linux(UI::UI_console * ui) : Game(ui)
{
	set_Score(0);
	set_Level(0);
}

void Game_linux::start_Game()
{
}
