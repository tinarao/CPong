#pragma once

// Player object
typedef struct Player {
	int score;
	float yPos;
} Player;

// Player rect width
extern const int PLAYER_W;

extern SDL_Rect* playerRect;

// Player rect height
extern const int PLAYER_H;

// Player rect margin
extern const int PLAYER_MARGIN;

// Player speed
extern const float PLAYER_SPEED;

// Returns a player instance
Player CreatePlayer(void);

// Renders a player to the screen
void RenderPlayer(Player* player, SDL_Renderer* renderer);

// Update the player
void UpdatePlayer(Player* player, SDL_Renderer* renderer, float elapsed);