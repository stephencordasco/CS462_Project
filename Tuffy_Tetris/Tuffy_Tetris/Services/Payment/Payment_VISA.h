/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Payment_VISA.h
Purpose:	Declares concrete class for IPayment interface class. This class
			handles payment processing for the VISA payment method.
*******************************************************************************/

#ifndef PAYMENT_VISA_H
#define PAYMENT_VISA_H

#include <memory>
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
