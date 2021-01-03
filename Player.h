#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

class Player{

private:

	// Create player shape
	sf::Texture texture;
	sf::Sprite player;

	// Player variables
	int groundHeight;
	float gravitySpeed;
	bool isJumping;
	
	float movementSpeed;
	
	// Init player
	void initPlayerShape();

	// Init variables
	void initVariables();

public:

	//Constructor & Destructor
	Player();
	virtual ~Player();

	//------------------------Functions
	// Gravity purposes
	int getPlayerY();
	// Movement
	void inputUpdate();
	// Gravity power
	void gravityPower(int playerY);

	// Update & Render
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

