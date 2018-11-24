#include "Piece2.h"

using Domain::Piece2;

Piece2::Piece2(int x, int y) : Piece(x, y) { init(); }

/*******************************************************************************
Name:		init
Parameters:	Initializes a concrete piece of type 2 which is an "square" shaped piece.
Purpose:	Initializes the piece points[4][4] array to one of 5 preset tetris
			shapes. Also sets the display character for the piece.
*******************************************************************************/
void Piece2::init()
{
	set_displaychar('U');

	bool piece[4][4]{
			{ 0,0,0,0 },
			{ 0,1,1,0 },
			{ 0,1,1,0 },
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