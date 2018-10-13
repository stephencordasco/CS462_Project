#pragma once
class Piece
{
public:
	Piece(int);
	~Piece();
	void rotate();
	int* get_skirt();
	int get_x();
	int get_y();
	void set_x();
	void set_y();
private:
	int type;
	bool points[4][4];
	void get_initial(bool[4][4]);
	int abs_x;
	int abs_y;
	int * skirt;
};

