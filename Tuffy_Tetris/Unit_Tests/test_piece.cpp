#pragma once

#include "../Tuffy_Tetris/Domain/Piece/Piece.h"
#include <string>
#include <iostream>

using Domain::Piece;

namespace Test
{
	std::string output_piece(Piece & input) 
	{
		std::string ostring;
		for (int i = 0; i < 4; i++) 
		{
			for (int j = 0; j < 4; j++) 
			{
				ostring += (input.get_points())[i][j];
				if (j == 3) ostring += "/n";
			}
		}
	}

	void test_Piece_Functions()
	{
		Piece test_piece = Piece(1, 0, 0);

		output_piece(test_piece);

		test_piece.rotate();

		output_piece(test_piece);

		test_piece.undo_rot();

		output_piece(test_piece);

		test_piece.gen_skirt();

		int * test_skirt = test_piece.get_skirt();

		for (int k = 0; k < 4; k++) 
		{
			std::cout << test_skirt[k] << std::endl;
		}
	}
	
}