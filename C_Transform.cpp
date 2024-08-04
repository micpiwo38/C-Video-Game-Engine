#include "C_Transform.hpp"
#include "Object.hpp"

C_Transform::C_Transform(Object* owner) : Component(owner), position(10.f, 10.f){}


void C_Transform::SetPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

void C_Transform::SetPosition(sf::Vector2f pos) {
	position = pos;
}

void C_Transform::AddPosition(float x, float y) {
	position.x += x;
	position.y += y;
}

void C_Transform::AddPosition(sf::Vector2f pos) {
	position += pos;
}

void C_Transform::SetX(float x) {
	position.x += x;
}

void C_Transform::SetY(float y) {
	position.y += y;
}

void C_Transform::AddX(float x) {
	position.x += x;
}

void C_Transform::AddY(float y) {
	position.y += y;
}

//Getter
const sf::Vector2f& C_Transform::GetPosition() const {
	return position;
}