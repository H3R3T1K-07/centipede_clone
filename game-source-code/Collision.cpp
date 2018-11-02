#include "Collision.h"

namespace Centipede
{
	Collision::Collision()
	{
	}

	Collision::~Collision()
	{
	}

	bool Collision::checkSpriteCollision(sf::CircleShape sprite1, sf::CircleShape sprite2)
	{

		if (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds()) == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}