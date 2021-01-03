#pragma once

#include "Player.h"
#include "Scene.h"
#include <vector>

class ChristmasTreeDecorations{
private:

	// Create christmas lights
	std::vector<sf::CircleShape> christmasLights;

	// Time and Clock
	sf::Clock clock;
	sf::Time time;

	// Scene (getglobalbounds of christmas tree)
	Scene scene;

	// void init lights
	void initChristmasLights();

public:
	// Constructor & Destructor
	ChristmasTreeDecorations();
	~ChristmasTreeDecorations();

	// Functions 	
	// randomize lights
	void randomizeLights();

	// Update & Render
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};
