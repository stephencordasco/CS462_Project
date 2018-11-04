/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Game.cpp
Purpose:	Defines methods for the abstract Game class.
*******************************************************************************/

#include "Game.h"

Domain::Game::Game(UI::UI_console * ui) : game_UI(ui), level(0), score(0), game_paused(false)
, game_started(false), game_Board(nullptr), game_Server(nullptr) {}

Domain::Game::~Game()
{
	if(game_Board) delete game_Board;
}
