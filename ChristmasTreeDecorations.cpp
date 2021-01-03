#include "ChristmasTreeDecorations.h"
#include <cmath>
#include<iostream>

void ChristmasTreeDecorations::initChristmasLights(){
	/*
		@ return void
		- Create christmas lights
	*/

	for (int i = 0; i < 150; ++i) {
		sf::CircleShape light;
		light.setRadius(rand() % 6+1);
		light.setPosition(sf::Vector2f(550, 300));
		light.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		this->christmasLights.push_back(light);
	}
}

void ChristmasTreeDecorations::randomizeLights(){
	/*
		@ return void
		- Randomize christmas lights position and color
		- Randomize based on random height, then calculates current max X range to stay in christmas tree shape
	*/

	for (int i = 0; i < 150; ++i) {

		int dy = rand() % 510 + 125;
		double x = 0;
		double smallx = 0;
		double h = 0;
		double tanalpha = 0;
		double temp = 0;
		double newz = 0;
		double y = 0;

		if (dy > 572) { x = 680; smallx = 480; h = 100; temp = 200; y = 635; }
		else if (dy > 508) { x = 600; smallx = 480 * 0.9; h = 100 * 0.9; temp = 235; y = 570; }
		else if (dy > 444) { x = 540; smallx = 480 * 0.8; h = 100 * 0.8; temp = 270; y = 505; }
		else if (dy > 380) { x = 470; smallx = 480 * 0.7; h = 100 * 0.7; temp = 305; y = 445; }
		else if (dy > 327) { x = 400; smallx = 480 * 0.6; h = 100 * 0.6; temp = 345; y = 380; }
		else if (dy > 280) { x = 340; smallx = 480 * 0.5; h = 100 * 0.5; temp = 380; y = 325; }
		else if (dy > 250) { x = 260; smallx = 480 * 0.4; h = 100 * 0.4; temp = 415; y = 280; }
		else { x = 220; smallx = 0; h = 130; temp = 440; y = 250; }

		y -= dy;
		tanalpha = (2 * h) / (x - smallx);
		newz = y / tanalpha;

		double randrangedouble = ceil(abs(x - (2 * (y / tanalpha))));
		int randrange = randrangedouble+1;

		int b = (rand() % randrange)+temp+newz;

		this->christmasLights[i].setFillColor(sf::Color(rand() % 155+100, rand()%100, rand() % 255, rand()%155+100));
		this->christmasLights[i].setRadius(rand() % 6 + 1);
		this->christmasLights[i].setOutlineThickness(rand()%1+1 );
		this->christmasLights[i].setOutlineColor(sf::Color(0, 0, 0, 50));
		this->christmasLights[i].setPosition(sf::Vector2f(b, dy));
	}
}

// Constructor & Destructor
ChristmasTreeDecorations::ChristmasTreeDecorations(){
	this->initChristmasLights();
}

ChristmasTreeDecorations::~ChristmasTreeDecorations(){

}

// Functions
void ChristmasTreeDecorations::update(const sf::RenderTarget* target){
	/*
		@ return void
		- randomize lights every 0.8s (I found this optimum, didn't manage to match it with sound tempo, perhaps it's not constant)
	*/

	this->time = this->clock.getElapsedTime();
	if (time.asSeconds() >= 0.8) {
		this->randomizeLights();
		clock.restart();
	}
}

void ChristmasTreeDecorations::render(sf::RenderTarget* target){
	/*
		@ return void
		- Draw randomized lights
	*/

	for (auto i : christmasLights) {
		target->draw(i);
	}
}
