#pragma once

#include "../Tuffy_Tetris/Domain/Piece/Piece.h"
#include <string>
#include <iostream>

using Domain::Piece;

namespace Test
{
	//rough function for printing piece without using board class
	inline std::string output_piece(Piece & input) 
	{
		std::string ostring;
		for (int i = 0; i < 4; i++) 
		{
			bool * row = (input.get_points())+(4*i);
			for (int j = 0; j < 4; j++) 
			{
				bool val = row[j];
				if (val == true) ostring += 'X';
				else ostring += "_";
				if (j == 3) ostring += "\n";
			}
		}
		return ostring;
	}

	//tests the skirt function
	inline void test_skirt_fun(Piece& test) 
	{
		test.gen_skirt();

		int * test_skirt = test.get_skirt();

		std::cout << "Skirt: ";

		for (int k = 0; k < 4; k++)
		{
			std::cout << test_skirt[k] << ", ";
		}
		std::cout << std::endl;
	}

	//test routine, tests all piece functions on each type of piece
	inline void test_Piece_Functions()
	{

		for (int i = 1; i < 6; i++)
		{
			Piece test_piece = Piece(i, 0, 0);

			std::cout << "Default piece: \n";

			std::cout << output_piece(test_piece);

			test_skirt_fun(test_piece);

			std::cout << "Rotated: \n";

			test_piece.rotate();

			std::cout << output_piece(test_piece);

			test_skirt_fun(test_piece);

			std::cout << "Undo rot: \n";
			
			test_piece.undo_rot();

			std::cout << output_piece(test_piece);

			test_skirt_fun(test_piece);

			std::cout << "Default x and y: \n";

			std::cout << "( " << test_piece.get_x() << ", " << test_piece.get_y() << " )" << std::endl;

			std::cout << "X and Y after setting: \n";

			test_piece.set_x(3);
			test_piece.set_y(3);

			std::cout << "( " << test_piece.get_x() << ", " << test_piece.get_y() << " )" << std::endl;


		}
	}
	
}