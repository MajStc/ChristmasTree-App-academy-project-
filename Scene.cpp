#include "Scene.h"


void Scene::initBackground(){
	/*
		@ return void
		- Initialize background colors
	*/

	this->backgroundColor.setFillColor(sf::Color(205, 194, 254, 100));
	this->backgroundColor.setSize(sf::Vector2f(1080.f, 720.f));
}

void Scene::initStars(){
	/*
		@ return void
		- Create stars on sky in random position
	*/

	for (int i = 0; i < 500; ++i) {
		sf::CircleShape star;
		star.setRadius(rand()%2+1);
		star.setFillColor(sf::Color(225, 249, 46, rand() % 150));
		star.setPosition(sf::Vector2f(rand() % 1080, rand() % 690));

		this->stars.push_back(star);
	}
}

void Scene::initChristmasTreeTrunk() {
	/*
		@ return void
		- Create base christmas tree trunk
	*/

	this->christmasTreeTrunk.setFillColor(sf::Color(43, 33, 0));
	this->christmasTreeTrunk.setSize(sf::Vector2f(40, 60));
	this->christmasTreeTrunk.setPosition(sf::Vector2f(530.f, 635.f));
}

void Scene::initChristmasTreeTrunkParticles(){
	/*
		@ return void
		- Create trunk particles so it looks cooler 
	*/

	for (int i = 0; i < 100; ++i) {
		sf::RectangleShape trunkParticle;
		trunkParticle.setSize(sf::Vector2f(rand()%2+1,rand()%4+1));
		trunkParticle.setFillColor(sf::Color(rand()%60, rand()%30,0));
		trunkParticle.setPosition(sf::Vector2f(rand()%39+530, rand() % 60 + 635));
		this->christmasTreeTrunkParticles.push_back(trunkParticle);
	}
}

void Scene::initChristmasTree(){
	/*
		@ return void
		- Create christmas tree
	*/

	sf::ConvexShape firstPart;

	firstPart.setPointCount(5);
	firstPart.setPoint(0, sf::Vector2f(530.f, 635.f));
	firstPart.setPoint(1, sf::Vector2f(200.f, 635.f));
	firstPart.setPoint(2, sf::Vector2f(300.f, 535.f));
	firstPart.setPoint(3, sf::Vector2f(780.f, 535.f));
	firstPart.setPoint(4, sf::Vector2f(880.f, 635.f));
	firstPart.setFillColor(sf::Color(66, 105, 47));

	sf::ConvexShape secondPart;
	secondPart.setPointCount(5);

	secondPart = firstPart;
	secondPart.setScale(0.9f, 0.9f);
	secondPart.move(56, 0.f);
	secondPart.setFillColor(sf::Color(66, 105, 47));

	sf::ConvexShape thirdPart;
	thirdPart.setPointCount(5);

	thirdPart = secondPart;
	thirdPart.setScale(0.8f, 0.8f);
	thirdPart.move(56.f, 0.f);
	thirdPart.setFillColor(sf::Color(66, 105, 47));

	sf::ConvexShape fourthPart;
	fourthPart.setPointCount(5);

	fourthPart = thirdPart;
	fourthPart.setScale(0.7f, 0.7f);
	fourthPart.move(56, 0.f);
	fourthPart.setFillColor(sf::Color(66, 105, 47));

	sf::ConvexShape fifthPart;
	thirdPart.setPointCount(5);

	fifthPart = fourthPart;
	fifthPart.setScale(0.6f, 0.6f);
	fifthPart.move(56.f, 0.f);
	fifthPart.setFillColor(sf::Color(66, 105, 47));

	sf::ConvexShape sixthPart;
	sixthPart.setPointCount(5);

	sixthPart = fifthPart;
	sixthPart.setScale(0.5f, 0.5f);
	sixthPart.move(56.f, 10.f);
	sixthPart.setFillColor(sf::Color(66, 105, 47));

	sf::ConvexShape seventhPart;
	seventhPart.setPointCount(5);

	seventhPart = sixthPart;
	seventhPart.setScale(0.4f, 0.4f);
	seventhPart.move(56.f, 15.f);
	seventhPart.setFillColor(sf::Color(66, 105, 47));

	sf::ConvexShape eigthPart;
	eigthPart.setPointCount(3);

	eigthPart.setPoint(0, sf::Vector2f(440.f, 200.f));
	eigthPart.setPoint(1, sf::Vector2f(550.f, 70.f));
	eigthPart.setPoint(2, sf::Vector2f(660.f, 200.f));
	eigthPart.setFillColor(sf::Color(66, 105, 47));

	eigthPart.move(0.f, 50.f);

	this->christmasTree.push_back(firstPart);
	this->christmasTree.push_back(secondPart);
	this->christmasTree.push_back(thirdPart);
	this->christmasTree.push_back(fourthPart);
	this->christmasTree.push_back(fifthPart);
	this->christmasTree.push_back(sixthPart);
	this->christmasTree.push_back(seventhPart);
	this->christmasTree.push_back(eigthPart);
}

