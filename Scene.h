#pragma once

#include "Player.h"
#include <vector>

class Scene{
private:

	// Draw background
	sf::RectangleShape backgroundColor;
	// Draw stars
	std::vector<sf::CircleShape> stars;

	// Draw christmasTree
	sf::RectangleShape christmasTreeTrunk;
	std::vector<sf::RectangleShape> christmasTreeTrunkParticles;
	std::vector<sf::ConvexShape> christmasTree;

	// Create main platform
	sf::RectangleShape mainPlatform;
	// Create more realistic dirt on main platform
	std::vector<sf::CircleShape> dirt;
	// Create snow on main pltform
	sf::RectangleShape snowOnMainPlatform;
	// Create more realistic platform snow
	std::vector<sf::CircleShape> realisticSnow;

	// Init background
	void initBackground();

	// Init stars
	void initStars();

	// Init christmas tree
	void initChristmasTreeTrunk();
	void initChristmasTreeTrunkParticles();
	void initChristmasTree();

	// Init main platform
	void initMainPlatform();
	// Make platform more realistic
	void initDirtPlatform();
	// Init snow on main platform
	void initSnowOnMainPlatform();
	// Make snow on platform more realistic
	void initRealisticMainPlatfromSnow();

public:
	//Constructor & Destructor
	Scene();
	~Scene();
	// Update & Render
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

