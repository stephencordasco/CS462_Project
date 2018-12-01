

#ifndef IPERSISTENCE_H
#define IPERSISTENCE_H

#include <string>

namespace Services
{
	class IPersistence
	{
	public:
		

		virtual bool login(std::string, std::string, std::string) = 0;
		

		virtual ~IPersistence();
	};
}

#endif
