#pragma once

#include "./Game_win.h"

using Domain::Game_win;

Game_win::Game_win() 
{
	set_Score(0);
	set_Level(0);

}

void Game_win::start_Game()
{

}

void Game_win::game_Loop()
{
	while (process_Input())
	{
		
	}
}

bool Game_win::process_Input()
{
	switch (/*input*/)
	{
		// rotate piece
		case 'w':

		case 'W':

			return true;
			break;
		// left move
		case 'a':

		case 'A':

			return true;
			break;
		// down move
		case 's':

		case 'S':

			return true;
			break;
		// right move
		case 'd':

		case 'D':

			return true;
			break;

		case 'p':

		case 'P':
			
			return true;
			break;

		case 'q':

		case 'Q':

			return false;
			break;
		default:
			// no input
	}
}

void Game_win::get_Score()
{
	return score;
}

void Game_win::get_Level()
{
	return level;
}