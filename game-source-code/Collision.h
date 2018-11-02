/** @brief Helper class for collision management
 */

#ifndef COLLISION_H_
#define COLLISION_H_

#include <SFML/Graphics.hpp>

namespace Centipede
{
	class Collision
	{
	public:
/** @brief Class constructor
 */
		Collision();
		~Collision();

/** @brief Method for checking whether sprites overlap
* 
*  @returns True if sprites overlap, false otherwise
*/         
        bool checkSpriteCollision(sf::CircleShape sprite1, sf::CircleShape sprite2);

	};
}




#endif /* COLLISION_H_ */