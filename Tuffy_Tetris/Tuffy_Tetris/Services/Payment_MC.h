
#ifndef PAYMENT_MC_H
#define PAYMENT_MC_H

#include "IPayment.h"

using Services::IPayment;

namespace Services 
{
	class Payment_MC : public IPayment 
	{
	public:
		Payment_MC();

		void acceptCardInfo();
		void printToLogger();
	};
}


#endif // !PAYMENT_MC_H

