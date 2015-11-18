#include "VisTankBase.hpp"

VisTankBase::VisTankBase(float const fsize, float const xPos, float const yPos) : size(fsize) {
	
	leftTrack = sf::RectangleShape( sf::Vector2f( 0.22*size, 0.9*size ) );
	leftTrack.setOrigin(0.45*size, 0.45*size);
	leftTrack.setFillColor(sf::Color(34, 139, 34));	
	leftTrack.setPosition(xPos, yPos);

	rightTrack = sf::RectangleShape( sf::Vector2f( 0.22*size, 0.9*size ) );
	rightTrack.setOrigin(-0.23*size, 0.45*size);
	rightTrack.setFillColor(sf::Color(34, 139, 34));	
	rightTrack.setPosition(xPos, yPos);
		
	gun = sf::RectangleShape( sf::Vector2f( 0.12*size, 0.4*size ) );
	gun.setOrigin(0.06*size, 0.48*size);
	gun.setFillColor(sf::Color(0, 100, 0));	
	gun.setPosition(xPos, yPos);
	
	turret = sf::CircleShape( 0.375*size );
	turret.setOrigin(0.375*size, 0.375*size);
	turret.setFillColor(sf::Color(45, 185, 45));	
	turret.setPosition(xPos, yPos);
	
}


VisTankBase::~VisTankBase(){
}

void VisTankBase::setPosition(float const xPos, float const yPos){
	turret.setPosition(xPos, yPos);
	leftTrack.setPosition(xPos, yPos);
	rightTrack.setPosition(xPos, yPos);
	gun.setPosition(xPos, yPos);
}

void VisTankBase::setPosition(sf::Vector2f & pos){
}

void VisTankBase::rotate(VisTankBase::Direction dir){
	leftTrack.setRotation(dir * 90);
	rightTrack.setRotation(dir * 90);
	gun.setRotation(dir * 90);
}

void VisTankBase::draw(sf::RenderWindow & window){
	window.draw(leftTrack);
	window.draw(rightTrack);
	window.draw(turret);
	window.draw(gun);
	
}

void VisTankBase::setColor(sf::Color const & lTraColor, sf::Color const & rTraColor, sf::Color const & gunColor, sf::Color const & turrColor){
	leftTrack.setFillColor(lTraColor);
	rightTrack.setFillColor(rTraColor);
	gun.setFillColor(gunColor);
	turret.setFillColor(turrColor);	
}
	
	
	

