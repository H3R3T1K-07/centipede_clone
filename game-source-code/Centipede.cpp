#include "Centipede.h"



namespace Centipede
{
    int Centi::count = 0;
    
    bool IsRowEven(int y) //Move right
    {
        double i = y + 30;
        i = i/40;
        int j = static_cast<int>(i);

        if (j==i){return true;}
        if (j!=i){return false;}
    }
    
    void increaseObjectCount()
    {
        Centi::count++;
    }
    
    void resetObjectCount()
    {
        if(Centi::count >= 15){Centi::count = 0;}
        
    }
    
    
	Centi::Centi(GameDataRef data) : _data(data)
	{
        _seg.setFillColor(sf::Color::Magenta);
        _seg.setRadius(10);
        
        this->_data->resource.LoadTexture("Centipede Sprite", CENTIPEDE_SPRITE_FILEPATH);
		
         
        _seg.setTexture(&this->_data->resource.GetTexture("Centipede Sprite"));
        _segs.clear(); // Makes sure vector is empty before use

        _dir = false; // centipede direction controller
        
        resetObjectCount();
        increaseObjectCount();
        
        _seg.setPosition(780,10);
        _seg.move(-20*count,0);
        _segs.push_back(sf::CircleShape(_seg));
        
        
       /* if (_segs.size()<SEG_SIZE)
        {
            for (unsigned short int i = 0; i < SEG_SIZE; i++)
            {
                _seg.setPosition(780,10);

                _segs.push_back(sf::CircleShape(_seg));

                    for (size_t j = 0; j <= i ; j++)
                    {
                       // _segs[j].move(-20,0);
                    }
                    
            }
        }
        */
	}
    
    Centi::~Centi()
	{
	}
    
    void Centi::moveCentipede()
    {
  
        //downward movement of centipede
        if(_segs.size()== SEG_SIZE && _dir == false){
            for (unsigned short int i = 0; i < _segs.size() && _dir!= true; i++)
            {
                if(_segs[0].getPosition().x ==780 && _segs[0].getPosition().y ==730){_dir = true;} // reached player area


                if (_segs[i].getPosition().x <=10 && IsRowEven(_segs[i].getPosition().y)== false){
                        _segs[i].move(-20,0); //move left
                        _segs[i].move(0,20); //move down
                }

                if (_segs[i].getPosition().x >=10 && IsRowEven(_segs[i].getPosition().y)== false)
                    _segs[i].move(-20,0); //move left

                if (_segs[i].getPosition().x <790 && IsRowEven(_segs[i].getPosition().y)== true)
                    _segs[i].move(20,0); //move right

                if (_segs[i].getPosition().x >=790 && IsRowEven(_segs[i].getPosition().y)== true){
                    _segs[i].move(0,20); //move down
                    _segs[i].move(-20,0); //move left
                }
            }
        }


        //keep centipede in player area. WORK IN PROGRESS
        if(_dir == true){
            for(unsigned short int i = 0; i < SEG_SIZE; i++)
            {
                if (_segs[i].getPosition().x >=0 && _segs[i].getPosition().x <=790 && _segs[i].getPosition().y == 730)
                    _segs[i].move(20,0); //move right


                if (_segs[i].getPosition().x <=10 && _segs[i].getPosition().y== 750){
                    _segs[i].move(0,-20); //move up
                }


                if (_segs[i].getPosition().x >=790 && _segs[i].getPosition().y== 730){
                    _segs[i].move(0,20); //move down
                }

                if (_segs[i].getPosition().x >=10 && _segs[i].getPosition().x <=800 && _segs[i].getPosition().y == 750)
                    _segs[i].move(-20,0); //move left
            }
        }

    }
    
    std::vector<sf::CircleShape> &Centi::GetSprites() 
    {
        return _segs;
    }
    
    const sf::CircleShape &Centi::GetSprite() const
    {
        return _seg;
    }
    
    void Centi::DrawCentipede()
    { 
           for (unsigned short int i = 0; i < _segs.size(); i++)
			{
				this->_data->window.draw(_segs[i]);
			}
    }
}




