/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		VISAFactory.cpp
Purpose:	Defines functionality for VISAFactory concrete factory class.
*******************************************************************************/


#include "VISAFactory.h"

using Services::Payment_VISA;

Payment_VISA * Services::VISAFactory::createPayment()
{
	return new Payment_VISA();
}
