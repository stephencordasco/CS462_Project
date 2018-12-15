/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		PaymentFactory.h
Purpose:	Abstract factory class for construction of payment processor system
			classes. Delivers appropriate factory type for object creation.
*******************************************************************************/


#ifndef PAYMENTFACTORY_H
#define PAYMENTFACTORY_H

#include "IPayment.h"
#include "../Persistence/PersistenceHandler.h"
#include "../Logger/Logger.h"
#include <string>

namespace Services 
{
	class PaymentFactory 
	{
	public:
		static PaymentFactory* createPaymentFactory(PersistenceHandler*);

		virtual IPayment* createPayment() = 0;
	};
}

#endif // !PAYMENTFACTORY_H

