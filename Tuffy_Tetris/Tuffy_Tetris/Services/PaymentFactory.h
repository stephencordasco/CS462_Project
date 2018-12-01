
#ifndef PAYMENTFACTORY_H
#define PAYMENTFACTORY_H

#include "IPayment.h"
#include "IPersistence.h"
#include <string>

namespace Services 
{
	class PaymentFactory 
	{
	public:
		static PaymentFactory* createPaymentFactory(IPersistence*);

		virtual IPayment* createPayment() = 0;
	};
}

#endif // !PAYMENTFACTORY_H

