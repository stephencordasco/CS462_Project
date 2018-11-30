/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece.h
Purpose:	Declares class for a game piece. Contains properties and low level
			methods for manipulating a piece object on a Board.
*******************************************************************************/

#ifndef PIECE_H

#define PIECE_H

#include <algorithm>

namespace Domain
{

	class Piece
	{
	public:
		Piece();
		Piece(int x, int y);
		void rotate();
		void undo_rot();
		void move_vert(int y);
		void move_horiz(int x);
		//generate skirt array
		void gen_skirt();
		virtual void init() = 0;

		//trivial properties
		int get_x() { return abs_x; }
		int get_y() { return abs_y; }
		bool * get_points() { return points[0]; }
		int * get_skirt() { return skirt; }
		void set_x(int x) { abs_x = x; }
		void set_y(int y) { abs_y = y; }
		void set_displaychar(char c) { displaychar = c; }
		char get_displaychar() { return displaychar; }
		//

	private:
		bool points[4][4];

		int abs_x;
		int abs_y;
		int skirt[4];
		char displaychar;
	};

}

#endif