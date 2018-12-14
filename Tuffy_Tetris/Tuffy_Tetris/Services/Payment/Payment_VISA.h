/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console_linux.h
Purpose:	child class of UI_console declares member functions and member
			variables for Linux OS
*******************************************************************************/
#ifndef PAYMENT_VISA_H
#define PAYMENT_VISA_H

#include "IPayment.h"
#include "../Logger/LoggerHandler.h"

using Services::IPayment;

namespace Services
{
	class Payment_VISA : public IPayment
	{
	public:
		Payment_VISA();

		bool acceptCardInfo(std::string, std::string, std::string, std::string, std::string, std::string);
		void printToLogger(std::string);

	private:
		std::unique_ptr<Services::LoggerHandler>             _loggerPtr;
		Services::LoggerHandler                            & _logger = *_loggerPtr;
	};
}


#endif // !PAYMENT_VISA_H
