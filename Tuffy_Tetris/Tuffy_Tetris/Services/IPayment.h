

#ifndef IPAYMENT_H
#define IPAYMENT_H

#include<string>

namespace Services 
{
	class IPayment 
	{
	public:
		IPayment();
		virtual bool acceptCardInfo(std::string, std::string, std::string, std::string, std::string, std::string) = 0;
		virtual void printToLogger(std::string) = 0;


	};


	inline IPayment::IPayment()
	{}



}


#endif // !IPAYMENT_H

