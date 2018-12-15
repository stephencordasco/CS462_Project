/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		14 December 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		IPayment.h
Purpose:	Declares the interface functionality for the IPayment interface to
			the technical services layer. Interface handles payment processing
			functionality.
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

