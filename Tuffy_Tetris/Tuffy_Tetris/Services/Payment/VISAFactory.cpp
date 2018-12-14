#include "VISAFactory.h"

using Services::Payment_VISA;

Payment_VISA * Services::VISAFactory::createPayment()
{
	return new Payment_VISA();
}
