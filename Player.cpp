#include <iostream>
#include <cmath>
#include "Character.h"

Player::Player()
{
	Textr = new sf::Texture;
	FightTextr = new sf::Texture;
	Textr->loadFromFile("HeroTexture.png");
	FightTextr->loadFromFile("HeroStance.png");
	Animation = new PlayerAnimation(Textr, sf::Vector2u(2,8), 0.3f);
	Body.setTexture(*Textr);
	Body.setScale(3.0f, 3.0f);
	Body.setPosition(540.0f, 480.0f);
	FightBody.setTexture(*FightTextr);
	FightBody.setScale(2.0f, 2.0f);
	FightBody.setPosition(300.0f, 400.0f);
	Speed = 180;
	Movement.x = 0.0f;
	Movement.y = 0.0f;
	IsMoving = false;
	PositionIndeks.x = Body.getPosition().x / 60;
	PositionIndeks.y = Body.getPosition().y / 60;
	Drt = down;

	MoveList.push_back(new PhysicalAttack("poke", 2, 0));
	MoveList.push_back(new PhysicalAttack("punch", 5, 5));
	MoveList.push_back(new PhysicalAttack("slash", 15, 20));
	HoldingWeapon = new Weapon(5);
	LifePoints = 100;
	StaminaPoints = 100;
	Checked = false;
	Maxhealth = 100;
	MaxStamina = 100;
	Lvl = 1;
}

void Player::Update(const float& elapsed)
{
	Direction drt = Drt;
	if ((Movement.x != 0.0f || Movement.y != 0.0f))
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
		Drt = drt;
		if (Movement.x != 0.0f || Movement.y != 0.0f)
			Walk(drt, elapsed);
	}

	Animation->Update(Drt, elapsed, IsMoving);
	Body.setTextureRect(Animation->UvRect);


	//Direction drt = Drt;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	//{
	//	Movement.x = 1;
	//	drt = right;
	//	IsMoving = true;
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	//{
	//	Movement.x = (-1);
	//	drt = left;
	//	IsMoving = true;
	//}

	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	//{
	//	Movement.y = 1;
	//	drt = down;
	//	IsMoving = true;
	//}

	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	//{
	//	Movement.y = (-1);
	//	drt = up;
	//	IsMoving = true;
	//}

	//if (IsMoving == true && drt == Drt)
	//	Walk(drt, elapsed);

	//Drt = drt;
	

}


void Player::Walk(Direction _drt , const float& _elapsed)
{
	//if (PositionIndeks.x == Body.getPosition().x || PositionIndeks.y == Body.getPosition().y)
	//{
	//	PositionIndeks.x += Movement.x;
	//	PositionIndeks.y += Movement.y;
	//}
	//Body.move(Movement.x * Speed * _elapsed, Movement.y * Speed * _elapsed);
	//if(Body.getPosition().x )

		if (_drt == Drt)
	{
		Body.move(Movement.x * Speed * _elapsed, Movement.y * Speed * _elapsed);
		IsMoving = true;
		if (((fmod(Body.getPosition().x, 60.0f) >= 58.0f || fmod(Body.getPosition().x, 60.0f) <= 2.0f) && fmod(Body.getPosition().y, 60.0f) == 0.0f)||
			((fmod(Body.getPosition().y, 60.0f) >= 58.0f || fmod(Body.getPosition().y, 60.0f) <= 2.0f) && fmod(Body.getPosition().x, 60.0f) == 0.0f))
		{
			Movement.x = 0;
			Movement.y = 0;
			Body.setPosition(round(Body.getPosition().x/10)*10, round(Body.getPosition().y/10) * 10);
			PositionIndeks.x = Body.getPosition().x / 60;
			PositionIndeks.y = Body.getPosition().y / 60;
			Checked = false;
			if (LifePoints < Maxhealth)
				LifePoints++;

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


void Player::Stop(bool isCollision)
{
	if (isCollision)
	{
		Movement.x = 0.0f;
		Movement.y = 0.0f;
		Body.setPosition(PositionIndeks.x * 60, PositionIndeks.y * 60);
	}
}

void Player::RaiseLvl()
{
	if (Exp >= Lvl * 10)
	{
		Exp -= Lvl * 10;
		Lvl++;
		Maxhealth = Maxhealth + 10 + Lvl * 2;
		LifePoints = Maxhealth;
		MaxStamina = MaxStamina + 5 + Lvl * 3;
		StaminaPoints = MaxStamina;
	}
}
