#include "Game.h"

Domain::Game::Game(UI::UI_console * ui) : game_UI(ui) {}

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

Domain::Board * Domain::Game::get_Board()
{
	return game_Board;
}

void Domain::Game::set_Board(Domain::Board * b)
{
	game_Board = b;
}

bool Domain::Game::is_Started()
{
	return game_started;
}

void Domain::Game::set_started(bool s)
{
	game_started = s;
}

bool Domain::Game::is_Paused()
{
	return game_paused;
}

void Domain::Game::set_paused(bool p)
{
	game_paused = p;
}

Domain::Game::~Game()
{
	delete game_UI;
	delete game_Board;
}
