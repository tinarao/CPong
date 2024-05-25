#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int RandomNumber(int min, int max) {
	
	static bool initialized = false;
	if (!initialized) {
		initialized = true;
		srand(time(NULL));
	}

	return rand() % max + min;
}

int RandomColor() {
	return RandomNumber(0, 255);
}

bool CoinFlip(void) {
	return RandomNumber(1, 2) % 2 == 1;
}