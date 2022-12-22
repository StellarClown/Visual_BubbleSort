#include <SFML/Graphics.hpp>
#include "../Headers/SceneElements.h"

using namespace SceneElements;

Stick::Stick(const size_t ValueStick) : height(ValueStick), width(2) {
	;
}






const sf::RectangleShape Stick::getStick(const uint16_t posx, const uint16_t hWindow, const bool SelectedStick) const {
	sf::RectangleShape Stick(sf::Vector2f(0, 0));

	Stick.setPosition(posx, hWindow);
	Stick.setSize(sf::Vector2f(this->width, this->height));
	Stick.setRotation(180);
	Stick.setFillColor(SelectedStick ? sf::Color::Red : sf::Color::Black);

	return Stick;
}






/*
	OVERLOADING OPERATORS
*/
bool Stick::operator> (const Stick& obj) const {
	return this->height > obj.height;
}

void Stick::operator= (const Stick& obj) {
	this->height = obj.height;
}