/** @brief Centipede segments for spawning the centipede
 */

#ifndef CENTIPEDE_H_
#define CENTIPEDE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "GameDefinitions.h"
#include "GameLoop.h"


namespace Centipede
{
	class Centi
	{
	public:
    
/** @brief Class constructor
* 
*/  
		Centi(GameDataRef data);
		~Centi();
        
        
/** @brief Moves centipede segment as required
* 
*/        
        void moveCentipede();

/** @brief Renderes centipede segment to game window
* 
*/         
		void DrawCentipede();

/** @brief Accessor method for centipede sprites
* 
*  @returns vector of centipede sprites 
*/        
        std::vector<sf::CircleShape> &GetSprites();
        
/** @brief Accessor method for centipede sprite
* 
*  @returns centipede sprite 
*/
        const sf::CircleShape &GetSprite() const;
        
        
        static int count;
        
	private:
		GameDataRef _data;
        sf::CircleShape _seg;
        std::vector<sf::CircleShape> _segs;
        bool _dir;
	};
}


#endif /* CENTIPEDE_H_ */
