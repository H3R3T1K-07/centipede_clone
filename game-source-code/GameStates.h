/** @brief Parent base class for state classes
* 
*/ 
#ifndef GAMESTATES_H_
#define GAMESTATES_H_


namespace Centipede
{
     class GameStates
	{
	public:
/** @brief Initialises state
* 
*/     
		virtual void Init() = 0;
/** @brief Manages user input
* 
*/ 
		virtual void HandleInput() = 0;
/** @brief Updates changes to variables
* 
*/
		virtual void Update(float dt) = 0;
/** @brief Renders changes
* 
*/         
		virtual void Draw(float dt) = 0;

		virtual void Pause() { }
		virtual void Resume() { }
	};
}

#endif /* GAMESTATES_H_ */