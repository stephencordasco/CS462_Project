#pragma once

#include "./Game_win.h"
#include <iostream>

using Domain::Game_win;

Game_win::Game_win(UI::UI_console * ui) : Game(ui)
{
	set_Score(0);
	set_Level(0);
}

void Game_win::start_Game()
{
	
	set_Board(new Board());
	set_started(true);
	game_Loop();
}

void Game_win::game_Loop()
{
	bool endloop = false;
	Board* board_ptr = get_Board();
	UI::UI_console* ui_ptr = get_UI();
	std::string frame = "";
	clock_t start_time, end_time;
	float tick = 0.33f;
	while (!endloop)
	{
		for (int i = 0; i < 3; i++) 
		{
			start_time = clock();
			end_time = 0;
			while(((float)(end_time-start_time)/CLOCKS_PER_SEC) < tick)
			{
				Sleep(10);
				if (_kbhit())
				{
					char inputchar = (char)_getch();
					if (!process_Input(inputchar))
				    {
						endloop = true;
						break;
					}
					board_ptr->generate_Frame(frame);
					ui_ptr->print_Frame(frame);
				}
				end_time = clock();	
			}
			if (endloop) break;
		}
		board_ptr->system_Move();
		board_ptr->generate_Frame(frame);
		ui_ptr->print_Frame(frame);
	}
	end_Game();
}

bool Game_win::process_Input(char input)
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
				set_paused(true);
				if (get_UI()->pauseMenu()) 
				{
					set_paused(false);
				}
				else 
				{
					set_paused(false);
					return false;
				}
			}
			break;
		default:
			// no input
			break;
	}
	return true;
}

void Domain::Game_win::end_Game()
{
	set_started(false);
	UI::UI_console* ui_ptr = get_UI();
	if(get_game_Server()->check_hs(1000))
	{
		ui_ptr->hsMenu();
	}
	else 
	{
		std::cout << "No new highscore.\n";
		system("pause");
	}
}
