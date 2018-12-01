#ifndef LOGGER_H
#define LOGGER_H


#include<iostream>
#include<string>
namespace Services
{
	class Logger
	{
		Logger(std::ostream & loggingStream);  // default ctor

		// Operations
		Logger & operator<< (const std::string & message);

		// Destructor
		~Logger() noexcept;

	protected:
		std::ostream & _loggingStream;
	};
}

#endif