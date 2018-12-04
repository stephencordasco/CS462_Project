#include "../Services/Payment_MC.h"

using Services::Payment_MC;

Payment_MC::Payment_MC()
{

}

bool Payment_MC::acceptCardInfo(std::string cardNumber, std::string accountHolder, std::string securityNumber, std::string expirationDate, std::string billingAddress, std::string zipCode)
{
	return true;
}

void Payment_MC::printToLogger(std::string message)
{
	_logger << message;
}