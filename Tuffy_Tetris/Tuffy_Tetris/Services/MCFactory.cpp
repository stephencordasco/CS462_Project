#include "MCFactory.h"

using Services::Payment_MC;

Payment_MC * Services::MCFactory::createPayment()
{
	return new Payment_MC();
}