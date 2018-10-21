#pragma once

#include "./Piece.h"

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


Piece::~Piece()
{
}

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

//increment or decrement y by 1 (0,0) is top left, 
//positive value for down one, negative value or 0 for up one
void Piece::move_vert(int y)
{

	if (y < 0) set_y((get_y()+1));
	else set_y((get_y()-1));
}

//increment or decrement x by 1 (0, 0) is top left,
//positive value or 0 for right one, negative value for left one
void Piece::move_horiz(int x)
{
	if (x < 0) set_x((get_x() - 1));
	else set_x((get_x() + 1));
}

void Piece::gen_skirt()
{
	//for each x coordinate in points[], find the lowest y coord,
	//and add that y coord to skirt[]
	skirt[0] = -1; skirt[1] = -1; skirt[2] = -1; skirt[3] = -1;
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
// Properties
int Piece::get_x() { return abs_x; }
int Piece::get_y() { return abs_y; }

int Piece::get_type()
{
	return type;
}

bool * Domain::Piece::get_points()
{
	return points[0];
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

