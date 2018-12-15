/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		Logger.h
Purpose:	Interface class for the logger interface to technical services layer.
			Provides logging capability to file. Original code by
			Prof. Thomas Betten and used with permission.
*******************************************************************************/

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
		:_loggingStream(LogFile.c_str(), std::ios::out | std::ios::app)
	{}
} 



#endif 
