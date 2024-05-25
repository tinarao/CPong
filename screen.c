#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

bool* served = false;
int score = 0;
int lifes = 3;

void UpdateWindowTitle(SDL_Window *window) {
	char str[128];
	snprintf(str, 128, "Pong | Score: %d | Lifes: %d", score, lifes);

	SDL_SetWindowTitle(window, str);
}