#include <sstream>
#include "GameDefinitions.h"
#include "GamePlayOver.h"
#include "GamePlay.h"

#include <iostream>

namespace Centipede
{
	GamePlayOver::GamePlayOver(GameDataRef data, int score) : _data(data), _score(score)
	{

	}

	void GamePlayOver::Init()
	{
        std::ifstream readFile;
        readFile.open("Resources/Highscore.txt");
        
        
        if (readFile.is_open())
        {
            while (!readFile.eof())
            {
                readFile >> _highScore;
            }
        }
        
        
        readFile.close();
        
        std::ofstream writeFile("Resources/Highscore.txt");
        
        if (writeFile.is_open())
        {
            if (_score > _highScore)
            {
                _highScore = _score;
            }
            
            writeFile << _highScore;
        }
        
        writeFile.close();
        
		this->_data->resource.LoadTexture("Game Over Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->resource.GetTexture("Game Over Background"));
        
        this->_data->resource.LoadFont("Splash Screen Font", SPLASH_SCREEN_FONT_FILEPATH);
        this->_data->resource.LoadTexture("Splash Screen Background", SPLASH_SCREEN_BACKGROUND_FILEPATH );

		_background.setTexture(this->_data->resource.GetTexture("Splash Screen Background"));
        _gameOverTitle.setFont(this->_data->resource.GetFont("Splash Screen Font"));

        _gameOverTitle.setCharacterSize(70);

        _gameOverTitle.setString("GAME OVER");

       // _gameOverTitle.setPosition(SCREEN_WIDTH/2 - 200,SCREEN_HEIGHT/2 - 200);
        
        _gameOverTitle.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - 200 , (_data->window.getSize().y / 2) - 200));

        _gameOverTitle.setColor(sf::Color::Red);
        
        _scoreText.setFont(this->_data->resource.GetFont("Splash Screen Font"));
        _scoreText.setString(std::to_string(_score));
        _scoreText.setCharacterSize(56);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
        _scoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15));
        
        _highScoreText.setFont(this->_data->resource.GetFont("Splash Screen Font"));
        _highScoreText.setString(std::to_string(_highScore));
        _highScoreText.setCharacterSize(56);
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(sf::Vector2f(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2));
        _highScoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78));
        
        _scoreTitle.setFont(this->_data->resource.GetFont("Splash Screen Font"));
        _scoreTitle.setString("SCORE");
        _scoreTitle.setCharacterSize(56);
        _scoreTitle.setFillColor(sf::Color::White);
        _scoreTitle.setOrigin(sf::Vector2f(_scoreTitle.getGlobalBounds().width / 2, _scoreTitle.getGlobalBounds().height / 2));
        _scoreTitle.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25 - 400, _data->window.getSize().y / 2.15));
        
        _highScoreTitle.setFont(this->_data->resource.GetFont("Splash Screen Font"));
        _highScoreTitle.setString("HIGH SCORE");
        _highScoreTitle.setCharacterSize(56);
        _highScoreTitle.setFillColor(sf::Color::White);
        _highScoreTitle.setOrigin(sf::Vector2f(_highScoreTitle.getGlobalBounds().width / 2, _highScoreTitle.getGlobalBounds().height / 2));
        _highScoreTitle.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25 - 400, _data->window.getSize().y / 1.78));
        
        _splashInstruction.setFont(this->_data->resource.GetFont("Splash Screen Font"));
        _splashInstruction.setCharacterSize(20);
        _splashInstruction.setString("Press ENTER Key to restart or Press ESCAPE key at any point to quit");
        _splashInstruction.setPosition(95,600);
        _splashInstruction.setColor(sf::Color::Magenta);
	}

	void GamePlayOver::HandleInput()
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

	void GamePlayOver::Update(float dt)
	{

	}

	void GamePlayOver::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
        
        this->_data->window.draw( this->_gameOverTitle );
        
        _data->window.draw(_scoreText);
        _data->window.draw(_highScoreText);
        _data->window.draw(_scoreTitle);
        _data->window.draw(_highScoreTitle);

		this->_data->window.display();
	}
}