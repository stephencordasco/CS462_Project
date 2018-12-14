/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console_linux.h
Purpose:	child class of UI_console declares member functions and member
			variables for Linux OS
*******************************************************************************/
#include "../Services/Payment_MC.h"

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