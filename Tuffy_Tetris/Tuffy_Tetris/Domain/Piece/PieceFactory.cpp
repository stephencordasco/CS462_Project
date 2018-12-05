#include "PieceFactory.h"

Piece* Domain::PieceFactory::createPiece(int type, int x, int y)
{
	switch(type) 
	{
	case(0):
		return new Piece1(x, y);
		break;
	case(1):
		return new Piece2(x, y);
		break;
	case(2):
		return new Piece3(x, y);
		break;
	case(3):
		return new Piece4(x, y);
		break;
	case(4):
		return new Piece5(x, y);
		break;
	case(5):
		return new newPiece(x, y);
		break;
	case(6):
		return new Chunk(x, y);
		break;
	default: 
		return new Piece1(x, y);
		break;
	}
	
}
