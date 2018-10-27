#pragma once

#include <string>
#include "../Domain/Game/Game.h"
#include "../Services/Game_server.h"

namespace UI 
{
	class UI_console 
	{
	public:
		UI_console();

		//virtual methods
		virtual void displayLoginScreen() const = 0;
		virtual void displayMainMenu() const = 0;
		virtual bool login() = 0;
		virtual char getMenuChoice() = 0;
		virtual std::string getUserName() = 0;
		virtual std::string getPassword() = 0;
		virtual std::string getEmail() = 0;
	private:
		//common fields
		char menuChoice;
		std::string username;
		std::string password;
		std::string email;
	};
}