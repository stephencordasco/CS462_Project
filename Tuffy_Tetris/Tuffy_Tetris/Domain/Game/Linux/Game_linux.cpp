#pragma once

#include "./Game_linux.h"
#include <iostream>


using Domain::Game_linux;


//code for this function used from StackOverFlow by user: Matthew Slattery
//retrieved from URL:  https://stackoverflow.com/questions/4025891/create-a-function-to-check-for-key-press-in-unix-using-ncurses?rq=1
int Game_linux::kbhit(void)
{
	int ch = getch();

	if (ch != ERR) {
		ungetch(ch);
		return 1;
	}
	else {
		return 0;
	}
}

Game_linux::Game_linux(UI::UI_console * ui) : Game(ui)
{
	set_Score(0);
	set_Level(0);
}

void Game_linux::start_Game()
{

	set_Board(new Board());
	set_started(true);
	game_Loop();
}

void Game_linux::game_Loop()
{
	bool endloop = false;
	Board* board_ptr = get_Board();
	UI::UI_console* ui_ptr = get_UI();
	std::string frame = "";
	clock_t start_time, end_time;
	float tick = 0.33f;
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	scrollok(stdscr, TRUE);
	while (!endloop)
	{
		for (int i = 0; i < 3; i++)
		{
			start_time = clock();
			end_time = 0;
			while (((float)(end_time - start_time) / CLOCKS_PER_SEC) < tick)
			{
				usleep(10000);
				if (kbhit())
				{
					char inputchar = (char)getch();
					if (!process_Input(inputchar))
					{
						endwin();
						endloop = true;
						break;
					}
					endwin();
					board_ptr->generate_Frame(frame);
					ui_ptr->print_Frame(frame);
				}
				endwin();
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

bool Game_linux::process_Input(char input)
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

void Domain::Game_linux::end_Game()
{
	set_started(false);
	UI::UI_console* ui_ptr = get_UI();
	set_Score(1000);
	if (get_game_Server()->check_hs(get_Score()))
	{
		ui_ptr->hsMenu();
	}
	else
	{
		std::cout << "No new highscore.\n";
		std::cout << "Press enter to continue...";
		std::cin.get();
	}
}
