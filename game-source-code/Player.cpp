#include "Player.h"

// you need this because of forward declaration
#include <SFML/Graphics.hpp>


namespace Centipede
{
	Player::Player(GameDataRef data) : _data(data)
	{
        _xVelocity = 0;
        _yVelocity = 0;
        _spaceShip.setRadius(10);
        _spaceShip.setPosition(SCREEN_WIDTH/2 - _spaceShip.getRadius(), SCREEN_HEIGHT - _spaceShip.getRadius()*2 - 5);
        _spaceShip.setFillColor(sf::Color::White);
        this->_data->resource.LoadTexture("Player Sprite", PLAYER_SPRITE_FILEPATH);
		
         
        _spaceShip.setTexture(&this->_data->resource.GetTexture("Player Sprite"));
         playerCenter = sf::Vector2f(_spaceShip.getPosition().x+_spaceShip.getRadius(), _spaceShip.getPosition().y + _spaceShip.getRadius());
	}

	Player::~Player()
	{
	}
    
    void Player::moveUp()
    {
        _yVelocity = -1;
        _spaceShip.move(0, _yVelocity);
        if(_spaceShip.getPosition().y <=  679)
        {
            _spaceShip.move(0, -_yVelocity);
        }


        if(_spaceShip.getPosition().y > 779)
        {
            _spaceShip.move(0, -_yVelocity);
        }

        playerCenter = sf::Vector2f(_spaceShip.getPosition().x+_spaceShip.getRadius(), _spaceShip.getPosition().y + _spaceShip.getRadius());
    }

    void Player::moveDown()
    {
        _yVelocity = 1;
        _spaceShip.move(0, _yVelocity);
        if(_spaceShip.getPosition().y <=  679)
        {
            _spaceShip.move(0, -_yVelocity);
        }


        if(_spaceShip.getPosition().y > 779)
        {
            _spaceShip.move(0, -_yVelocity);
        }

        playerCenter = sf::Vector2f(_spaceShip.getPosition().x+_spaceShip.getRadius(), _spaceShip.getPosition().y + _spaceShip.getRadius());
    }

    void Player::moveLeft()
    {
        _xVelocity = -1;
        _spaceShip.move(_xVelocity, 0);
        if(_spaceShip.getPosition().x <= 0)
        {
            _spaceShip.move(-_xVelocity, 0);
        }
        if(_spaceShip.getPosition().x > 779)
        {
            _spaceShip.move(-_xVelocity, 0);
        }

        playerCenter = sf::Vector2f(_spaceShip.getPosition().x+_spaceShip.getRadius(), _spaceShip.getPosition().y + _spaceShip.getRadius());
    }

    void Player::moveRight()
    {
        _xVelocity = 1;
        _spaceShip.move(_xVelocity, 0);
        if(_spaceShip.getPosition().x <= 0)
        {
            _spaceShip.move(-_xVelocity, 0);
        }
        if(_spaceShip.getPosition().x > 779)
        {
            _spaceShip.move(-_xVelocity, 0);
        }

        playerCenter = sf::Vector2f(_spaceShip.getPosition().x+_spaceShip.getRadius(), _spaceShip.getPosition().y + _spaceShip.getRadius());
    }

    void Player::noMovementX()
    {
        _xVelocity = 0;
    }

    void Player::noMovementY()
    {
        _yVelocity = 0;
    }

    sf::Vector2f Player::getCenter()
    {
        return playerCenter;
    }
    

	void Player::Draw()
	{
		//_data->window.draw(_playerSprite);
        _data->window.draw(_spaceShip);
	}
    
    const sf::CircleShape &Player::GetSprite() const
    {
        return _spaceShip;
    }
    
}

