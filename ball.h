#pragma once

// Ball object
typedef struct Ball {
	float x;
	float y;
	float xSpeed;
	float ySpeed;
	int size;
} Ball;

extern SDL_Rect* ballRect;

// Create a Ball instance
Ball CreateBall(int size);

// Renders a ball
void RenderBall(const Ball* ball, SDL_Renderer* renderer);

// Update a ball position based on it's speed and position
void UpdateBall(Ball* ball, SDL_Renderer* renderer, SDL_Window* window, float elapsed);