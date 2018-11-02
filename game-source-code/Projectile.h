/** @brief Creates projectile object
* 
*/ 
#ifndef PROJECTILE_H_
#define PROJECTILE_H_


#include <SFML/Graphics.hpp>
#include "GameLoop.h"
#include <vector>


namespace Centipede
{
	class Projectile
	{
	public:
/** @brief Class contructor
* 
*/ 
		Projectile(GameDataRef data);
		~Projectile();
/** @brief shoot projectile
* 
*/        
        void fireShot();
/** @brief load projectile sprite
* 
*/        
        void loadShot(sf::Vector2f);
/** @brief Accesor method for geometric center of projectile sprite
* 
*  @returns center coordinates
*/ 
        sf::Vector2f getCenter();
/** @brief Accesor method for projecile sprite
* 
*  @returns vector of projecile sprites
*/ 
        std::vector<sf::CircleShape> &GetSprites();
/** @brief Renders player
* 
*/ 
        void DrawProjectiles();

	private:
		GameDataRef _data;
        sf::CircleShape _projectile;
		std::vector<sf::CircleShape> _Projectiles;
        sf::Vector2f _projetileCenter;

	};

}













/*
class MyDrawableTransformable : public sf::Drawable, public sf::Transformable{
public:
        MyDrawableTransformable() {};
        ~MyDrawableTransformable() {};
};

class Projectile : public MyDrawableTransformable
{
    public:
        sf::CircleShape circle;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            states.transform *= getTransform();
            target.draw(circle, states);
        }

    private:
        sf::CircleShape projectile;
        vector<sf::MyDrawableTransformable> projectiles;
};

*/











#endif /* PROJECTILE_H_ */
