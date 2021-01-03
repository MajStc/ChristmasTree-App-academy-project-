#pragma once

#include "Player.h"
#include "Scene.h"
#include "ChristmasTreeDecorations.h"
#include "Star.h"
#include "Snow.h"

#include <vector>

class Game{
private:
	// Creating variables
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;
	bool endGame;

	//Creating a scene
	Scene scene;

	// Create christmat tree decorations
	ChristmasTreeDecorations christmasTreeDecorations;

	// Create christmas tree star
	Star star;

	// Create snow
	Snow snow;

	// Creating a player
	Player player;
	

	// Initializing variables
	void initVariables();

	// Initializing window
	void initWindow();

public:
	// Constructor & Destructor
	Game();
	~Game();

	// Game status
	const bool running() const;
	void pollEvents();

	// Updating & rendering window
	void update();
	void render();
};



