/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		VISAFactory.h
Purpose:	Concrete factory class for the abstract PaymentFactory class.
			Provides creation functionalty for VISA payment system.
*******************************************************************************/

#ifndef VISAFACTORY_H
#define VISAFACTORY_H

#include "PaymentFactory.h"
#include "Payment_VISA.h"

using Services::PaymentFactory;

namespace Services
{

	class VISAFactory : public PaymentFactory
	{
		Payment_VISA* createPayment() override;
	};
}


#endif // !PAYMENT_MC_H
