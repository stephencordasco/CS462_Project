

#ifndef IPERSISTENCE_H
#define IPERSISTENCE_H

#include <string>

namespace Services
{
	class IPersistence
	{
	public:
		

		virtual bool login(std::string, std::string, std::string) = 0;

		//read config file to retrieve payment processor type
		virtual std::string read_config_payment() = 0;
		

		virtual ~IPersistence();
	};
}

#endif
