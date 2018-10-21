#pragma once

#include "../Tuffy_Tetris/Domain/Board/Board.h"
#include <string>
#include <iostream>
#include <functional>

using Domain::Board;

namespace Test 
{
	inline void test_move(bool (Board::*move_fun)(), Board& test_board) 
	{
		std::string test_output;

		(test_board.*move_fun)();

		test_board.generate_Frame(test_output);

		std::cout << test_output << std::endl << std::endl;
	}

	inline void test_Board_Functions() 
	{
		Board test_board = Board();

		test_move(&Board::move_Down, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::move_Down, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::rotate_Piece, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::move_Right, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);
		test_move(&Board::system_Move, test_board);

		

	}
}