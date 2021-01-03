#include "Game.h"
#include <iostream>

void Game::initVariables(){
	this->endGame = false;
}

void Game::initWindow(){
	/*
		@ return void
		- Create non-resizeable window, limit fps to 60
	*/

	this->videoMode = sf::VideoMode(1080, 720);
	this->window = new sf::RenderWindow(this->videoMode, "Choinka", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

// Constructor & Destructor
Game::Game(){
	this->initVariables();
	this->initWindow();
}

Game::~Game(){
	delete this->window;
}


// Functions
const bool Game::running() const{
	/*
		@ return bool
		- Return true if window is not closed
	*/

	return this->window->isOpen();
}

void Game::pollEvents(){
	/*
		@ return void
		- Watch for closing the window
	*/

	while (this->window->pollEvent(sfmlEvent)) {
		if (sfmlEvent.type == sf::Event::Closed) {
			this->window->close();
		}	
	}
}

void Game::update() {
	/*
		@ return void
		- Check if someone closed the window (basically any action)
		- Update player position
		- Update christmas tree decorations
		- Update Christmas Tree star
		- Update falling snow

	*/

	this->pollEvents();
	this->player.update(this->window);
	this->christmasTreeDecorations.update(this->window);
	this->star.update(this->window);
	this->snow.update(this->window);
}

void Game::render(){
	/*
		@ return void
		- clear current window state
		- Render every updated or non-changed element
		- display new stuff
	*/

	this->window->clear();


	this->scene.render(this->window);
	this->christmasTreeDecorations.render(this->window);
	this->star.render(this->window);
	this->snow.render(this->window);
	this->player.render(this->window);

	this->window->display();
}
