#include "Piece4.h"

using Domain::Piece4;

Piece4::Piece4(int x, int y) : Piece(x, y) { init(); }

/*******************************************************************************
Name:		init
Parameters:	Initializes a concrete piece of type 4 which is an "Z" shaped piece.
Purpose:	Initializes the piece points[4][4] array to one of 5 preset tetris
			shapes. Also sets the display character for the piece.
*******************************************************************************/
void Piece4::init()
{
	set_displaychar('F');

	bool piece[4][4]{
		{ 0,0,0,0 },
		{ 0,1,1,0 },
		{ 0,0,1,1 },
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