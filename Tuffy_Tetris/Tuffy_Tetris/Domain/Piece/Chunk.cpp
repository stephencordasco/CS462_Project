
#include "Chunk.h"

using Domain::Chunk;

Chunk::Chunk(int x, int y) : Piece(x, y) { }

void Domain::Chunk::set_points(bool * points)
{
	for (unsigned char i = 0; i < 21; i++) 
	{
		bool * row = &points[10 * i];
		for (int j = 0; j < 10; j++) 
		{
			chunk_points[i][j] = row[j];
		}
	}
}

bool * Domain::Chunk::get_points()
{
	return chunk_points[0];
}


void Chunk::init() 
{
	set_displaychar('O');
}