

#include "newPiece.h";

Domain::newPiece::newPiece(int x, int y) : Piece(x, y) { init(); }

void Domain::newPiece::init() 
{
	set_displaychar('N');

	bool piece[4][4]{
		{ 1,0,0,0 },
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 } };

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