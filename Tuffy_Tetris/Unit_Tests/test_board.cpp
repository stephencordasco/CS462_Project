
#include "../Tuffy_Tetris/Domain/Board/Board.h"
#include <string>

using Domain::Board;

namespace Test 
{

	void test_Board_Functions() 
	{
		Board test_board = Board();

		test_board.spawn_Piece(1, 0, 0);

		std::string test_output;

		test_board.generate_Frame(test_output);
	}
}