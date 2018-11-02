#include "Mushroom.h"

namespace Centipede
{
    int Mushroom::count = 1;
    int Mushroom::count2 = 0;
    
    void increaseObjectCount1()
    {
        Mushroom::count++;
        srand(time(NULL) + Mushroom::count);
    }
    
    void resetObjectCount1()
    {
        if(Mushroom::count > Mushroom::count2){Mushroom::count2++;}
            srand( time(NULL) + Mushroom::count2);
            Mushroom::count2*=Mushroom::count;
    }
	Mushroom::Mushroom(GameDataRef data) : _data(data)
	{
        srand(time(NULL));
        increaseObjectCount1();
        resetObjectCount1();
        _shroom.setRadius(10);
        _shroom.setPosition(rand()%760 + 20,rand()%660 + 20);
        _shroom.setFillColor(sf::Color::White);
        
        this->_data->resource.LoadTexture("Mushroom Sprite", MUSHROOM_SPRITE_FILEPATH);
		
         
        _shroom.setTexture(&this->_data->resource.GetTexture("Mushroom Sprite"));
	}
    
    Mushroom::~Mushroom()
	{
	}
    
    const sf::CircleShape &Mushroom::GetSprite() const
    {
        return _shroom;
    }
    

	void Mushroom::DrawMushroom()
	{
        _data->window.draw(_shroom);
	}
}