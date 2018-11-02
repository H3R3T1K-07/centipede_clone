 #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "doctest.h"
#include "../game-source-code/Player.h"
#include "../game-source-code/Centipede.h"
#include "../game-source-code/Projectile.h"
#include "../game-source-code/GameLoop.h"
#include "../game-source-code/GameStates.h"
#include "../game-source-code/GamePlay.h"
#include "../game-source-code/SplashScreen.h"
#include "../game-source-code/GameDefinitions.h"
#include "../game-source-code/GameStatesHandler.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <vector>

#include <iostream>

	// Player Tests
	TEST_CASE("Test if player can move in all the four cardinal directions")
	{
		Centipede::GameDataRef _data =std::make_shared<Centipede::GameData>();
		Centipede::Player player(_data);
		
		// moved left?
		sf::Vector2f pos1 = player.getCenter();
		player.moveLeft();
		sf::Vector2f pos2 = player.getCenter();
		CHECK(pos1 != pos2);
		
		// moved right?
		player.moveRight();
		pos1 = player.getCenter();
		CHECK(pos1 != pos2);
		
		// moved up?
		player.moveUp();
		pos2 = player.getCenter();
		CHECK(pos1 != pos2);
		
		// moved down?
		player.moveDown();
		pos1 = player.getCenter();
		CHECK(pos1 != pos2);
		
		//Testing the NoMovement functions
		player.noMovementX();
		pos2 = player.getCenter();
		CHECK(pos1 == pos2);
		
		player.noMovementY();
		pos1 = player.getCenter();
		CHECK(pos1 == pos2);
		
	}


// Centipede Tests

	TEST_CASE("Test if centipede segments can move in all the four cardinal directions")
	{
        Centipede::GameDataRef _data =std::make_shared<Centipede::GameData>();
		Centipede::Centi centipede(_data);
        
        sf::Vector2f pos1;
        sf::Vector2f pos2;
        
        std::vector<sf::CircleShape> centipedeSprites = centipede.GetSprites();
     
        for (int i = 0; i < centipedeSprites.size(); i++)
			{
				pos1 = centipedeSprites.at(i).getPosition();
                centipede.moveCentipede();
                centipedeSprites = centipede.GetSprites();
                pos2 = centipedeSprites.at(i).getPosition();
                
                CHECK(pos1 != pos2);
			}
	}


// Bullet Tests

	TEST_CASE("Test if bullet is created in same position as player")
	{
		
		Centipede::GameDataRef _data =std::make_shared<Centipede::GameData>();
		Centipede::Projectile bullet(_data);
		Centipede::Player ship(_data);
		
		ship.moveRight();
		sf::Vector2f pos1 = ship.getCenter();
		
		bullet.loadShot(pos1);
		sf::Vector2f pos2 = bullet.getCenter();
		
		CHECK(pos1 == pos2);
	}
	
	TEST_CASE("Test if bullet moves away from player when fired")
	{
		
		Centipede::GameDataRef _data =std::make_shared<Centipede::GameData>();
		Centipede::Projectile bullet(_data);
		Centipede::Player ship(_data);
		
		sf::Vector2f pos1 = ship.getCenter();
		
		bullet.loadShot(pos1 );
		bullet.fireShot();
		sf::Vector2f pos2 = bullet.getCenter();
		
		CHECK(pos1 != pos2); // I doubt this will work
	}
	


