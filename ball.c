#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "utils.h"
#include "ball.h"
#include "colors.h"
#include "screen.h"

SDL_Rect* ballRect;
int ballSpeed = 100;

Ball CreateBall(int size) {
	Ball ball = {
		.x = WINDOW_W / 2 - size / 2,
		.y = WINDOW_H / 2 - size / 2,
		.size = size,
		.xSpeed = ballSpeed * (CoinFlip() ? 1 : -1),
		.ySpeed = ballSpeed * (CoinFlip() ? 1 : -1),

	};

	return ball;
}

void RenderBall(const Ball *ball, SDL_Renderer *renderer) {
	int size = ball->size;
	int halfSize = size / 2;

	SDL_Rect rect = {
		.x = ball->x - size / 2,
		.y = ball->y - size / 2,
		.w = size,
		.h = size,
	};

	ballRect = &rect;

	SDL_SetRenderDrawColor(renderer, COLOR_WHITE);
	SDL_RenderFillRect(renderer, &rect);
}

void UpdateBall(Ball* ball, SDL_Renderer* renderer, SDL_Window* window, float elapsed) {
	if (!served) {
		ball->x = WINDOW_W / 2;
		ball->y = WINDOW_H / 2;

		return;
	}

	ball->x += ball->xSpeed * elapsed;
	ball->y += ball->ySpeed * elapsed;

	if (ball->x < ball->size / 2) {
		ball->xSpeed = fabs(ball->xSpeed);
	}

	if (ball->x > WINDOW_W - ball->size / 2) {
		ball->xSpeed = -fabs(ball->xSpeed);
		lifes -= 1;
		UpdateWindowTitle(window);
	}

	if (ball->y < ball->size / 2) {
		ball->ySpeed = fabs(ball->ySpeed);
	}

	if (ball->y > WINDOW_H - ball->size / 2) {
		ball->ySpeed = -fabs(ball->ySpeed);
	}
}