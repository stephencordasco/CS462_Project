#pragma once

#include <string>

namespace Services 
{
	class Game_server 
	{
	public:
		Game_server();

		virtual bool login(std::string user, std::string pass, std::string email = "");
		virtual bool logout(std::string user);
		virtual bool register_acct(std::string user, std::string pass, std::string email);
		virtual bool save_hs(int current_score);
		virtual bool check_hs(int current_score);
		virtual bool update_sub(std::string cNum, std::string accName, std::string secNum,
								std::string dExp, std::string addr, std::string zip);
		virtual bool check_sub();

		virtual ~Game_server();
	
	};
	
}