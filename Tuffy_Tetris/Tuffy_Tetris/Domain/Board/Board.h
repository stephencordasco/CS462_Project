/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Board.h
Purpose:	Declares properties and methods for the Board class. The Board class
			handles control of a Piece object, manages Board and Piece states,
			and validates moves based on predefined game rules. Also generates
			logical data frames for output.
*******************************************************************************/

#pragma once

#include "../Piece/Piece.h"
#include <string>

namespace Domain
{

	class Board
	{
	public:
		Board();
		~Board();
		bool generate_Frame(std::string & output);
		bool move_Down();
		bool move_Left();
		bool move_Right();
		bool rotate_Piece();
		bool system_Move();
		// TODO -- under construction --
		void checkFullRow();
		void clearRow();

	private:

		void init_board();
		void init_piece();
		void spawn_Piece(int type, int x_pos, int y_pos);
		bool draw_Piece_State();
		void draw_Board_State();
		bool validate_Move();
		// ASCII values for displaying letters in output
		// T U Y F F respectively
		int display_symbol[5] = { 84,85,89,70,70 };
		bool board_state[22][12];
		bool piece_state[22][12];
		bool update_frame;
		int type_count;
		Piece * current_piece;
	};

}