#include "PaymentFactory.h"
#include "MCFactory.h"
#include "VISAFactory.h"

using Services::PaymentFactory;

PaymentFactory * Services::PaymentFactory::createPaymentFactory(PersistenceHandler* p)
{
	std::string payment_type = p->read_config_payment();
	Logger log("Log.txt");
	if (payment_type == "mastercard") 
	{
		log << "Using Mastercard Payment Processor";
		return new MCFactory();

	}
	else //default VISAFactory if empty or otherwise
	{
		log << "Using VISA Payment Processor";
		return new VISAFactory();
	}
}
