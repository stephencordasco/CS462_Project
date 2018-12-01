

#ifndef SIMPLEDB_H
#define SIMPLEDB_H

#include "IPersistence.h"
#include <string>

namespace Services 
{
	class SimpleDB : public IPersistence 
	{
	public:
		bool login(std::string, std::string, std::string) override;
		std::string read_config_payment() override;
	};

}
#endif // !SIMPLEDB_H
