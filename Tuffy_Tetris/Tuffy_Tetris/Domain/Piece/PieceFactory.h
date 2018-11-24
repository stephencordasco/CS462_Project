#pragma once
#include "Piece.h"
#include "Piece1.h"
#include "Piece2.h"
#include "Piece3.h"
#include "Piece4.h"
#include "Piece5.h"

using Domain::Piece;

namespace Domain
{
	class PieceFactory
	{
	public:
		static Piece* createPiece(int type, int x, int y);
	};
}