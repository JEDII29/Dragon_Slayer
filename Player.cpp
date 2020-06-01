#include <iostream>
#include "Character.h"

Player::Player()
{
	Textr.loadFromFile("guy.png");
	Body.setTexture(Textr);
	Body.setPosition(200.0f, 300.0f);
	Drt = down;

}

void Player::Walk(Direction _drt , const sf::Time& _elapsed)
{
	switch (_drt)
	{
	case down:
	{
		if (_drt == Drt)
			Body.move(0.0f , 10.0f * _elapsed.asSeconds() * 10);
		else
			Drt = _drt;
		break;
	}
	case up:
	{
		if (_drt == Drt)
			Body.move(0.0f , 10.0f * _elapsed.asSeconds() * -10);
		else
			Drt = _drt;
		break;
	}
	case right:
	{
		if (_drt == Drt)
			Body.move(10.0f * _elapsed.asSeconds() * 10 , 0.0f);
		else
			Drt = _drt;
		break;
	}
	case left:
	{
		if (_drt == Drt)
			Body.move(10.0f * _elapsed.asSeconds() * -10 , 0.0f);
		else
			Drt = _drt;
		break;
	}
	}
}
