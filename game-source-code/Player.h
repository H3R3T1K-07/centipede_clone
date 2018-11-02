/** @brief Creates player object
* 
*/ 
#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>

#include "GameDefinitions.h"
#include "GameLoop.h"


namespace Centipede
{
	class Player
	{
	public:
/** @brief Class contructor
* 
*/     
		Player(GameDataRef data);
		~Player();
/** @brief Moves player sprite
* 
*/         
        void moveUp();
/** @brief Moves player sprite
* 
*/ 
        void moveDown();
/** @brief Moves player sprite
* 
*/ 
        void moveLeft();
/** @brief Moves player sprite
* 
*/ 
        void moveRight();
/** @brief Prevents movement of player sprite if horizontal inputs are pressed at the same time
* 
*/ 
        void noMovementX();
/** @brief Prevents movement of player sprite if vertical inputs are pressed at the same time
* 
*/ 
        void noMovementY();
/** @brief Accesor method for geometric center of payer sprite
* 
*  @returns center coordinates
*/ 
        sf::Vector2f getCenter();
/** @brief Method for accessing player sprite
* 
*  @returns player sprite
*/ 
        const sf::CircleShape &GetSprite() const;
/** @brief Renders player
* 
*/ 
		void Draw();

	private:
		GameDataRef _data;

		//sf::Sprite _playerSprite;
        sf::CircleShape _spaceShip;
        sf::Vector2f _playerCenter;
        int _xVelocity, _yVelocity;
        sf::Vector2f playerCenter;

	};
}



#endif /* PLAYER_H_ */
