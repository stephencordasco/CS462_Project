#include "Piece.h"

using Domain::Piece;

Piece::Piece()
{
	type = 1;
	get_initial(piece1);
	gen_skirt();
	set_x(0);
	set_y(0);
}

Piece::Piece(int t, int x, int y)
{
	type = t;
	//get value for initial piece state
	switch (t)
	{
	case 1:
		this->get_initial(piece1);
	case 2:
		this->get_initial(piece2);
	case 3:
		this->get_initial(piece3);
	case 4:
		this->get_initial(piece4);
	case 5:
		this->get_initial(piece5);
	}
	set_x(x);
	set_y(y);
	gen_skirt();
}


Piece::~Piece()
{
}

void Piece::rotate()
{
	//swap along diagonal X==Y then skip
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j) continue;
			std::swap(points[i][j], points[j][j]);
		}
	}
	// swap R1 <-> R4, R2 <-> R3
	for (int i = 0; i < 4; i++)
	{
		std::swap(points[i][0], points[i][3]);
		std::swap(points[i][1], points[i][2]);
	}

	// get new skirt for rotated piece
	gen_skirt();
}

void Piece::undo_rot()
{
}

void Piece::move_vert(int)
{
}

void Piece::move_horiz(int)
{
}

void Piece::gen_skirt()
{
	//for each x coordinate in points[], find the lowest y coord,
	//and add that y coord to skirt[]
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			if (points[i][j])
			{
				skirt[i] = j;
			}
		}

	}
}
// Properties
int Piece::get_x() { return abs_x; }
int Piece::get_y() { return abs_y; }

int Piece::get_type()
{
	return type;
}

int * Piece::get_skirt()
{
	return skirt;
}

void Piece::set_x(int x) { abs_x = x; }
void Piece::set_y(int y) { abs_y = y; }

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

