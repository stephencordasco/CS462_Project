/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		8 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		SimpleDB.cpp
Purpose:	Defines implementation of functionality for the SimpleDB class.
			Original code by Prof. Thomas Betten and used with permission.
*******************************************************************************/

#include "SimpleDB.h"
#include "../Logger/Logger.h"
#include <string>
#include <vector>
#include <fstream>
#include "../../Domain/Player/Player.h"

namespace Services
{
	SimpleDB::SimpleDB()
		: _loggerPtr(new Services::Logger("Services/Log.txt"))
	{
		_logger << "Simple DB being used and has been successfully initialized";
		PaymentFactory* pFactory = PaymentFactory::createPaymentFactory(this);
		payment_processor = pFactory->createPayment();
	}



	SimpleDB::~SimpleDB() noexcept
	{
		_logger << "Simple DB shutdown successfully";
	}


	bool Services::SimpleDB::checkDB(std::string username, std::string password, std::string email)
	{
		
		std::string line;
		std::ifstream ReadPersistFile;
		//opens persistence file in services folder
		ReadPersistFile.open("Services/Persistence.txt", std::ios::in);

		//reads first line of persistence file which holds the number of users
		getline(ReadPersistFile, line);
		
		//converts the number of users into an integer
		int numUsers = stoi(line);

		//goes through all the users
		for (int i = 0; i < numUsers; i++) {
			getline(ReadPersistFile, line);
			std::string tokens[5];
			int tokIndex = 0;
			char comma = ',';
			int begToken = 0;

			//breaks down each line into tokens for username, password, email, etc.
			for (int j = 0; j < line.length(); j++) {

				//separated by commas
				if (line.at(j) == comma) {
					tokens[tokIndex] = line.substr(begToken, j-begToken);
					std::cout << tokens[tokIndex] << std::endl;
					begToken = j+1;
					j++;
					tokIndex++;
				}
			}

			//if first three tokens match return true
			if (username == tokens[0] && password == tokens[1] && email == tokens[2]) {

				//log when successful login
				_logger << "User has successfully logged in";
				return true;
			}
		}

		//log that login failed
		_logger << "Login failed";

		//if none match return false
		return false;
	}

	bool SimpleDB::AddUser(std::string username, std::string password, std::string email) 
	{
		//open persistence file in services folder for reading
		std::ifstream ReadPersistFile("Services/Persistence.txt");

		//if persistence file exists
		if (ReadPersistFile) {
			std::string* lines;
			std::string line;

			//reads first line of persistence file which holds the number of users
			getline(ReadPersistFile, line);

			//converts number of users into an integer
			int numUsers = stoi(line);

			//creates an array to store each line of the text document
			lines = new std::string[numUsers + 1];


			//goes through each user already stored and saves it to the array
			for (int i = 0; i < numUsers; i++) {
				getline(ReadPersistFile, line);
				lines[i] = line;
			}
			
			//adds the new user to the array
			lines[numUsers] = username + "," + password + "," + email + "," + "0," + "No,";

			//closes the file
			ReadPersistFile.close();

			//opens the persistence file for writing
			std::ofstream WritePersistFile("Services/Persistence.txt", std::ios::out);

			//increments the number of users and writes it to the persistence file
			WritePersistFile << numUsers + 1<<"\n";

			//adds stored lines to persistence file
			for (int i = 0; i < numUsers + 1; i++) {
				WritePersistFile << lines[i]<<"\n";
			}

			//closes persistence file
			WritePersistFile.close();

			//log successful account creation
			_logger << "New account successfully created";
		}
		//if file doesn't exist
		else{
			//creates a new file
			std::ofstream WritePersistFile("Services/Persistence.txt", std::ios::out);

			//adds 1 user to the file
			WritePersistFile << "1\n";

			//adds new user
			WritePersistFile << username << "," << password << "," << email << "," << "0," << "No,";

			//log successful account creation
			_logger << "New account successfully created";
		}

		return true;
	}

	bool SimpleDB::authorizePayment(std::string cardNum, std::string acctHolder, std::string secNum, std::string exprDate, std::string addr, std::string zip)
	{
		if (cardNum != " ")
			return true;
		else return false;
	}

	bool SimpleDB::checkSub(std::string)
	{
		//stub, call actual function to search database
		return false;
	}
}

std::string Services::SimpleDB::read_config_payment()
{
	//stub
	return "mastercard";
}