#include "Game.h"

UI::UI_console* Domain::Game::get_UI()
{
	return  &game_UI;
}

void Domain::Game::set_UI(UI::UI_console & set_UI)
{
	game_UI = set_UI;
}
