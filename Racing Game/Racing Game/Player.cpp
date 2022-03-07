/// <summary>
/// Michal Rapciak
/// </summary>

#pragma once
#include "Player.h"
#include <math.h>
#include <iostream>

Player::Player()
{
	loadImage();

	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2;
	direction = 270;
	playerSprite.setRotation(direction);
	setPosition(position);  // set the position of the players sprite
}

void Player::loadImage()
// Loads the image for the player object
{
	if (!playerTexture.loadFromFile("ASSETS/IMAGES/car.png"))
	{
		std::cout << "error with player car file";
	}

	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(0.1, 0.1);
	playerSprite.setOrigin(340, 170);
}

void Player::moveForward()
{
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y -= 2.0;
	}
	*/
}
void Player::moveLeft()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//direction = 180.0f * headingRadians / static_cast<float>(M_PI);
		//headingDegree += 90.0f;
		playerSprite.setRotation(direction);
	}
}
void Player::moveRight()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//headingDegree += 90.0f;
	}
}

void Player::moveBack()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//headingDegree += 90.0f;
	}
}

void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.y -= 0.10;
		/*
		float headingRadians = std::atan2(velocity.y, velocity.x);
		float headingDegree = 180.0f * headingRadians / static_cast<float>(3.14159265);
		*/
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y += 0.05;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction -= 1;
		velocity.x -= 0.05;
		velocity.y -= 0.05;
		playerSprite.setRotation(direction);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction += 1;
		velocity.x += 0.05;
		velocity.y += 0.05;
		playerSprite.setRotation(direction);
	}
	position += velocity;
	std::cout << "Y" << velocity.y << std::endl;
	std::cout << "DEGREES" << direction << std::endl;
	playerSprite.setPosition(position);
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (velocity.y < 0))
	{
		velocity.y += 0.10;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (velocity.y > 0))
	{
		velocity.y -= 0.10;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (velocity.x < 0))
	{
		velocity.x += 0.10;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (velocity.x > 0))
	{
		velocity.x -= 0.10;
	}
}

sf::Sprite Player::returnSprite()
{
	return playerSprite;
}

void Player::setPosition(sf::Vector2f position)
{
	playerSprite.setPosition(position);
}