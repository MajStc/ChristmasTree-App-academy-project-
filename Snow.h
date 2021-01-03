#pragma once
#include "Player.h"
#include <vector>

class Snow {
private:
	// Create snow
	std::vector<sf::CircleShape> snow;

	// Gravity variables
	int snowGroundHeight;
	float snowGravitySpeed;

	// Generate snow
	void generateSnow();
	// Init variables
	void initSnowVariables();
	// Spawn another snow
	void spawnAnotherSnow();
	// update snow
	void updateSnow();

public:
	// Constructor & Destructor
	Snow();
	~Snow();

	// Snow Gravity
	void snowGravity();

	// Update & Render
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

