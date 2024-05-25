#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "colors.h"

#define WINDOW_W 900
#define WINDOW_H 600
#define BALL_SIZE 20

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

static void PongRenderBall(void) {
	SDL_SetRenderDrawColor(renderer, COLOR_WHITE);

	SDL_Rect ballRect = {
		WINDOW_W / 2 - BALL_SIZE / 2,
		WINDOW_H / 2 - BALL_SIZE / 2,
		BALL_SIZE,
		BALL_SIZE,
	};

	SDL_RenderFillRect(renderer, &ballRect);
}

static bool PongInit(void) {
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Pong",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN
	);
	if (!window) {
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		return false;
	}
	return true;
};

// Main loop, i guess
static void Update(float elapsed) {
	SDL_SetRenderDrawColor(renderer, COLOR_BLACK);
	SDL_RenderClear(renderer);

	PongRenderBall();

	SDL_RenderPresent(renderer);

};

static void Shutdown(void) {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}
	if (window) {
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
};

int main(int argc, const char **argv[]) {
	_crt_atexit(Shutdown);

	if (!PongInit()) {
		exit(1);
	}

	SDL_Event event;
	bool running = true;
	Uint32 lastTick = SDL_GetTicks();

	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			}
		}
		Uint32 currTick = SDL_GetTicks();
		Uint32 diff = currTick - lastTick;
		Update(diff / 1000.0f);
		lastTick = currTick;
	}

	return 0;
}