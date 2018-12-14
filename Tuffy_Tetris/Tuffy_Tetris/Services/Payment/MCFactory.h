
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
