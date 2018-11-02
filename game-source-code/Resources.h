/** @brief Creates score resources object
* 
*/ 
#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <map>
#include <SFML/Graphics.hpp>


namespace Centipede
{
	class Resources
	{
	public:
/** @brief Class constructor
* 
*/     
		Resources() { }
		~Resources() { }
/** @brief Loads texture
* 
*/ 
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);
/** @brief Loads Fonts
* 
*/
		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);
        
	private:
        // conveniently store resources
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
	};
}

#endif /* RESOURCES_H_ */