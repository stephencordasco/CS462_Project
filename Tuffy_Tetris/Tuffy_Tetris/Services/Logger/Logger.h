#ifndef TechicalServices_Logging_SimpleLogger_hpp
#define TechicalServices_Logging_SimpleLogger_hpp

#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

#include "LoggerHandler.h"


namespace Services
{
	class Logger : public Services::LoggerHandler
	{
	public:
		//Constructors
		using LoggerHandler::LoggerHandler;                       // inherent constructors
		Logger(std::string const & LogFile = "Services/Log.txt");
		
		
		// Operations
		 Logger & operator<< (const std::string & message) override;

		// Destructor
		~Logger() noexcept override;
	}; // class SimpleLogger


/*****************************************************************************
** Inline implementations
******************************************************************************/
	inline Logger::Logger(std::string const & LogFile)
		: LoggerHandler(LogFile)
	{
		*this << "Logger being used and has been successfully initialized";
	}


	inline Logger::~Logger() noexcept
	{
		*this << "Simple Logger shutdown successfully";
	}



	inline Logger & Logger::operator<< (const std::string & message)
	{
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

#pragma warning(suppress : 4996)  // acknowledge and accept that std::localtime is not thread safe (Turn off MSVC++ warning)
		_loggingStream << std::put_time(std::localtime(&now), "%Y-%m-%d %X") << " | ";

		_loggingStream << message << '\n';

		return *this;
	}





}


#endif
