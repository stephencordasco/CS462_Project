#pragma once

#include "./Board.h"
#include <string>

using Domain::Board;

Board::Board()
{
}


Board::~Board()
{
	delete current_piece;
}

//iterate over the board_state and piece_state and see if either are on, 
//then write both to a long string
bool Board::generate_Frame(std::string & output)
{	//check if frame needs to be updated, if not, simply return false.
	if (update_frame == true)
	{
		output.clear();
		for (int i = 0; i < 20; i++) //iterate over length
		{
			for (int j = 0; j < 10; j++) //iterate over width 
			{
				if (board_state[i][j])
				{
					output += "X";
				}
				else if (piece_state[i][j])
				{
					//output the character corresponding to the piece type
					output += (char)(display_symbol[current_piece->get_type()]);
				}
				else
				{
					output += ".";
				}
			}
			output += "\n"; //add newline every Y coord
		}
		update_frame = false;
		return true;
	}
	else return false;
}

void Board::spawn_Piece(int type, int x, int y)
{
	current_piece = new Piece(type, x, y);
}

void Board::draw_Piece()
{
	//call validate state to check piece

	//if valid, "draw" piece state and undo state
}

void Board::validate_Move()
{
}
