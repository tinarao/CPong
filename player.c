#include <SDL.h>
#include <stdbool.h>

#include "player.h"
#include "screen.h"
#include "colors.h"

const int PLAYER_W = 20;
const int PLAYER_H = 100;
const int PLAYER_MARGIN = 10; // margin from the screen edge
const float PLAYER_SPEED = 150.0f;

SDL_Rect* playerRect;

Player CreatePlayer(void) {
	Player player = {
		.score = 0,
		.yPos = WINDOW_H / 2 - PLAYER_H / 2,
	};

	return player;
};

void RenderPlayer(const Player* player, SDL_Renderer* renderer) {
	SDL_Rect rect = {
		.x = WINDOW_W - PLAYER_MARGIN - PLAYER_W,
		.y = player->yPos,
		.w = PLAYER_W,
		.h = PLAYER_H,
	};

	playerRect = &rect;

	SDL_SetRenderDrawColor(renderer, COLOR_WHITE);
	SDL_RenderFillRect(renderer, &rect);
};

void UpdatePlayer(Player *player, SDL_Renderer *renderer, float elapsed) {
	const Uint8 *keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_SPACE]) {
		served = true;
	}

	if (keyState[SDL_SCANCODE_UP] && player->yPos > PLAYER_MARGIN) {
		player->yPos -= elapsed * PLAYER_SPEED;
	}

	if (keyState[SDL_SCANCODE_DOWN] && player->yPos + PLAYER_H < WINDOW_H - PLAYER_MARGIN) {
		player->yPos += elapsed * PLAYER_SPEED;
	}

};