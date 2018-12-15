/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		PieceFactory.cpp
Purpose:	Defines method implementations for the PieceFactory class.
*******************************************************************************/

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
		return new Chunk(x, y);
		break;
	default: 
		return new Piece1(x, y);
		break;
	}
	
}
