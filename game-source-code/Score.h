/** @brief Creates score helper object
* 
*/ 
#ifndef SCORE_H_
#define SCORE_H_

#include <SFML/Graphics.hpp>

#include "GameDefinitions.h"
#include "GameLoop.h"

namespace Centipede
{
	class Score
	{
	public:
/** @brief Class constructor
* 
*/    
		Score(GameDataRef data);
		~Score();
/** @brief Renders changes
* 
*/ 
		void Draw();
/** @brief Update changes
* 
*/ 
		void UpdateScore(int score);

	private:
		GameDataRef _data;

		sf::Text _scoreText;
        sf::Text _scoreTitle;

	};
}

#endif /* SCORE_H_ */