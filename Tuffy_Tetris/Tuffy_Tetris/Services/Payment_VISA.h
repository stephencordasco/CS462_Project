
#ifndef PAYMENT_VISA_H
#define PAYMENT_VISA_H

#include "IPayment.h"

using Services::IPayment;

namespace Services
{
	class Payment_VISA : public IPayment
	{
	public:
		Payment_VISA();

		void acceptCardInfo();
		void printToLogger();
	};
}


#endif // !PAYMENT_VISA_H
