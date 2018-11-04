/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Game_linux.cpp
Purpose:	defines member functions for Game_linux class
*******************************************************************************/


#ifndef _WIN32

#include "./Game_linux.h"
#include <iostream>


using Domain::Game_linux;


Game_linux::Game_linux(UI::UI_console * ui) : Game(ui)
{
	set_Score(0);
	set_Level(0);
}

/*******************************************************************************
Name:		kbhit
Parameters:	none
Purpose:	Provides the same functionality as <conio.h> _kbhit(). Returns true
			if at least one character is in the input buffer and returns false
			otherwise.

//code for this function used from StackOverFlow by user: Matthew Slattery
//retrieved from URL:
https://stackoverflow.com/questions/4025891/create-a-function-to-check-for-key-press-in-unix-using-ncurses?rq=1
*******************************************************************************/
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

/*******************************************************************************
Name:		start_Game
Parameters:	none
Purpose:	Creates a new Board class instance, initalizes started variable, and
			begins the game_Loop method.
*******************************************************************************/
void Game_linux::start_Game()
{

	set_Board(new Board());
	set_started(true);
	game_Loop();
}

/*******************************************************************************
Name:		game_Loop
Parameters:	none
Purpose:	This is where the main game logic runs. User input is captured and
			processed, the board object is sent move commands, and then the
			resulting frames are sent to the UI for printing.
*******************************************************************************/
void Game_linux::game_Loop()
{
	bool endloop = false;
	Board* board_ptr = get_Board();
	UI::UI_console* ui_ptr = get_UI();
	std::string frame = "";
	clock_t start_time, end_time;
	//tick is the base time unit for the loop
	float tick = 0.1f;
	//loop while game is not over
	while (!endloop)
	{
		//ncurses initializer functions, sets non blocking input and more
		initscr();
		cbreak();
		noecho();
		nodelay(stdscr, TRUE);
		scrollok(stdscr, TRUE);
		for (int i = 0; i < 3; i++)
		{
			start_time = clock();
			end_time = 0;
			double time_elapsed = 0.0f;
			//loop while one tick has not elapsed
			while (time_elapsed <= tick)
			{
				//check for keyboard input
				if (kbhit())
				{
					//get a character from the input buffer
					char inputchar = getch();
					//process the input character and call appropriate
					//ui or board functions. break if user selected quit
					if (!process_Input(inputchar))
					{
						//endwin ends ncurses modes/window
						endwin();
						endloop = true;
						break;
					}
					endwin();
					//generate and print an output screen frame
					board_ptr->generate_Frame(frame);
					ui_ptr->print_Frame(frame);
				}
				end_time = clock();
				//find out how much time has elapsed in fractional seconds
				time_elapsed = static_cast<double>(end_time - start_time) / 
					static_cast<double>(CLOCKS_PER_SEC);
			}
			if (endloop) break;
		}
		endwin();
		//do a system move after checking for user input 3 times
		//system move moves piece down one
		board_ptr->system_Move();
		//generate and print an output screen frame
		board_ptr->generate_Frame(frame);
		ui_ptr->print_Frame(frame);
	}
	end_Game();
}

/*******************************************************************************
Name:		process_Input
Parameters:	char input : an input character typed by the user and sent for
			processing.
Purpose:	Checks for specific input keypresses and calls the corresponding
			Board or UI functions. Returns false if user initiates game
			exit command.
*******************************************************************************/
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

/*******************************************************************************
Name:		end_Game()
Parameters:	none
Purpose:	Handles end game functionality. Function called when user quits or
			game is over. Calls check_hs function to check if user score is a
			highscore.
*******************************************************************************/
void Domain::Game_linux::end_Game()
{
	set_started(false);
	UI::UI_console* ui_ptr = get_UI();
	//temporary set score to test score stub
	set_Score(1000);
	//check if current game score is higher than user's highest previous score
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

#endif // !_WIN32