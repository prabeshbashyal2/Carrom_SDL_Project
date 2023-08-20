#include "headers/PlayerIntro.h"
#include "headers/MainFrame.h"
#include "headers/MainMenu.h"
#include "headers/TextureManager.h"
#include "headers/music.h"
#include "headers/fonts.h"
#include "headers/SinglePlayerGame.h"

extern Initialization* MainWindow;
extern MainMenu MenuWindow;
extern Music* ClickSound;
extern SinglePlayerGame SinglePlayerGameWindow;


void PlayerIntro::render_message() {

	FontManager::LFont(MainWindow->renderer, message_surface, message_texture, MainWindow->fontType, "Enter your name ", { 218, 165, 32 }, &r11);

}

void PlayerIntro::render_message_box() {
	
	FontManager::LFont(MainWindow->renderer, message_box_surface, message_box_texture, MainWindow->fontType, textInput.c_str(), { 255, 255, 255 }, &r12);

}

void PlayerIntro::render_done_button() {

	if (done_button_state == true) {
		done_surface = IMG_Load("buttons/done_two.png");
		done_button_state = false;
	}
	else {
		done_surface = IMG_Load("buttons/done_one.png");
		done_button_state = true;
	}

	TextureManager::LTexture(MainWindow->renderer, done_surface, done_texture, NULL, &r13);

}

void PlayerIntro::render_intro_all() {

	render_message();
	render_done_button();
	
}

void PlayerIntro::reset_button_states() {

	done_button_state = true;

}

void PlayerIntro::handlePlayerIntroEvents(SDL_Event e) {

	switch (e.type) {

		case SDL_MOUSEBUTTONDOWN:
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (x >= 370 + offsetX && x <= 370 + 200 + offsetX && y >= 550 + offsetY && y <= 550 + offsetY + BUT_HEIGHT) {
				render_done_button();
				ClickSound->PlayClickMusic();
				render_message_box();
				std::cout <<"Player 1: " <<textInput << std::endl;
				SDL_Delay(2000);
				currState = SINGLEPLAYERGAME;
				SDL_RenderClear(MainWindow->renderer);
				SinglePlayerGameWindow.render_singleplayer_window();
				ClickSound->PauseBackgroundMusic();

			}
			break;	

		case SDL_TEXTINPUT:
			SDL_StartTextInput();
			textInput += e.text.text;
			break;

		default:
			break;

	}
}