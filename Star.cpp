#include "Star.h"

void Star::initStar(){
	/*
		@ return void
		- Create star build from two triangles
	*/

	this->starOne.setPointCount(3);
	this->starTwo.setPointCount(3);

	this->starOne.setRadius(80);
	this->starTwo.setRadius(80);

	this->starOne.setFillColor(sf::Color(255, 255, 0));
	this->starTwo.setFillColor(sf::Color(255, 255, 0));

	this->starOne.setScale(0.3, 0.3);
	this->starTwo.setScale(0.3, 0.3);

	this->starTwo.rotate(180);

	this->starOne.setPosition(sf::Vector2f(526,100));
	this->starTwo.setPosition(sf::Vector2f(574,150));
}

void Star::initShine(){
	this->r = 0;
	this->shineStronger = true;
	this->shine.setFillColor(sf::Color(255,255,0,150));
	this->shine.setRadius(r);
}

// Constructor & Destructor
Star::Star(){
	this->initStar();
}

Star::~Star(){

}

void Star::updateShine(){
	if (this->r < 3 && shineStronger) {
		r += 0.15;
	}
	else{
		this->shineStronger = false;
	}
	if (this->r >= 0 && !shineStronger) {
		r -= 0.15;
	}
	else {
		this->shineStronger = true;
	}
	this->shine.setRadius(r);
	this->shine.setFillColor(sf::Color(255, 255, 220));
	this->shine.setPosition(sf::Vector2f(567, 113));
}

// Functions
void Star::update(const sf::RenderTarget* target){
	this->updateShine();
}

void Star::render(sf::RenderTarget* target){
	/*
		@ return void
		- Draw updated star
	*/

	target->draw(this->starOne);
	target->draw(this->starTwo);
	target->draw(this->shine);
}
