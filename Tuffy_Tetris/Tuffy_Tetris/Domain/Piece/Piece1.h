/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece1.h
Purpose:	A concrete class for the Piece abstract type.
*******************************************************************************/

#ifndef PIECE1_H
#define PIECE1_H

#include "Piece.h"

namespace Domain
{

	class Piece1 : public Piece
	{
	public:
		Piece1(int x, int y);
		void init() override;
	};
}

#endif