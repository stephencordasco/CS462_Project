/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console_linux.h
Purpose:	child class of UI_console declares member functions and member
			variables for Linux OS
*******************************************************************************/

#ifndef IPAYMENT_H
#define IPAYMENT_H

#include<string>

namespace Services 
{
	class IPayment 
	{
	public:
		IPayment();
		virtual bool acceptCardInfo(std::string, std::string, std::string, std::string, std::string, std::string) = 0;
		virtual void printToLogger(std::string) = 0;


	};


	inline IPayment::IPayment()
	{}



}


#endif // !IPAYMENT_H

