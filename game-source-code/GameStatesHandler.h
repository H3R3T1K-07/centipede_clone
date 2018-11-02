/** @brief Helper object for managing states
* 
*/

#ifndef GAMESTATESHANDLER_H_
#define GAMESTATESHANDLER_H_

#include <memory>
#include <stack>

#include "GameStates.h"

namespace Centipede
{
	typedef std::unique_ptr<GameStates> StateRef;

	class GameStatesHandler
	{
	public:
/** @brief Class constructor
* 
*/ 
		GameStatesHandler() { }
		~GameStatesHandler() { }
        
/** @brief Adds a new state to the progam stack
* 
*/
		void AddState(StateRef newState, bool isReplacing = true);
/** @brief Removes active state from the progam stack
* 
*/        
		void RemoveState();
        
		// Run at start of each loop in Game.cpp
        
/** @brief Process state changes
* 
*/
		void ProcessStateChanges();

		StateRef &GetActiveState();

	private:
		std::stack<StateRef> _states;
		StateRef _newState;

		bool _isRemoving;
		bool _isAdding, _isReplacing;
	};
}

#endif /* GAMESTATESHANDLER_H_ */