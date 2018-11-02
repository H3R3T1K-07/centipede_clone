/** @brief Creates Mushroom objects
* 
*/ 

#ifndef MUSHROOM_H_
#define MUSHROOM_H_



#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "GameDefinitions.h"
#include "GameStates.h"
#include "GameLoop.h"

namespace Centipede
{
	class Mushroom
	{
	public:
/** @brief Class contructor
* 
*/ 
		Mushroom(GameDataRef data);
        ~Mushroom();
        
/** @brief Method for accessing mushroom sprite
* 
*  @returns mushroom sprite
*/  
        const sf::CircleShape &GetSprite() const;
        
        static int count;
        static int count2;
        
/** @brief Renders mushroom
* 
*/         
		void DrawMushroom();

	private:
		GameDataRef _data;
        sf::CircleShape _shroom;
		std::vector<sf::CircleShape> mushroomSprites;

	};
}


#endif /* MUSHROOM_H_*/