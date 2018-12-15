/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		MCFactory.h
Purpose:	Concrete factory class for the abstract PaymentFactory class. 
			Provides creation functionalty for Mastercard payment system.
*******************************************************************************/

#ifndef MCFACTORY_H
#define MCFACTORY_H

#include "PaymentFactory.h"
#include "Payment_MC.h"

using Services::PaymentFactory;

namespace Services
{

	class MCFactory : public PaymentFactory
	{
		Payment_MC* createPayment() override;
	};
}


#endif // !PAYMENT_MC_H
