/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece3.cpp
Purpose:	Defines method implementations for the Piece3 concrete class.
*******************************************************************************/

#include "Piece3.h"

using Domain::Piece3;

Piece3::Piece3(int x, int y) : Piece(x, y) { init(); }

/*******************************************************************************
Name:		init
Parameters:	Initializes a concrete piece of type 3 which is an "bar" shaped piece.
Purpose:	Initializes the piece points[4][4] array to one of 5 preset tetris
			shapes. Also sets the display character for the piece.
*******************************************************************************/
void Piece3::init()
{
	set_displaychar('Y');

	bool piece[4][4]{
		{ 0,0,0,0 },
		{ 1,1,1,1 },
		{ 0,0,0,0 },
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