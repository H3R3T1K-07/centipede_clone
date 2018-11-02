/** @brief Creates game play state object
* 
*/ 

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <SFML/Graphics.hpp>
#include "GameStates.h"
#include "GameLoop.h"
#include "Player.h"
#include "Projectile.h"
#include "Centipede.h"
#include "Collision.h"
#include "CollisionScreen.h"
#include "Score.h"
#include "Mushroom.h"

namespace Centipede
{
	class GamePlay : public GameStates
	{
	public:
/** @brief Class constructor
* 
*/     
        GamePlay(GameDataRef data);
        
/** @brief Initialises state
* 
*/ 
		void Init();
        
/** @brief Manages user input
* 
*/ 
		void HandleInput();
/** @brief Updates changes to variables
* 
*/ 
		void Update(float dt);
        
/** @brief Renders changes
* 
*/ 
		void Draw(float dt);

	private:
		GameDataRef _data;
        Player *spaceShip;
        Projectile *bullet;
        Centi *centi;
        Centi *centi2;
        Centi *centi3;
        Centi *centi4;
        Centi *centi5;
        Centi *centi6;
        Centi *centi7;
        Centi *centi8;
        Centi *centi9;
        Centi *centi10;
        Centi *centi11;
        Centi *centi12;
        Centi *centi13;
        Centi *centi14;
        Centi *centi15;
        
        Mushroom *mushroom;
        Mushroom *mushroom2;
        Mushroom *mushroom3;
        Mushroom *mushroom4;
        Mushroom *mushroom5;
        Mushroom *mushroom6;
        Mushroom *mushroom7;
        Mushroom *mushroom8;
        Mushroom *mushroom9;
        Mushroom *mushroom10;
        Mushroom *mushroom11;
        Mushroom *mushroom12;
        Mushroom *mushroom13;
        Mushroom *mushroom14;
        Mushroom *mushroom15;
        Mushroom *mushroom16;
        Mushroom *mushroom17;
        Mushroom *mushroom18;
        Mushroom *mushroom19;
        Mushroom *mushroom20;
        Mushroom *mushroom21;
        Mushroom *mushroom22;
        Mushroom *mushroom23;
        Mushroom *mushroom24;
        Mushroom *mushroom25;
        Mushroom *mushroom26;
        
        
        FlashScreen *flash;
        Score *score;
        
        Collision collision;
        
		sf::Sprite _background;
        sf::Clock clock;
        
        std::vector<Centi> _CentiSegs;
        std::vector<sf::CircleShape> _segs;
        std::vector<sf::CircleShape> _indisegs;
        
        int _gameState;
        int _shootTimer;
        int _score;
        int _centipedeCount;
        bool leftButton = false, rightButton = false, upButton = false, downButton = false, shootButton = false;


	};
}







#endif /* GAMEPLAY_H_*/