/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece2.h
Purpose:	A concrete class for the Piece abstract type.
*******************************************************************************/

#ifndef PIECE2_H
#define PIECE2_H

#include "Piece.h"

namespace Domain
{

	class Piece2 : public Piece
	{
	public:
		Piece2(int x, int y);
		void Piece::init();
	};
}
#endif