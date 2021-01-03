#pragma once
#include "Player.h"

class Star{
private:
	// Create star
	sf::CircleShape starOne;
	sf::CircleShape starTwo;

	// Create shine 
	sf::CircleShape shine;

	// Shine radius & bool
	double r;
	bool shineStronger;

	// Init star
	void initStar();
	// Init shine
	void initShine();

public:
	// Constructor & Destructor
	Star();
	~Star();

	// Update shine
	void updateShine();

	// Update & Render
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

