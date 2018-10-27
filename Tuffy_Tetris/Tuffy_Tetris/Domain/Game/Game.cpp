#include "Game.h"

int Domain::Game::get_Score()
{
	return score;
}

int Domain::Game::get_Level()
{
	return score;
}

void Domain::Game::set_Score(int sc)
{
	score = sc;
}

void Domain::Game::set_Level(int lv)
{
	level = lv;
}

UI::UI_console* Domain::Game::get_UI()
{
	return  game_UI;
}

void Domain::Game::set_UI(UI::UI_console * set_UI)
{
	game_UI = set_UI;
}
