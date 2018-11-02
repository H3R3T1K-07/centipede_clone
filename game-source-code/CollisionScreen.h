/** @brief Helper class for collision Indication
 */

#ifndef COLLISIONSCREEN_H_
#define COLLISIONSCREEN_H_

#include <SFML/Graphics.hpp>
#include "GameDefinitions.h"
#include "GameLoop.h"


namespace Centipede
{
	class FlashScreen
	{
	public:
/** @brief Class constructor
* 
*/ 
		FlashScreen(GameDataRef data);
		~FlashScreen();
        
/** @brief Implements flashing of game window
* 
*/ 
		void Show(float dt);

/** @brief Renders the flash
* 
*/         
		void Draw();

	private:
		GameDataRef _data;

		sf::RectangleShape _shape;

		bool _flashOn;

	};
}

#endif /* COLLISIONSCREEN_H_ */