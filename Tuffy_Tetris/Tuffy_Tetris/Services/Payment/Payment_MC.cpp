/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Payment_MC.cpp
Purpose:	Defines functionality for Payment_MC concrete class.
*******************************************************************************/

#include "Payment_MC.h"

using Services::Payment_MC;

Payment_MC::Payment_MC()
{

}

bool Payment_MC::acceptCardInfo(std::string cardNumber, std::string accountHolder, std::string securityNumber, std::string expirationDate, std::string billingAddress, std::string zipCode)
{
	return true;
}

void Payment_MC::printToLogger(std::string message)
{
	_logger << message;
}