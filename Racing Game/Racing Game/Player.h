/// <summary>
/// Michal Rapciak
/// </summary>

#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Globals.h"

class Player
{
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	float direction;
	//int speed;
	sf::Vector2f velocity;
	sf::Vector2f position;

public:

	Player();
	void loadImage();
	void moveForward();
	void moveLeft();
	void moveRight();
	void moveBack();
	void movement();
	sf::Sprite returnSprite();
	void setPosition();
	void setPosition(sf::Vector2f position);
};