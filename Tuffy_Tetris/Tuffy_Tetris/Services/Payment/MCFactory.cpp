/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		MCFactory.cpp
Purpose:	Defines functionality for MCFactory concrete factory class.
*******************************************************************************/

#include "MCFactory.h"

using Services::Payment_MC;

Payment_MC * Services::MCFactory::createPayment()
{
	return new Payment_MC();
}
