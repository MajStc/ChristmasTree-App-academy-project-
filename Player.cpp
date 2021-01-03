#include "Player.h"





void Player::initPlayerShape(){
	/*
		@ return void
		- Initialize player sprite and starting position
	*/

	this->texture.loadFromFile("Images/Player.png");
	this->player.setTexture(texture);
	this->player.setPosition(sf::Vector2f(0.f,600.f));
}



void Player::initVariables(){
	/*
		@ Initialize variables
	*/

	this->gravitySpeed = 2.25;
	this->groundHeight = 600;
	this->isJumping = false;
	this->movementSpeed = 5;
}

// Constructor & Destructor
Player::Player() {
	this->initPlayerShape();
	this->initVariables();
}

Player::~Player(){

}

// Functions
int Player::getPlayerY(){
	/*
		@ return player Y position as integer
	*/

	return player.getPosition().y;
}

void Player::inputUpdate() {
	/*
		@ returns void
		- Watch for WASD action
		- Move the player position
	*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->player.move(-this->movementSpeed, 0.f);
		this->texture.loadFromFile("Images/PlayerLeft.png");
		this->player.setTexture(texture);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->player.move(this->movementSpeed, 0.f);
		this->texture.loadFromFile("Images/Player.png");
		this->player.setTexture(texture);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->player.move(0.f, -this->movementSpeed);
		isJumping = true;
	}
	if (isJumping && sf::Keyboard::Up) {
		isJumping = false;
	}
}

void Player::gravityPower(int playerY){
	/*
		@ return void
		- Simple gravity function
	*/

	if (playerY < groundHeight && !isJumping) {
		player.move({ 0, gravitySpeed });
	}
}

void Player::update(const sf::RenderTarget* target){
	/*
		- Parameters: pointer to window target (neccesary for drawing directly on window from here)
		@ return void
		- Update player position
	*/

	int playerY = getPlayerY();
	this->inputUpdate();
	this->gravityPower(playerY);
}

void Player::render(sf::RenderTarget* target){
	/*
		- Parameters: pointer to window target (neccesary for drawing directly on window from here)
		@ return void
		- Render updated player position
	*/

	target->draw(this->player);
}
