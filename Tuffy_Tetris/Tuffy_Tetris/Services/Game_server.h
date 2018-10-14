#pragma once


namespace Services 
{
	class Game_server 
	{
	public:
		Game_server();

		virtual void login();
		virtual void logout();
		virtual void save_hs();
		virtual void check_hs();
		virtual void update_sub();
		virtual void check_sub();
	
	};
	
}