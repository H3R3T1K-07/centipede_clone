#include <sstream>
#include "GameDefinitions.h"
#include "GamePlay.h"
#include "GamePlayOver.h"
#include "GamePlayFinished.h"

#include <iostream>

namespace Centipede
{
	GamePlay::GamePlay(GameDataRef data) : _data(data)
	{
        
	}

	void GamePlay::Init()
	{
		this->_data->resource.LoadTexture("Game Background", GAME_WINDOW_BACKGROUND_FILEPATH);
		this->_data->resource.LoadTexture("Player Sprite", PLAYER_SPRITE_FILEPATH);

        spaceShip = new Player(_data);
        bullet = new Projectile(_data);
        
        // centipede segments
        
        centi = new Centi(_data);
        centi2 = new Centi(_data);
        centi3 = new Centi(_data);
        centi4 = new Centi(_data);
        centi5 = new Centi(_data);
        centi6 = new Centi(_data);
        centi7 = new Centi(_data);
        centi8 = new Centi(_data);
        centi9 = new Centi(_data);
        centi10 = new Centi(_data);
        centi11 = new Centi(_data);
        centi12 = new Centi(_data);
        centi13 = new Centi(_data);
        centi14 = new Centi(_data);
        centi15 = new Centi(_data);
        
        mushroom = new Mushroom(_data);
        mushroom2 = new Mushroom(_data);
        mushroom3 = new Mushroom(_data);
        mushroom4 = new Mushroom(_data);
        mushroom5 = new Mushroom(_data);
        mushroom6 = new Mushroom(_data);
        mushroom7 = new Mushroom(_data);
        mushroom8 = new Mushroom(_data);
        mushroom9 = new Mushroom(_data);
        mushroom10 = new Mushroom(_data);
        mushroom11 = new Mushroom(_data);
        mushroom12 = new Mushroom(_data);
        mushroom13 = new Mushroom(_data);
        mushroom14 = new Mushroom(_data);
        mushroom15 = new Mushroom(_data);
        mushroom16 = new Mushroom(_data);
        mushroom17 = new Mushroom(_data);
        mushroom18 = new Mushroom(_data);
        mushroom19 = new Mushroom(_data);
        mushroom20 = new Mushroom(_data);
        mushroom21 = new Mushroom(_data);
        mushroom22 = new Mushroom(_data);
        mushroom23 = new Mushroom(_data);
        mushroom24 = new Mushroom(_data);
        mushroom25 = new Mushroom(_data);
        mushroom26 = new Mushroom(_data);
        
  
        flash = new FlashScreen(_data);
        score = new Score(_data);
		
        
        _shootTimer = 0;
        _score = 0;
        _centipedeCount = 15;
        _gameState = Game_States::eReady;

		_background.setTexture(this->_data->resource.GetTexture("Game Background"));
        score->UpdateScore(_score);
        
	}

