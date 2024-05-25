#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "ball.h"
#include "player.h"
#include "screen.h"

void InspectCollisions(Ball* ball, Player* player, SDL_Window* window) {
	SDL_Rect ballRect = {
		.x = ball->x - ball->size / 2,
		.y = ball->y - ball->size / 2,
		.w = ball->size,
		.h = ball->size,
	};

	SDL_Rect playerRect = {
		.x = WINDOW_W - PLAYER_W - PLAYER_MARGIN,
		.y = (int)(player->yPos) - PLAYER_H / 2,
		.w = PLAYER_W,
		.h = PLAYER_H,
	};

	if (SDL_HasIntersection(&ballRect, &playerRect)) {
		score += 100;
		ball->xSpeed = -fabs(ball->xSpeed + score / 2);

		
		UpdateWindowTitle(window);
	}
}