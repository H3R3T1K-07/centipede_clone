/** @brief Creates splash play state object
* 
*/ 
#ifndef SPLASHSCREEN_H_
#define SPLASHSCREEN_H_

#include <SFML/Graphics.hpp>
#include "GameStates.h"
#include "GameLoop.h"

namespace Centipede
{
	class SplashScreen : public GameStates
	{
	public:
/** @brief Class constructor
* 
*/ 
		SplashScreen(GameDataRef data);
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
        sf::Text _title, _splashInstruction, _playInstructions;

	};
}

#endif /* SPLASHSCREEN_H_ */