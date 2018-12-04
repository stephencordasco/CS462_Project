

#ifndef IPAYMENT_H
#define IPAYMENT_H

namespace Services 
{
	class IPayment 
	{
		virtual bool acceptCardInfo() = 0;
		virtual void printToLogger() = 0;
	};
}


#endif // !IPAYMENT_H

