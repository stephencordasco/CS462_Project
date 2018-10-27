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
		string getUserName();
		string getPassword();
		string getEmail();

	private:
		char menuChoice;
		string username;
		string password;
		string email;
		
	};
}