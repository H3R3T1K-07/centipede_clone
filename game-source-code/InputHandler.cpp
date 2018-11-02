#include "InputHandler.h"

namespace Centipede
{
	bool InputHandler::isMovedUp()
	{
        if(sf::Keyboard::Up)
            return true;
        else
            return false;
	}

    bool InputHandler::isMovedDown()
	{
        if(sf::Keyboard::Down)
            return true;
        else
            return false;
	}

    bool InputHandler::isMovedLeft()
	{
        if(sf::Keyboard::Left)
            return true;
        else
            return false;
	}

    bool InputHandler::isMovedRight()
	{
        if(sf::Keyboard::Right)
            return true;
        else
            return false;
	}
    
    bool InputHandler::isNotMovedAlongX()
	{
        if(sf::Keyboard::Left && sf::Keyboard::Right)
            return true;
        else
            return false;
	}

    bool InputHandler::isNotMovedAlongY()
	{
        if(sf::Keyboard::Up && sf::Keyboard::Down)
            return true;
        else
            return false;
	}

}