
#ifndef PAYMENT_MC_H
#define PAYMENT_MC_H

#include "IPayment.h"
#include "LoggerHandler.h"

using Services::IPayment;

namespace Services 
{
	class Payment_MC : public IPayment 
	{
	public:
		Payment_MC();

		bool acceptCardInfo(std::string, std::string, std::string, std::string, std::string, std::string);
		void printToLogger(std::string);

	private:
		std::unique_ptr<Services::LoggerHandler>             _loggerPtr;
		Services::LoggerHandler                            & _logger = *_loggerPtr;
	};
}


#endif // !PAYMENT_MC_H

