/** @brief Helper object for managing user inputs
* 
*/
#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "SFML\Graphics.hpp"

namespace Centipede
{
	class InputHandler
	{
	public:
		InputHandler() {}
		~InputHandler() {}
        
        bool isMovedUp();
        bool isMovedDown();
        bool isMovedLeft();
        bool isMovedRight();
        bool isNotMovedAlongX();
        bool isNotMovedAlongY();
        
		//bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);


	};
}



#endif /* INPUTHANDLER_H_ */