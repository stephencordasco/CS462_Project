#pragma once

#include <algorithm>

namespace Domain
{

	class Piece
	{
	public:
		Piece();
		Piece(int t, int x, int y);
		~Piece();
		void rotate();
		void undo_rot();
		void move_vert(int y);
		void move_horiz(int x);
		//generate skirt array
		void gen_skirt();
		int get_x();
		int get_y();
		int get_type();
		int * get_skirt();
		void set_x(int x);
		void set_y(int y);
	private:
		int type;
		bool points[4][4];
		bool last_rot[4][4];
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