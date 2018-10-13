#pragma once
class Board
{
public:
	Board();
	~Board();
private:
	bool board_state[7][10];
	bool piece_state[7][10];
	bool undo_state[7][10];
};

