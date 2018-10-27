#pragma once

#include "../Game.h"

namespace Domain
{
	class Game_linux : Game 
	{
	public:
		Game_linux(UI::UI_console*);
		void start_Game();

	private:
	};

}