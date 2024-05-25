#pragma once

#define WINDOW_W 900
#define WINDOW_H 600

extern bool served;
extern int score;
extern int lifes;

// Updates window title with known lifes and score values
void UpdateWindowTitle(SDL_Window* window);