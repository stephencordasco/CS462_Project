/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Game_linux.h
Purpose:	Child class of Game class that declares member functions
			for use with Linux OS
*******************************************************************************/

#ifndef GAME_LINUX_H
#define GAME_LINUX_H

#include "../Game.h"
#include "../../../UI/UI_console.h"
#include "../../../UI/Windows/UI_console_win.h"

namespace Domain
{
	class Game_linux : public Game 
	{
	public:
		Game_linux(UI::UI_console*);
		void start_Game() override;
		void game_Loop() override;
		bool process_Input(char) override;
		void end_Game() override;
		int kbhit(void);
	private:
	};

}

#endif