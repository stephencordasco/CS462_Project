#ifndef CHUNK_H
#define CHUNK_H

#include "Piece.h"

namespace Domain
{

	class Chunk : public Piece
	{
	public:
		Chunk(int x, int y);
		void Piece::init();
		void set_points(bool* points);
		bool* get_points() override;
	private:
		bool chunk_points[21][10];
	};
}

#endif
