
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

