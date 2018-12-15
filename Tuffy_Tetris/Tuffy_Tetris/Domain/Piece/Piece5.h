/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Piece5.h
Purpose:	A concrete class for the Piece abstract type.
*******************************************************************************/

#ifndef PIECE5_H
#define PIECE5_H

#include "Piece.h"

namespace Domain
{

	class Piece5 : public Piece
	{
	public:
		Piece5(int x, int y);
		void init() override;
	};
}

#endif