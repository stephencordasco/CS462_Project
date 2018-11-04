/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece.cpp
Purpose:	Defines methods for Piece class.
*******************************************************************************/

#include "./Piece.h"

using Domain::Piece;

/*******************************************************************************
Name:		Piece
Parameters:	none
Purpose:	Default constructor for Piece class. Sets initial piece to type 1
			and initializes neccesary parameters.
*******************************************************************************/
Piece::Piece()
{
	type = 1;
	get_initial(piece1);
	gen_skirt();
	set_x(0);
	set_y(0);
}

/*******************************************************************************
Name:		Piece
Parameters:	Integer values for piece type, and absolute x and y coordinates.
Purpose:	Parameterized constructor for Piece class. Sets initial piece to type
			given in parameter and initializes neccesary parameters.
*******************************************************************************/
Piece::Piece(int t, int x, int y)
{
	type = t;
	//get value for initial piece state
	switch (t)
	{
	case 1:
		this->get_initial(piece1);
		break;
	case 2:
		this->get_initial(piece2);
		break;
	case 3:
		this->get_initial(piece3);
		break;
	case 4:
		this->get_initial(piece4);
		break;
	case 5:
		this->get_initial(piece5);
		break;
	}
	set_x(x);
	set_y(y);
	gen_skirt();
}

/*******************************************************************************
Name:		rotate
Parameters:	none
Purpose:	Performs a counter clock-wise rotation on a piece's points[4][4]
			array.
*******************************************************************************/
void Piece::rotate()
{
	//swap along diagonal X==Y then skip
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			if (i == j) continue;
			std::swap(points[i][j], points[j][i]);
		}
	}
	// swap R1 <-> R4, R2 <-> R3
	for (int i = 0; i < 4; i++)
	{
		std::swap(points[0][i], points[3][i]);
		std::swap(points[1][i], points[2][i]);
	}

	// get new skirt for rotated piece
	gen_skirt();
}

/*******************************************************************************
Name:		undo_rotate
Parameters:	none
Purpose:	Performs a clock-wise rotation on a piece's points[4][4]
			array to undo a previous rotation. Exactly opposite of rotate()
*******************************************************************************/
void Piece::undo_rot()
{
	// swap R1 <-> R4, R2 <-> R3
		std::swap(points[0], points[3]);
		std::swap(points[1], points[2]);
	
	//swap along diagonal X==Y then skip
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			if (i == j) continue;
			std::swap(points[i][j], points[j][i]);
		}
	}
	
	// get new skirt for rotated piece
	gen_skirt();

}

/*******************************************************************************
Name:		move_vert
Parameters:	Integer representing a piece move up or down:
			Positive value for down one, negative value or 0 for up one.
Purpose:	Moves the piece's position by up or down one in absolute coordinates.
*******************************************************************************/
void Piece::move_vert(int y)
{
	//set piece y coordinate one down if parameter is negative
	if (y < 0) set_y((get_y()+1));
	//otherwise set y coordinate up by one
	else set_y((get_y()-1));
}

/*******************************************************************************
Name:		move_horiz
Parameters:	Integer representing a piece move left or right:
			Positive value or 0 for right one, negative value for left one
Purpose:	Moves the piece's position by left or right one in absolute coordinates.
*******************************************************************************/
void Piece::move_horiz(int x)
{
	if (x < 0) set_x((get_x() - 1));
	else set_x((get_x() + 1));
}


/*******************************************************************************
Name:		gen_skirt
Parameters:	none
Purpose:	Generates a length 4 array representing the Y coordinate of the
			lowest enabled block in each piece column.
*******************************************************************************/
void Piece::gen_skirt()
{
	//initialize skirt array to all -1
	skirt[0] = -1; skirt[1] = -1; skirt[2] = -1; skirt[3] = -1;
	//for each x coordinate in points[], find the lowest y coord,
	//and add that y coord to skirt[]
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			if (skirt[i]<0 && points[j][i])
			{
				skirt[i] = j;
			}
		}

	}
}

/*******************************************************************************
Name:		gen_initial
Parameters:	Reference to a 4x4 boolean array. Represents the initial state of
			one of 5 tetris piece shapes.
Purpose:	Initializes the piece points[4][4] array to one of 5 preset tetris
			shapes.
*******************************************************************************/
void Piece::get_initial(bool(&piece)[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			points[i][j] = piece[i][j];
		}
	}
}

