#include "Snow.h"
#include <iostream>



void Snow::generateSnow(){
	/*
		@ return void
		- Create 'starting' snow, high so user can't see it
	*/

	for (int i = 0; i < 500; ++i) {
		sf::CircleShape snowflake;

		snowflake.setRadius(rand() % 3 + 1);
		snowflake.setFillColor(sf::Color::White);
		snowflake.setPosition(sf::Vector2f(rand() % 1100, -1 * (rand() % 820 + 10)));

		this->snow.push_back(snowflake);
	}
}

void Snow::initSnowVariables(){
	/*
		@ return void
		- Initialize variables
	*/

	this->snowGravitySpeed = 0.75;
	this->snowGroundHeight = 700;
}

void Snow::spawnAnotherSnow(){
	/*
		@ return void
		- Spawn snowflake
	*/

	sf::CircleShape snowflake;

	snowflake.setRadius(rand() % 3 + 1);
	snowflake.setFillColor(sf::Color::White);
	snowflake.setPosition(sf::Vector2f(rand() % 1100, -1 * (rand() % 820 + 10)));

	this->snow.push_back(snowflake);
}

void Snow::updateSnow(){

}

// Constructor & Destructor
Snow::Snow(){
	this->initSnowVariables();
	this->generateSnow();
}

Snow::~Snow(){

}

// Functions
void Snow::snowGravity(){
	/*
		@ return void
		- Move every snowflake down as it falls
		- To make it look better (actually it is now looking like a whole new level better) randomize falling speed and move it to sides a bit also randomly
		- Whenever a snowflake hits the ground, it is being deleted and new one is created high above the view port so it can fall down again and again
	*/

	for (int i = 0; i < snow.size(); ++i) {
		int randSpeed = (rand() % 20)*0.1;
		snowGravitySpeed += randSpeed;
		if (randSpeed > 0.9) {
			snow[i].move({ 0.2,snowGravitySpeed });
		}
		else {
			snow[i].move({ -0.2,snowGravitySpeed });
		}
		snowGravitySpeed -= randSpeed;
		if (this->snow[i].getPosition().y > snowGroundHeight) {
			this->snow.erase(this->snow.begin() + i);
			this->spawnAnotherSnow();
		}
	}
}

void Snow::update(const sf::RenderTarget* target){
	/*
		@ return void
		- Update falling snow
	*/

	this->snowGravity();
}

void Snow::render(sf::RenderTarget* target){
	/*
		@ return void
		- Draw updated snow
	*/

	for (auto i : snow) {
		target->draw(i);
	}
}
