#include <iostream>
#include "Character.h"

Player::Player()
{
	Textr = new sf::Texture;
	Textr->loadFromFile("HeroTexture.png");
	Animation = new PlayerAnimation(Textr, sf::Vector2u(2,4), 0.35f);
	Body.setTexture(*Textr);
	Body.setScale(3.0f, 3.0f);
	Body.setPosition(200.0f, 300.0f);
	Drt = down;
	Speed = 20;

}



void Player::Walk(Direction _drt , const sf::Time& _elapsed)
{
	switch (_drt)
	{
	case down:
	{
		if (_drt == Drt)
			Body.move(0.0f , Speed * _elapsed.asSeconds() * 10);
		else
		{
			Drt = _drt;
		}
		break;
	}
	case up:
	{
		if (_drt == Drt)
			Body.move(0.0f , Speed * _elapsed.asSeconds() * -10);
		else
			Drt = _drt;
		break;
	}
	case right:
	{
		if (_drt == Drt)
			Body.move(Speed * _elapsed.asSeconds() * 10 , 0.0f);
		else
			Drt = _drt;
		break;
	}
	case left:
	{
		if (_drt == Drt)
			Body.move(Speed * _elapsed.asSeconds() * -10 , 0.0f);
		else
			Drt = _drt;
		break;
	}
	}
}
