/** @brief Creates main game object
* 
*/ 

#ifndef GAMELOOP_H_
#define GAMELOOP_H_

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameStatesHandler.h"
#include "Resources.h"
#include "InputHandler.h"

namespace Centipede
{
/** @brief Creates objects with special attributes
* 
*/ 
	struct GameData
	{
		GameStatesHandler stateHandler;
		sf::RenderWindow window;
		Resources resource;
        InputHandler input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
/** @brief Constuctor for game object
* 
*/ 
		Game(int width, int height, std::string title);

	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}


#endif /* GAMELOOP_H_ */