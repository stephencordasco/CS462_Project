#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include "Piece.h"
#include "Piece1.h"
#include "Piece2.h"
#include "Piece3.h"
#include "Piece4.h"
#include "Piece5.h"
#include "Chunk.h"

using Domain::Piece;

namespace Domain
{
	class PieceFactory
	{
	public:
		static Piece* createPiece(int type, int x, int y);
	};
}

#endif