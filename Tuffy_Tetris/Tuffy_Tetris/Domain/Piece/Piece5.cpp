/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece5.cpp
Purpose:	Defines method implementations for the Piece5 concrete class.
*******************************************************************************/

#include "Piece5.h"

using Domain::Piece5;

Piece5::Piece5(int x, int y) : Piece(x, y) { init(); }

/*******************************************************************************
Name:		init
Parameters:	Initializes a concrete piece of type 5 which is an "S" shaped piece.
Purpose:	Initializes the piece points[4][4] array to one of 5 preset tetris
			shapes. Also sets the display character for the piece.
*******************************************************************************/
void Piece5::init()
{
	set_displaychar('F');

	bool piece[4][4]{
		{ 0,0,0,0 },
		{ 0,1,1,0 },
		{ 1,1,0,0 },
		{ 0,0,0,0 } };

	bool* ptr = get_points();
	for (int i = 0; i < 4; i++)
	{
		bool* row = &ptr[4 * i];
		for (int j = 0; j < 4; j++)
		{
			row[j] = piece[i][j];
		}
	}
}