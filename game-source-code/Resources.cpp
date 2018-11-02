#include <SFML/Graphics.hpp>
#include "Resources.h"

namespace Centipede
{
	void Resources::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture &Resources::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void Resources::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font &Resources::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}