#include "Score.h"

#include <string>

namespace Centipede
{
	Score::Score(GameDataRef data) : _data(data)
	{
        
		_scoreText.setFont(this->_data->resource.GetFont("Splash Screen Font"));
        _scoreTitle.setFont(this->_data->resource.GetFont("Splash Screen Font"));
		_scoreText.setString("0");
        _scoreTitle.setString("SCORE:");
		_scoreText.setCharacterSize(25);
        _scoreTitle.setCharacterSize(20);
		_scoreText.setFillColor(sf::Color::White);
        _scoreTitle.setFillColor(sf::Color::White);

		_scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
		_scoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 2, 5));
        _scoreTitle.setPosition(sf::Vector2f(_data->window.getSize().x / 2 - 100, 0));
	}

	Score::~Score()
	{
	}

	void Score::Draw()
	{
		_data->window.draw(_scoreText);
        _data->window.draw(_scoreTitle);
	}

	void Score::UpdateScore(int score)
	{
		_scoreText.setString(std::to_string(score));
	}
}