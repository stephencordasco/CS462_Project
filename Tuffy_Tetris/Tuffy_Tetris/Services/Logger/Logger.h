/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Logger.h
Purpose:	Concrete class for the LoggerHandler Interface provides logging
			capability to file. Original code by Prof. Thomas Betten. and used
			with permission.
*******************************************************************************/


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
#ifdef _MSC_VER
		#pragma warning(suppress : 4996)  // acknowledge and accept that std::localtime is not thread safe (Turn off MSVC++ warning)
		_loggingStream << std::put_time(std::localtime(&now), "%Y-%m-%d %X") << " | ";
#else
		_loggingStream << std::put_time(std::localtime(&now), "%Y-%m-%d %X") << " | ";
#endif
		_loggingStream << message << '\n';

		return *this;
	}





}


#endif
