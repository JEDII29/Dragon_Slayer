#include <iostream>
#include <cmath>
#include "Character.h"

Player::Player()
{
	Textr = new sf::Texture;
	Textr->loadFromFile("HeroTexture.png");
	Animation = new PlayerAnimation(Textr, sf::Vector2u(2,8), 0.3f);
	Body.setTexture(*Textr);
	Body.setScale(3.0f, 3.0f);
	Body.setPosition(180.0f, 300.0f);
	Drt = down;
	Speed = 18;
	Movement.x = 0.0f;
	Movement.y = 0.0f;
	IsMoving = false;

}

void Player::Update(const float& elapsed)
{
	Direction drt = Drt;
	if (Movement.x != 0 || Movement.y != 0)
	{
		Walk(drt, elapsed);
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			Movement.x = 1;
			drt = right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			Movement.x = (-1);
			drt = left;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			Movement.y = 1;
			drt = down;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			Movement.y = (-1);
			drt = up;
		}

		if (Movement.x != 0.0f || Movement.y != 0.0f)
			Walk(drt, elapsed);
	}

}


void Player::Walk(Direction _drt , const float& _elapsed)
{

	if (_drt == Drt)
	{
		Body.move(Movement.x * Speed * _elapsed * 10, Movement.y * Speed * _elapsed * 10);
		IsMoving = true;
		if (((fmod(Body.getPosition().x, 60.0f) >= 58.0f || fmod(Body.getPosition().x, 60.0f) <= 2.0f) && fmod(Body.getPosition().y, 60.0f) == 0.0f)||
			((fmod(Body.getPosition().y, 60.0f) >= 58.0f || fmod(Body.getPosition().y, 60.0f) <= 2.0f) && fmod(Body.getPosition().x, 60.0f) == 0.0f))
		{
			Movement.x = 0;
			Movement.y = 0;
			Body.setPosition(round(Body.getPosition().x/10)*10, round(Body.getPosition().y/10) * 10);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			{
			}
			else
				IsMoving = false;
		}
		
	}	
	else
	{
		Drt = _drt;
		Movement.x = 0.0f;
		Movement.y = 0.0f;
	}

}
