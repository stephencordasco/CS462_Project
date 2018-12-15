/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Chunk.h
Purpose:	A concrete class for the Piece abstract type represents a chunk of
			blocks that move down after rows are cleared from the board.
*******************************************************************************/

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
