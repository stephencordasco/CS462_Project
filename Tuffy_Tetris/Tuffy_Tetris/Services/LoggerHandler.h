#ifndef Services_LoggerHandler_h
#define Services_LoggerHandler_h


#include <iostream>
#include <string>
#include <fstream>


namespace Services
{
	// Logging Package within the Technical Services Layer Abstract class
	class LoggerHandler
	{
	public:
		// Constructors and assignment operations
		LoggerHandler(std::string const & LogFile);
		LoggerHandler(const LoggerHandler &  original) = default;  // copy ctor
		LoggerHandler(LoggerHandler && original) = default;  // move ctor

		virtual LoggerHandler & operator=(const LoggerHandler &  rhs) = default;  // copy assignment
		virtual LoggerHandler & operator=(LoggerHandler && rhs) = default;  // move assignment


		// Operations
		virtual LoggerHandler & operator<< (const std::string & message) = 0;

		// Destructor
		// Pure virtual destructor helps force the class to be abstract, but must still be implemented
		virtual ~LoggerHandler() noexcept = 0;


	protected:
		std::ofstream _loggingStream;
	};





	/*****************************************************************************
	** Inline default implementations
	******************************************************************************/
	inline LoggerHandler::~LoggerHandler() noexcept
	{}


	
	
	inline LoggerHandler::LoggerHandler(std::string const & LogFile) 
		:_loggingStream(LogFile.c_str(), std::ios::out)
	{}
} 



#endif 
