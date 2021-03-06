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

#ifndef BOARD_H
#define BOARD_H

#include "../Piece/Piece.h"
#include "../Piece/PieceFactory.h"
#include <string>
#include <vector>
#include <random>
#include <list>

namespace Domain
{

	class Board
	{
	public:
		Board();
		~Board();
		bool generate_Frame(std::string & output);
		bool move_Down();
		bool move_Chunk_Down();
		bool move_Left();
		bool move_Right();
		bool rotate_Piece();
		bool system_Move();
		void checkFullRow();
		void clearRow(int row);

	private:

		void init_board();
		void init_piece();
		void spawn_Piece(int type, int x_pos, int y_pos);
		bool draw_Piece_State();
		bool draw_Chunk_State();
		void draw_Board_State();
		bool validate_Move();
		bool board_state[22][12];
		bool piece_state[22][12];
		bool chunk_state[21][10];
		bool update_frame;
		std::default_random_engine rand_piece;
		std::uniform_int_distribution<int> dist_piece;
		Piece * current_piece;
	};

}

#endif