#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "colors.h"
#include "ball.h"
#include "player.h"
#include "screen.h"
#include "collision.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

const int BALL_SIZE = 20;
Ball ball;
Player player;

static bool PongInit(void) {
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Pong | Score: 0 | Lifes: 3",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN
	);
	if (!window) {
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		return false;
	}

	ball = CreateBall(BALL_SIZE);
	player = CreatePlayer();

	return true;
};

// Main loop, i guess
static void Update(float elapsed) {
	SDL_SetRenderDrawColor(renderer, COLOR_BLACK);
	SDL_RenderClear(renderer);

	//
	UpdateBall(&ball, renderer, window, elapsed);
	UpdatePlayer(&player, renderer, elapsed);

	RenderBall(&ball, renderer);
	RenderPlayer(&player, renderer);

	InspectCollisions(&ball, &player, window);
	//

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

		printf("Lifes: %d\tScore: %d\n", lifes, score);

		if (lifes == 0) {
			printf("Proebal loh");
			break;
		}
	}

	return 0;
}