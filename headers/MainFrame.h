#pragma once
#include <SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

enum windowStates {
	MAINMENU,
	NEWGAMEMODES,
	LEADERBOARD,
	ABOUT,
	SINGLEPLAYER,
	MULTIPLAYER,
	OVERLANMODES

};

extern windowStates currState;

class Initialization {

	private:

		int flags = 0;

	public:

		SDL_Window* window;
		SDL_Renderer* renderer;
		TTF_Font* fontType;

		bool is_running = true;

		Initialization() {}
		~Initialization() {}

		void windowInit(const char* title, int x_pos, int y_pos, int p_w, int p_h, bool fullscreen);

		bool runningState() { return is_running; }

		void handleMainEvent(SDL_Event e);
		
		void clean();
};	
