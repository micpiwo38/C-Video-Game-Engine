#include "C_KeyboardMovement.hpp"
#include "Object.hpp"
#include <iostream>

C_KeyboardMovement::C_KeyboardMovement(Object* owner) : Component(owner), moveSpeed(100){}

void C_KeyboardMovement::SetInput(Input* input) {
	this->input = input;
}

void C_KeyboardMovement::SetMovementSpeed(int moveSpeed) {
	this->moveSpeed = moveSpeed;
}

void C_KeyboardMovement::Update(float deltaTime) {
	if (input == nullptr) {
		return;
	}

	int xMove = 0;
	

	if (input->IsKeyPressed(Input::Key::Left)) {
		xMove = -moveSpeed;
		std::cout << "test gauche : " << std::endl;
	}
	else if (input->IsKeyPressed(Input::Key::Right)) {
		xMove = moveSpeed;
		std::cout << "test droite : " << std::endl;
	}

	int yMove = 0;

	if (input->IsKeyPressed(Input::Key::Up)) {
		yMove = -moveSpeed;
	}
	else if (input->IsKeyPressed(Input::Key::Down)) {
		yMove = moveSpeed;
	}

	float xFrameMove = xMove * deltaTime;
	float yFrameMove = yMove * deltaTime;

	owner->transform->AddPosition(xFrameMove, yFrameMove);
}



