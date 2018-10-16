#pragma once

#include "../Piece/Piece.h"
#include <string>

namespace Domain
{

	class Board
	{
	public:
		Board();
		~Board();
		bool generate_Frame(std::string & output);
		void spawn_Piece(int type, int x_pos, int y_pos);
		void draw_Piece();
		void validate_Move();
	private:
		// ASCII values for displaying letters in output
		// T U Y F F respectively
		int display_symbol[5] = { 84,85,121,70,70 };

		bool board_state[10][20];
		bool piece_state[10][20];
		bool update_frame;
		Piece * current_piece;
	};

}