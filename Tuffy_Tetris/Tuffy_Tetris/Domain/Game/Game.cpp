#include "Game.h"

Domain::Game::Game(UI::UI_console * ui) : game_UI(ui) {}

Domain::Game::~Game()
{
	if(game_UI) delete game_UI;
	if(game_Board) delete game_Board;
}
