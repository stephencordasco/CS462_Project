#pragma once

#include "./Board.h"
#include <string>

using Domain::Board;

Board::Board()
{
	type_count = 0;
	update_frame = false;
	current_piece = nullptr;
	init_board();
}


Board::~Board()
{
	if(current_piece)
	delete current_piece;
}

//iterate over the board_state and piece_state and see if either are on, 
//then write both to a long string
bool Board::generate_Frame(std::string & output)
{	//check if frame needs to be updated, if not, simply return false.
	if (update_frame == true)
	{
		output.clear();
		for (int i = 0; i < 21; i++) //iterate over length
		{
			for (int j = 1; j < 11; j++) //iterate over width 
			{
				if (piece_state[i][j])
				{
					//output the character corresponding to the piece type
					output += (char)(display_symbol[current_piece->get_type()-1]);
				}
				else if (board_state[i][j])
				{
					output += "X";
				}
				else
				{
					output += "-";
				}
			}
			output += "\n"; //add newline every Y coord
		}
		update_frame = false;
		return true;
	}
	else return false;
}

//setting a type < 0 will use type_count value to cycle each piece in order
void Board::spawn_Piece(int type, int x, int y)
{
	int type_holder = type;
	if (type_holder < 0)
	{
		//increment piece type_count to cycle through each piece type in order
		type_holder = type_count+1;
	}
	type_count = (type_count + 1) % 5;
	current_piece = new Piece(type_holder, x, y);
	draw_Piece_State();
}

void Board::draw_Board_State() 
{
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			board_state[i][j] = board_state[i][j] || piece_state[i][j];
		}
	}
	update_frame = true;
}

//draw piece onto board if it cannot move down anymore
bool Board::draw_Piece_State()
{
	init_piece();
	int abs_x = current_piece->get_x();
	int abs_y = current_piece->get_y();

	for (int i = 0; i < 4; i++) 
	{
		bool * row = (current_piece->get_points()) + (4 * i);
		for (int j = 0; j < 4; j++) 
		{
			// if the value in piece array is true, and out of bounds in x or y 
			if (row[j] && ((j + abs_x > 10 || j + abs_x < 1) || (i + abs_y > 20)))
				return false;
			//otherwise draw the point
			else 
			{
				piece_state[abs_y + i][abs_x + j] = row[j];
			}
		}
	}
	update_frame = true;
	return true;
}

// validate move by comparing with board_state
bool Board::validate_Move()
{
	for (int i = 0; i < 21; i++) 
	{
		for (int j = 1; j < 11; j++) 
		{
			if (board_state[i][j] && piece_state[i][j]) 
			{
				return false;
			}
		}
	}
	return true;
}

bool Domain::Board::move_Down()
{
	current_piece->move_vert(-1);

	if ((!draw_Piece_State() || !validate_Move())) 
	{
		current_piece->move_vert(1);
		draw_Piece_State();
		return false;
	}
	return true;
}

bool Domain::Board::move_Left()
{
	current_piece->move_horiz(-1);

	if ((!draw_Piece_State() || !validate_Move()))
	{
		current_piece->move_horiz(1);
		draw_Piece_State();
		return false;
	}
	return true;
}

bool Domain::Board::move_Right()
{
	current_piece->move_horiz(1);

	if ((!draw_Piece_State() || !validate_Move()))
	{
		current_piece->move_horiz(-1);
		draw_Piece_State();
		return false;
	}
	return true;
}

bool Domain::Board::rotate_Piece()
{
	current_piece->rotate();

	if ((!draw_Piece_State() || !validate_Move()))
	{
		current_piece->undo_rot();
		draw_Piece_State();
		return false;
	}
	return true;
}

bool Domain::Board::system_Move()
{
	current_piece->move_vert(-1);

	if ((!draw_Piece_State() || !validate_Move()))
	{
		current_piece->move_vert(1);
		draw_Piece_State();
		draw_Board_State();
		init_piece();
		spawn_Piece(-1, 5, 0);
		return false;
	}
	return false;
}

void Domain::Board::init_board()
{	
	update_frame = true;
	//initialize all false
	for (int i = 0; i < 22; i++) 
	{
		for (int j = 0; j < 12; j++) 
		{
			board_state[i][j] = false;
			piece_state[i][j] = false;
		}
	}
	//initialize bottom rows in both states
	for (int i = 0; i < 12; i++) 
	{
		board_state[21][i] = true;
		piece_state[21][i] = true;
	}
	//initialize first and last columns in both states
	for (int i = 0; i < 22; i++) 
	{
		board_state[i][0] = true;
		board_state[i][11] = true;
		piece_state[i][0] = true;
		piece_state[i][11] = true;
	}

	init_piece();
	spawn_Piece(1, 5, 0);

}

void Domain::Board::init_piece() 
{
	//initialize all false
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			piece_state[i][j] = false;
		}
	}
	//initialize bottom row
	for (int i = 0; i < 12; i++)
	{
		piece_state[21][i] = true;
	}
	//initialize first and last columns
	for (int i = 0; i < 22; i++)
	{
		piece_state[i][0] = true;
		piece_state[i][11] = true;
	}

}
