
#ifndef PAYMENTFACTORY_H
#define PAYMENTFACTORY_H

#include "IPayment.h"

namespace Services 
{
	class MCFactory;
	class VISAFactory;

	class PaymentFactory 
	{
		static PaymentFactory* createPaymentFactory();

		virtual IPayment* createPayment() = 0;
	};
}

#endif // !PAYMENTFACTORY_H