void Scene::initMainPlatform(){
	/*
		@ return void
		- Create main platform
	*/

	this->mainPlatform.setSize(sf::Vector2f(1080.f, 20.f));
	this->mainPlatform.setFillColor(sf::Color(42, 22, 7));
	this->mainPlatform.setPosition(sf::Vector2f(0.f, 700.f));
}

void Scene::initDirtPlatform(){
	/*
		@ return void
		- Create some particle-like things on platform so it also look cooler
	*/

	for (int i = 0; i < 3; ++i) {
		for (int j = 1; j < 72; ++j) {
			sf::CircleShape dirtParticle;
			dirtParticle.setRadius(rand() % 4 + 1);
			dirtParticle.setFillColor(sf::Color(32, 29, 24, rand() % 200 + 55));
			dirtParticle.setPosition(sf::Vector2f(j * 10, rand() % 20 + 700));
			this->dirt.push_back(dirtParticle);
		}
	}
}

void Scene::initSnowOnMainPlatform(){
	/*
		@ return void
		- Create snow on platform
	*/

	this->snowOnMainPlatform.setSize(sf::Vector2f(1080.f, 5.f));
	this->snowOnMainPlatform.setFillColor(sf::Color::White);
	this->snowOnMainPlatform.setPosition(sf::Vector2f(0.f, 695.f));
}

void Scene::initRealisticMainPlatfromSnow(){
	/*
		@ return void
		- Create cooler snow on main platform by adding some circles
	*/

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 108; ++j) {
			sf::CircleShape snowParticle;
			snowParticle.setRadius(rand() % 5 + 4);
			snowParticle.setFillColor(sf::Color::White);
			snowParticle.setPosition(sf::Vector2f(j * 10, rand()%5+695));
			this->realisticSnow.push_back(snowParticle);
		}
	}
}

//Cosntructor & Destructor
Scene::Scene() {
	this->initBackground();

	this->initStars();

	this->initChristmasTreeTrunk();
	this->initChristmasTreeTrunkParticles();
	this->initChristmasTree();

	this->initMainPlatform();
	this->initSnowOnMainPlatform();
	this->initDirtPlatform();
	this->initRealisticMainPlatfromSnow();
}

Scene::~Scene(){

}

// Functions
void Scene::update(const sf::RenderTarget* target) {
	
}

void Scene::render(sf::RenderTarget* target){
	/*
		@ return void
		- Draw whole backgorund, every star, christmass tree etc.
	*/

	target->draw(this->backgroundColor);

	for (auto i : stars) {
		target->draw(i);
	}

	target->draw(this->christmasTreeTrunk);
	for (auto i : christmasTreeTrunkParticles) {
		target->draw(i);
	}
	for (auto i : christmasTree) {
		target->draw(i);
	}


	target->draw(this->mainPlatform);
	target->draw(this->snowOnMainPlatform);
	for (auto i : dirt) {
		target->draw(i);
	}
	for (auto i : realisticSnow) {
		target->draw(i);
	}
}
