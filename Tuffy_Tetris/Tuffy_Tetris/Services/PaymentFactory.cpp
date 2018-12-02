#include "PaymentFactory.h"
#include "MCFactory.h"
#include "VISAFactory.h"

using Services::PaymentFactory;

PaymentFactory * Services::PaymentFactory::createPaymentFactory(PersistenceHandler* p)
{
	std::string payment_type = p->read_config_payment();

	if (payment_type == "mastercard") 
	{
		return new MCFactory();
	}
	else //default VISAFactory if empty or otherwise
	{
		return new VISAFactory();
	}
}
