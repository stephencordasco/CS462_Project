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
		bool move_Down();
		bool move_Left();
		bool move_Right();
		bool rotate_Piece();
		bool system_Move();
	private:

		void init_board();
		void init_piece();
		void spawn_Piece(int type, int x_pos, int y_pos);
		bool draw_Piece_State();
		void draw_Board_State();
		bool validate_Move();
		// ASCII values for displaying letters in output
		// T U Y F F respectively
		int display_symbol[5] = { 84,85,121,70,70 };
		bool board_state[22][12];
		bool piece_state[22][12];
		bool update_frame;
		int type_count;
		Piece * current_piece;
	};

}