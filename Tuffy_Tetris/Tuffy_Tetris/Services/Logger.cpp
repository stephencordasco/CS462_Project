
#define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"
#include <chrono>
#include <iomanip>

using Services::Logger;

//contructor
 Logger::Logger(std::ostream & loggingStream)
	: _loggingStream(loggingStream)
 {
	 //flushes the output stream before use
	 loggingStream << std::unitbuf;

	 *this << "Simple Logger being used and has been successfully initialized";
 }

 //operator overloading for <<
 Logger & Logger::operator<< (const std::string & message)
 {
	 //gets the current time
	 auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

#pragma warning(suppress : 4996)  // acknowledge and accept that std::localtime is not thread safe (Turn off MSVC++ warning)
	
	 //prints the current time and date to the log
	 _loggingStream << std::put_time(std::localtime(&now), "%Y-%m-%d %X") << " | ";

	 //prints the message to the log
	 _loggingStream << message << '\n';

	 return *this;
 }

 //destructor
 Logger::~Logger() noexcept
 {
	 *this << "Simple Logger shutdown successfully";
 }