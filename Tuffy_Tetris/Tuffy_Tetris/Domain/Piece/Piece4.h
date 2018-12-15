/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece4.h
Purpose:	A concrete class for the Piece abstract type.
*******************************************************************************/

#ifndef PIECE4_H
#define PIECE4_H

#include "Piece.h"

namespace Domain
{

	class Piece4 : public Piece
	{
	public:
		Piece4(int x, int y);
		void init() override;
	};
}

#endif