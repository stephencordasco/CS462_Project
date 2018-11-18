/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Board.cpp
Purpose:	Defines method implementations for the Board class.
*******************************************************************************/

#include "./Board.h"
#include <iostream>
#include <string>
#include <list>

using Domain::Board;

/*******************************************************************************
Name:		Board
Parameters:	none
Purpose:	Default constructor for Board class. Sets various properties to
			default values and calls board initialization function.
*******************************************************************************/
Board::Board() : board_state{}, piece_state{}
{
	type_count = 0;
	update_frame = false;
	current_piece = nullptr;
	//initialize board state
	init_board();
}


Board::~Board()
{
	if(current_piece)
	delete current_piece;
}

/*******************************************************************************
Name:		generate_Frame
Parameters:	string object reference for logical data frame output
Purpose:	Checks if a new frame needs to be generated due to Board or Piece
			state change. Then, if true, the method clears the output string,
			and writes a new string to represent board and piece states. Otherwise
			the method returns the original string.
*******************************************************************************/
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
					output += static_cast<char>(display_symbol[current_piece->get_type()-1]);
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

/*******************************************************************************
Name:		spawn_Piece
Parameters:	Integers representing Piece type, and absolute x and y coordinates
			for a Piece.
Purpose:	Creates a new piece of a specific type at a specific x and y
			coordinate. If the type value is less than 0, method will reference
			the type_count property and print the next Piece type in order.
*******************************************************************************/
void Board::spawn_Piece(int type, int x, int y)
{
	int type_holder = type;

	//setting a type < 0 will use type_count value to cycle each piece in order
	if (type_holder < 0)
	{
		//increment piece type_count to cycle through each piece type in order
		type_holder = type_count+1;
	}
	type_count = (type_count + 1) % 5;
	current_piece = new Piece(type_holder, x, y);
	//draw new piece_state
	draw_Piece_State();
}

/*******************************************************************************
Name:		draw_Board_State
Parameters:	none
Purpose:	Method simply updates the board_state after any change in piece or
			board state.
*******************************************************************************/
void Board::draw_Board_State() 
{
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			board_state[i][j] = board_state[i][j] || piece_state[i][j];
		}
	}
	//set update flag to generate an updated frame on request
	update_frame = true;
}

/*******************************************************************************
Name:		draw_Piece_State
Parameters:	none
Purpose:	Updates the piece_state array, and checks that the piece is inside
			the Board boundaries. If any part of the piece is out of founds, the
			method returns false to indicate failure. Otherwise return true.
*******************************************************************************/
bool Board::draw_Piece_State()
{
	init_piece();
	int abs_x = current_piece->get_x();
	int abs_y = current_piece->get_y();

	for (unsigned char i = 0; i < 4; i++) 
	{
		bool * row = &((current_piece->get_points())[4 * i]);
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

/*******************************************************************************
Name:		validate_Move
Parameters:	none
Purpose:	Method confirms that the current piece_state does not collide with
			a piece already on the Board. If piece_state collides with board_state
			then return false to indicate failure. Otherwise return true.
*******************************************************************************/
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

/*******************************************************************************
Name:		move_Down
Parameters:	none
Purpose:	Method attempts a Piece movement down by one. Performs move, and checks
			whether the new state collides with Board boundaries or other pieces
			already on the board. If so, the movement is reversed and method
			returns false. Otherwise method keeps move and returns true.
*******************************************************************************/
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

/*******************************************************************************
Name:		move_Left
Parameters:	none
Purpose:	Method attempts a Piece movement left by one. Performs move, and checks
			whether the new state collides with Board boundaries or other pieces
			already on the board. If so, the movement is reversed and method
			returns false. Otherwise method keeps move and returns true.
*******************************************************************************/
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

/*******************************************************************************
Name:		move_Right
Parameters:	none
Purpose:	Method attempts a Piece movement right by one. Performs move, and checks
			whether the new state collides with Board boundaries or other pieces
			already on the board. If so, the movement is reversed and method
			returns false. Otherwise method keeps move and returns true.
*******************************************************************************/
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

/*******************************************************************************
Name:		rotate_Piece
Parameters:	none
Purpose:	Method attempts a Piece rotation counter-clockwise. Performs move,
			and checks whether the new state collides with Board boundaries or
			other pieces already on the board. If so, the movement is reversed
			and method returns false. Otherwise method keeps move and returns true.
*******************************************************************************/
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

/*******************************************************************************
Name:		system_Move
Parameters:	none
Purpose:	Method attempts a Piece movement down one. Represents the default
			movement that occurs in tetris every few game ticks. If this movement
			fails, then the piece state is "baked" onto the game state, and a new
			Piece is spawned. See move_Down documentation.
*******************************************************************************/
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

/*******************************************************************************
Name:		init_board
Parameters:	none
Purpose:	Method sets the initial state of the board and piece states. Draws a
			border of turned on blocks along the sides and bottom of the Board.
*******************************************************************************/
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

/*******************************************************************************
Name:		init_piece
Parameters:	none
Purpose:	Similar to init_board, but only initializes the state of a new piece.
*******************************************************************************/
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

// TODO -- under construction --
void Board::checkFullRow()
{
	// count the number of true spaces in a row
	int count = 0;
	// vector to store indices of the row to clear
	std::list<int> indices;

	for (int i = 1; i < 21; i++)
	{
		count = 0;
		for (int j = 1; j < 11; j++)
		{
			if (board_state[i][j])
			{
				count++;
			}
		}
		// check if the row is true (full)
		if (count == 10)
		{
			indices.push_back(i);
		}
	}
	// get index of all rows to clear
	// clear rows of given index
	for (auto v : indices)
	{
		if (!indices.empty())
		{
			std::cout << "Row: " << v << "\n";
		}
	} 
}

void Board::clearRow()
{

}