/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece3.h
Purpose:	A concrete class for the Piece abstract type.
*******************************************************************************/

#ifndef PIECE3_H
#define PIECE3_H

#include "Piece.h"

namespace Domain
{

	class Piece3 : public Piece
	{
	public:
		Piece3(int x, int y);
		void init() override;
	};
}

#endif
