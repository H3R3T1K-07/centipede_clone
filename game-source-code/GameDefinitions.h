/** @brief Contains useful definitions that are made available to the relevant classes
* 
*/ 

#ifndef GAMEDEFINITIONS_H_
#define GAMEDEFINITIONS_H_

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define PROJECTILE_MOVEMENT_SPEED 200
#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_OVER_APPEARS 25.f

const int SEG_SIZE = 1; // number of centipede segments

#define SPLASH_SCREEN_FONT_FILEPATH "resources/ARIAL.TTF"
#define GAME_WINDOW_BACKGROUND_FILEPATH "resources/galaxy.png"
#define SPLASH_SCREEN_BACKGROUND_FILEPATH "resources/galaxy2.png"
#define PLAYER_SPRITE_FILEPATH "resources/ship.png"
#define CENTIPEDE_SPRITE_FILEPATH "resources/badbug.png"
#define MUSHROOM_SPRITE_FILEPATH "resources/Mushroom.png"

// Enumeration to help manage game states during gameplay
enum Game_States
{
	eReady,
	ePlaying,
	eGameOver,
    eFinished
};

#endif /* GAMEDEFINITIONS_H_ */