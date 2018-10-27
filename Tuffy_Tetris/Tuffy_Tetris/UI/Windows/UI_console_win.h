#pragma once

#include "../UI_console.h"

namespace UI
{
	class UI_console_win : UI_console 
	{
	public:
		UI_console_win();
		void displayLoginScreen() const;
		void displayMainMenu() const;
		bool login();
		char getMenuChoice();
		std::string getUserName();
		std::string getPassword();
		std::string getEmail();

	private:
		char menuChoice;
		std::string username;
		std::string password;
		std::string email;
		
	};
}