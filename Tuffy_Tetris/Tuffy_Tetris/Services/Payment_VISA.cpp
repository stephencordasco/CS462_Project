#include "../Services/Payment_VISA.h"

using Services::Payment_VISA;

Payment_VISA::Payment_VISA()
{

}

bool Payment_VISA::acceptCardInfo(std::string cardNumber, std::string accountHolder, std::string securityNumber, std::string expirationDate, std::string billingAddress, std::string zipCode)
{
	return true;
}

void Payment_VISA::printToLogger(std::string message)
{
	_logger << message;
}