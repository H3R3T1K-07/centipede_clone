#include <sstream>
#include "SplashScreen.h"
#include "GameDefinitions.h"
#include "GamePlay.h"


#include <iostream>

namespace Centipede
{
	SplashScreen::SplashScreen(GameDataRef data) : _data(data)
	{

	}

	void SplashScreen::Init()
	{
		this->_data->resource.LoadFont("Splash Screen Font", SPLASH_SCREEN_FONT_FILEPATH);
        this->_data->resource.LoadTexture("Splash Screen Background", SPLASH_SCREEN_BACKGROUND_FILEPATH );

		_background.setTexture(this->_data->resource.GetTexture("Splash Screen Background"));
        _title.setFont(this->_data->resource.GetFont("Splash Screen Font"));
        _splashInstruction.setFont(this->_data->resource.GetFont("Splash Screen Font"));
        _playInstructions.setFont(this->_data->resource.GetFont("Splash Screen Font"));
        _title.setCharacterSize(70);
        _splashInstruction.setCharacterSize(20);
        _playInstructions.setCharacterSize(20);
        _title.setString("CENTIPEDE");
        _splashInstruction.setString("Press ENTER Key to start or Press ESCAPE key at any point to quit");
        _playInstructions.setString("Use Keyboard Arrow Keys to Move Spaceship, Press SPACE key to Fire");
        _title.setPosition(SCREEN_WIDTH/2 - 200,SCREEN_HEIGHT/2 - 200);
        _splashInstruction.setPosition(95,360);
        _playInstructions.setPosition(80,400);
        _title.setColor(sf::Color::Green);
        _playInstructions.setColor(sf::Color::Magenta);
        
	}

	void SplashScreen::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				this->_data->window.close();
			}
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			{
				// Switch To Main Menu
				this->_data->stateHandler.AddState(StateRef(new GamePlay(_data)), true);
			}
		}
	}
    


	void SplashScreen::Update(float dt)
	{

	}

	void SplashScreen::Draw(float dt)
	{
		this->_data->window.clear();
        
        this->_data->window.draw(this->_background);
		this->_data->window.draw( this->_title );
        this->_data->window.draw( this->_splashInstruction );
        this->_data->window.draw( this->_playInstructions );

		this->_data->window.display();
         
	}
}

