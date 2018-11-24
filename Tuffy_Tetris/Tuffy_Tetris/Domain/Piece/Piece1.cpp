#include "Piece1.h"

using Domain::Piece1;

Piece1::Piece1(int x, int y) : Piece(x, y) { init(); }

/*******************************************************************************
Name:		init
Parameters:	Initializes a concrete piece of type 1 which is an "L" shaped piece.
Purpose:	Initializes the piece points[4][4] array to one of 5 preset tetris
			shapes. Also sets the display character for the piece.
*******************************************************************************/
void Piece1::init()
{
	set_displaychar('T');

	bool piece[4][4]{
	{ 0,1,0,0 },
	{ 0,1,0,0 },
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