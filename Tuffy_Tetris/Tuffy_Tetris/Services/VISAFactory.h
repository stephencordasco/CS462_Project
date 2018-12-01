

#ifndef MCFACTORY_H
#define MCFACTORY_H

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
