/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Chunk.cpp
Purpose:	Defines method implementations for the Chunk concrete class.
*******************************************************************************/

#include "Chunk.h"

using Domain::Chunk;

Chunk::Chunk(int x, int y) : Piece(x, y), chunk_points{} { }

void Domain::Chunk::set_points(bool * c_points)
{
	for (unsigned char i = 0; i < 21; i++) 
	{
		bool * row = &c_points[10 * i];
		for (int j = 0; j < 10; j++) 
		{
			chunk_points[i][j] = row[j];
		}
	}
}

bool * Domain::Chunk::get_points()
{
	return chunk_points[0];
}


void Chunk::init() 
{
	set_displaychar('O');
}