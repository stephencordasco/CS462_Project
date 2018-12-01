#include "SimpleDB.h"

bool Services::SimpleDB::login(std::string, std::string, std::string)
{
	return true;
}

std::string Services::SimpleDB::read_config_payment()
{
	//stub
	return "mastercard";
}
