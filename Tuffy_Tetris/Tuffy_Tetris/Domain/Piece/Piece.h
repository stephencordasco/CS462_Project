/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece.h
Purpose:	Declares class for a game piece. Contains properties and low level
			methods for manipulating a piece object on a Board.
*******************************************************************************/

#pragma once

#include <algorithm>

namespace Domain
{

	class Piece
	{
	public:
		Piece();
		Piece(int t, int x, int y);
		void rotate();
		void undo_rot();
		void move_vert(int y);
		void move_horiz(int x);
		//generate skirt array
		void gen_skirt();

		//trivial properties
		int get_x() { return abs_x; }
		int get_y() { return abs_y; }
		int get_type() { return type; }
		bool * get_points() { return points[0]; }
		int * get_skirt() { return skirt; }
		void set_x(int x) { abs_x = x; }
		void set_y(int y) { abs_y = y; }
		//

	private:
		int type;
		bool points[4][4];
		void get_initial(bool(&)[4][4]);
		int abs_x;
		int abs_y;
		int skirt[4];

		// "L" shaped piece
		bool piece1[4][4]{
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 0,1,1,0 },
			{ 0,0,0,0 } };

		// "square" shaped piece
		bool piece2[4][4]{
			{ 0,0,0,0 },
			{ 0,1,1,0 },
			{ 0,1,1,0 },
			{ 0,0,0,0 } };

		// "bar" shaped piece
		bool piece3[4][4]{
			{ 0,0,0,0 },
			{ 1,1,1,1 },
			{ 0,0,0,0 },
			{ 0,0,0,0 } };

		// "z" shaped piece
		bool piece4[4][4]{
			{ 0,0,0,0 },
			{ 0,1,1,0 },
			{ 0,0,1,1 },
			{ 0,0,0,0 } };

		// "s" shaped piece
		bool piece5[4][4]{
			{ 0,0,0,0 },
			{ 0,1,1,0 },
			{ 1,1,0,0 },
			{ 0,0,0,0 } };
	};

}