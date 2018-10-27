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
	UI::UI_console* new_UI = new UI::UI_console_win();
	set_UI(new_UI);
	get_UI()->displayMainMenu();
	process_Input(get_UI()->getMenuChoice());
}

void Game_win::game_Loop()
{
	while (true)
	{
		
	}
}

void Game_win::process_Input(char input)
{
	

	switch (input)
	{
		// rotate piece
		case 'w':

		case 'W':
			if (is_Started() && !is_Paused()) {
				get_Board()->rotate_Piece();
			}
			break;
		// left move
		case 'a':

		case 'A':
			if (is_Started() && !is_Paused()) {
				get_Board()->move_Left();
			}
			break;
		// down move
		case 's':

		case 'S':
			if (is_Started() && !is_Paused()) {
				get_Board()->move_Down();
			}
			break;
		// right move
		case 'd':
			
		case 'D':
			if (is_Started() && !is_Paused()) {
				get_Board()->move_Right();
			}
			break;
		// pause
		case 'p':

		case 'P':
			if (is_Started() && !is_Paused()) {
				get_UI()->displayPauseMenu();
				process_Input(get_UI()->getMenuChoice());
			}
			break;
		//continue game
		case '1':
			if (is_Started() && is_Paused()) {
				set_paused(false);
			}
			break;
		//exit game
		case '2':
			if (is_Started() && is_Paused()) {
				end_Game();
			}
			break;
		default:
			// no input
			break;
	}
}

void Domain::Game_win::end_Game()
{
}
