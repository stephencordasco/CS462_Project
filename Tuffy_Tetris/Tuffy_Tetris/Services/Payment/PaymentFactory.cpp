/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		8 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		PaymentFactory.cpp
Purpose:	Defines implementation of functionality for the PaymentFactory
			abstract factory class.
*******************************************************************************/

#include "PaymentFactory.h"
#include "MCFactory.h"
#include "VISAFactory.h"

using Services::PaymentFactory;

PaymentFactory * Services::PaymentFactory::createPaymentFactory(PersistenceHandler* p)
{
	std::string payment_type = p->read_config_payment();

	Logger log("Log.txt");
	if (payment_type == "mastercard")
	{
		log << "Using Mastercard Payment Processor";
		return new MCFactory();
	}
	else //default VISAFactory if empty or otherwise
	{
		log << "Using VISA Payment Processor";
		return new VISAFactory();
	}
}
