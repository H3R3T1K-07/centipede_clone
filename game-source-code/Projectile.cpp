#include "Projectile.h"


namespace Centipede
{
	Projectile::Projectile(GameDataRef data) : _data(data)
	{
        _projectile.setFillColor(sf::Color::Red);
        _projectile.setRadius(2);
	}
    
    Projectile::~Projectile()
	{
	}
    
    void Projectile::loadShot(sf::Vector2f playerCenter)
    {
        _projectile.setPosition(playerCenter);
         _projetileCenter = playerCenter;
        _Projectiles.push_back(sf::CircleShape(_projectile));
    }
    void Projectile::fireShot()
    {
        for (unsigned short int i = 0; i < _Projectiles.size(); i++)
			{
				_Projectiles[i].move(0, -10);
                _projetileCenter = sf::Vector2f(_Projectiles[i].getPosition().x+_Projectiles[i].getRadius(), _Projectiles[i].getPosition().y + _Projectiles[i].getRadius());
				if(_Projectiles[i].getPosition().y <= 0)
					_Projectiles.erase(_Projectiles.begin() + i);
			}
    }
    
    std::vector<sf::CircleShape> &Projectile::GetSprites()
    {
        return _Projectiles;
    }
    
    sf::Vector2f Projectile::getCenter()
    {
        return _projetileCenter;
    }

	void Projectile::DrawProjectiles()
	{
		for (unsigned short int i = 0; i < _Projectiles.size(); i++)
		{
			this->_data->window.draw(_Projectiles.at(i));
		}
	}
}

