#pragma once

#ifndef GAME_H
#define GAME_H

#include <string>
#include "../Board/Board.h"
#include "../../UI/UI_console.h"

namespace Domain {

	class Game
	{
	public:
		Game();
		virtual void start_Game() = 0;
		virtual bool is_Started() = 0;
		virtual bool is_Paused() = 0;
		virtual bool is_Logged() = 0;
		virtual void end_Game() = 0;
		virtual void get_Frame(std::string&) = 0;
		virtual void set_Paused() = 0;
		virtual bool process_Input(char) = 0;
		virtual bool register_acct(std::string, std::string, std::string) = 0;
		virtual bool login(std::string, std::string) = 0;
		virtual bool logout(std::string) = 0;
		virtual bool purchase_Sub(std::string, std::string, std::string, std::string,
			std::string, std::string) = 0;
		virtual int get_Userscore() = 0;
		virtual std::string get_Email() = 0;
		virtual std::string get_User() = 0;
		virtual bool is_Admin(std::string) = 0;
		virtual bool get_Sub() = 0;
		virtual int get_Level() = 0;
		virtual int get_Score() = 0;
		virtual bool save_Score() = 0;
		virtual ~Game();
	};

}

#endif // !IGAME_H
