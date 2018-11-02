/** @brief Creates game play over state object
* 
*/ 
#ifndef GAMEPLAYOVER_H_
#define GAMEPLAYOVER_H_

#include <SFML/Graphics.hpp>
#include "GameStates.h"
#include "GameLoop.h"
#include <fstream>

namespace Centipede
{
	class GamePlayOver : public GameStates
	{
	public:
/** @brief Class constructor
* 
*/ 
		GamePlayOver(GameDataRef data, int score);
/** @brief Initialises state
* 
*/ 
		void Init();
/** @brief Manages user input
* 
*/ 
		void HandleInput();
/** @brief Updates changes to variables
* 
*/ 
		void Update(float dt);
/** @brief Renders changes
* 
*/ 
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
        sf::Text _gameOverTitle;
        
        sf::Text _scoreText;
		sf::Text _highScoreText;
        sf::Text _scoreTitle;
		sf::Text _highScoreTitle;
        sf::Text _splashInstruction;

		int _score;
		int _highScore;

	};
}







#endif /* GAMEPLAYOVER_H_*/