	void GamePlay::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				this->_data->window.close();
			}
            
            if(event.type == sf::Event::KeyPressed ){
				if(event.key.code == sf::Keyboard::Right) rightButton  = true;
				if(event.key.code == sf::Keyboard::Left) leftButton= true;
				if(event.key.code == sf::Keyboard::Up) upButton = true;
				if(event.key.code == sf::Keyboard::Down) downButton = true;
				if(event.key.code == sf::Keyboard::Space) shootButton = true;
                
			}

			if(event.type == sf::Event::KeyReleased ){
				if(event.key.code == sf::Keyboard::Right) rightButton  = false;
				if(event.key.code == sf::Keyboard::Left) leftButton= false;
				if(event.key.code == sf::Keyboard::Up) upButton = false;
				if(event.key.code == sf::Keyboard::Down) downButton = false;
				if(event.key.code == sf::Keyboard::Space) shootButton = false;
			}
            
		}
        
       
        
	}

	void GamePlay::Update(float dt)
	{
        
        if(Game_States::ePlaying == _gameState )
         {
             if(centi != NULL){centi->moveCentipede();}
             if(centi2 != NULL){centi2->moveCentipede();}
             if(centi3 != NULL){centi3->moveCentipede();}
             if(centi4 != NULL){centi4->moveCentipede();}
             if(centi5 != NULL){centi5->moveCentipede();}
             if(centi6 != NULL){centi6->moveCentipede();}
             if(centi7 != NULL){centi7->moveCentipede();}
             if(centi8 != NULL){centi8->moveCentipede();}
             if(centi9 != NULL){centi9->moveCentipede();}
             if(centi10 != NULL){centi10->moveCentipede();}
             if(centi11 != NULL){centi11->moveCentipede();}
             if(centi12 != NULL){centi12->moveCentipede();}
             if(centi13 != NULL){centi13->moveCentipede();}
             if(centi14 != NULL){centi14->moveCentipede();}
             if(centi15 != NULL){centi15->moveCentipede();}
         }
        
        if (Game_States::eGameOver != _gameState)
         {
             
            if(leftButton == true){_gameState = Game_States::ePlaying; spaceShip->moveLeft();}
            if(rightButton == true){_gameState = Game_States::ePlaying; spaceShip->moveRight();;}
            if(leftButton == true && rightButton == true){spaceShip->noMovementX();}
            if(leftButton == false && rightButton== false){spaceShip->noMovementX();}

            if(upButton == true){_gameState = Game_States::ePlaying; spaceShip->moveUp();}
            if(downButton == true){_gameState = Game_States::ePlaying; spaceShip->moveDown();}
            if(upButton == true && downButton == true){spaceShip->noMovementY();}
            if(upButton == false && downButton == false){spaceShip->noMovementY();}
                
            if (_shootTimer < 20)
                _shootTimer++;

            if (shootButton == true && _shootTimer >= 20) //Shoot
            {
                bullet->loadShot(spaceShip->getCenter());

				_shootTimer = 0;
            }
            
            bullet->fireShot();
         }
          
            std::vector<sf::CircleShape> projectileSprites = bullet->GetSprites();
           
        /// centipede segment management 
 
            std::vector<sf::CircleShape> centipedeSprites;
            if(centi != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            

            
            if(centi2 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi2->GetSprites();
               for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi2;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi2 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            

            
            if(centi3 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi3->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi3;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi3 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            

            
            if(centi4 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi4->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi4;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi4 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            

            if(centi5 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi5->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi5;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi5 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            
            
            if(centi6 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi6->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi6;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi6 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            
            
            if(centi7 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi7->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi7;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi7 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            
            
            if(centi8 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi8->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi8;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi8 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
                        
            
            
            if(centi9 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi9->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi9;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi9 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
                        
            
            
            if(centi10 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi10->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi10;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi10 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            

            
            if(centi11 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi11->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi11;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi11 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            

            
            
            if(centi12 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi12->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi12;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi12 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            

            
            if(centi13 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi13->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi13;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi13 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            
            
            if(centi14 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi14->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi14;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi14 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            
            
            
            if(centi15 != NULL && Game_States::eGameOver != _gameState) 
            {
    
                centipedeSprites = centi15->GetSprites();
                for (int i = 0; i < centipedeSprites.size(); i++)
                {
                    if (collision.checkSpriteCollision(spaceShip->GetSprite(), centipedeSprites.at(i)))
                    {
                        _gameState = Game_States::eGameOver;
                        flash->Show(dt);
                        break;
                    }
                    
                    for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        if (collision.checkSpriteCollision(projectileSprites.at(j), centipedeSprites.at(i)))
                            { 
                                delete centi15;
                                projectileSprites.erase(projectileSprites.begin() + j);
                                _score = _score + 100;
                                centi15 = NULL;
                                _centipedeCount--;
                                score->UpdateScore(_score);
                                break;
                            }
                
                    }
                }
            }
            
            for(int j = 0; j < projectileSprites.size(); j++)
                    {
                        /// mushroom collision
                        if (mushroom != NULL && collision.checkSpriteCollision(mushroom->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom;
                            mushroom = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom2 != NULL && collision.checkSpriteCollision(mushroom2->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom2;
                            mushroom2 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom3 != NULL && collision.checkSpriteCollision(mushroom3->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom3;
                            mushroom3 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom4 != NULL && collision.checkSpriteCollision(mushroom4->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom4;
                            mushroom4 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom5 != NULL && collision.checkSpriteCollision(mushroom5->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom5;
                            mushroom5 = NULL;
                           _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom6 != NULL && collision.checkSpriteCollision(mushroom6->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom6;
                            mushroom6 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom7 != NULL && collision.checkSpriteCollision(mushroom7->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom7;
                            mushroom7 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom8 != NULL && collision.checkSpriteCollision(mushroom8->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom8;
                            mushroom8 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom9 != NULL && collision.checkSpriteCollision(mushroom9->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom9;
                            mushroom9 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom10 != NULL && collision.checkSpriteCollision(mushroom10->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom10;
                            mushroom10 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom11 != NULL && collision.checkSpriteCollision(mushroom11->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom11;
                            mushroom11 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom12 != NULL && collision.checkSpriteCollision(mushroom12->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom12;
                            mushroom12 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom13 != NULL && collision.checkSpriteCollision(mushroom13->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom13;
                            mushroom13 = NULL;
                            _score++;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom14 != NULL && collision.checkSpriteCollision(mushroom14->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom14;
                            mushroom14 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom15 != NULL && collision.checkSpriteCollision(mushroom15->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom15;
                            mushroom15 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom16 != NULL && collision.checkSpriteCollision(mushroom16->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom16;
                            mushroom16 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom17 != NULL && collision.checkSpriteCollision(mushroom17->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom17;
                            mushroom17 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom18 != NULL && collision.checkSpriteCollision(mushroom18->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom18;
                            mushroom18 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom19 != NULL && collision.checkSpriteCollision(mushroom19->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom19;
                            mushroom19 = NULL;
                           _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom20 != NULL && collision.checkSpriteCollision(mushroom20->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom20;
                            mushroom20 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom21 != NULL && collision.checkSpriteCollision(mushroom21->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom21;
                            mushroom21 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom22 != NULL && collision.checkSpriteCollision(mushroom22->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom22;
                            mushroom22 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom23 != NULL && collision.checkSpriteCollision(mushroom23->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom23;
                            mushroom23 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        if (mushroom24 != NULL && collision.checkSpriteCollision(mushroom24->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom24;
                            mushroom24 = NULL;
                           _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        if (mushroom25 != NULL && collision.checkSpriteCollision(mushroom25->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom25;
                            mushroom25 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        if (mushroom26 != NULL && collision.checkSpriteCollision(mushroom26->GetSprite(), projectileSprites.at(j)))
                        {
                            delete mushroom26;
                            mushroom26 = NULL;
                            _score = _score + 26;
                            score->UpdateScore(_score);
                        }
                        
                        
                    
                        ///////////////////////////////////////////////////////////////////////////////
                
                    }
            
            if ( _centipedeCount <= 0)
            {
                _gameState = Game_States::eFinished;
            }
            
            
            if (Game_States::eGameOver == _gameState )
            {
                if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
                {
                    this->_data->stateHandler.AddState(StateRef(new GamePlayOver(_data, _score)), true);
                }
            }
            
            if ( Game_States::eFinished == _gameState)
            {
                this->_data->stateHandler.AddState(StateRef(new GamePlayFinished(_data, _score)), true);
            }
            
            
	}

    
	

	void GamePlay::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);

		spaceShip->Draw();
        bullet->DrawProjectiles();
        
        if(centi != NULL){centi->DrawCentipede();}
        if(centi2 != NULL){centi2->DrawCentipede();}
        if(centi3 != NULL){centi3->DrawCentipede();}
        if(centi4 != NULL){centi4->DrawCentipede();}
        if(centi5 != NULL){centi5->DrawCentipede();}
        if(centi6 != NULL){centi6->DrawCentipede();}
        if(centi7 != NULL){centi7->DrawCentipede();}
        if(centi8 != NULL){centi8->DrawCentipede();}
        if(centi9 != NULL){centi9->DrawCentipede();}
        if(centi10 != NULL){centi10->DrawCentipede();}
        if(centi11 != NULL){centi11->DrawCentipede();}
        if(centi12 != NULL){centi12->DrawCentipede();}
        if(centi13 != NULL){centi13->DrawCentipede();}
        if(centi14 != NULL){centi14->DrawCentipede();}
        if(centi15 != NULL){centi15->DrawCentipede();}
        
        if(mushroom != NULL){mushroom->DrawMushroom();}
        if(mushroom2 != NULL){mushroom2->DrawMushroom();}
        if(mushroom3 != NULL){mushroom3->DrawMushroom();}
        if(mushroom4 != NULL){mushroom4->DrawMushroom();}
        if(mushroom5 != NULL){mushroom5->DrawMushroom();}
        if(mushroom6 != NULL){mushroom6->DrawMushroom();}
        if(mushroom7 != NULL){mushroom7->DrawMushroom();}
        if(mushroom8 != NULL){mushroom8->DrawMushroom();}
        if(mushroom9 != NULL){mushroom9->DrawMushroom();}
        if(mushroom10 != NULL){mushroom10->DrawMushroom();}
        if(mushroom11 != NULL){mushroom11->DrawMushroom();}
        if(mushroom12 != NULL){mushroom12->DrawMushroom();}
        if(mushroom13 != NULL){mushroom13->DrawMushroom();}
        if(mushroom14 != NULL){mushroom14->DrawMushroom();}
        if(mushroom15 != NULL){mushroom15->DrawMushroom();}
        if(mushroom16 != NULL){mushroom16->DrawMushroom();}
        if(mushroom17 != NULL){mushroom17->DrawMushroom();}
        if(mushroom18 != NULL){mushroom18->DrawMushroom();}
        if(mushroom19 != NULL){mushroom19->DrawMushroom();}
        if(mushroom20 != NULL){mushroom20->DrawMushroom();}
        if(mushroom21 != NULL){mushroom21->DrawMushroom();}
        if(mushroom22 != NULL){mushroom22->DrawMushroom();}
        if(mushroom23 != NULL){mushroom23->DrawMushroom();}
        if(mushroom24 != NULL){mushroom24->DrawMushroom();}
        if(mushroom25 != NULL){mushroom25->DrawMushroom();}
        if(mushroom26 != NULL){mushroom26->DrawMushroom();}
        
    
        flash->Draw();
        
        score->Draw();
        
		this->_data->window.display();
	}
}