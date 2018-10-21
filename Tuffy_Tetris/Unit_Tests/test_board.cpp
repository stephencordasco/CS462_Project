#pragma once

#include "../Tuffy_Tetris/Domain/Board/Board.h"
#include <string>

using Domain::Board;

namespace Test 
{

	inline void test_Board_Functions() 
	{
		Board test_board = Board();

		std::string test_output;

		test_board.generate_Frame(test_output);
	}
}