#pragma once
#include "Component.hpp"
#include "Input.hpp"

class C_KeyboardMovement : public Component
{
public:
	C_KeyboardMovement(Object* owner);

	void SetInput(Input* input);
	void SetMovementSpeed(int moveSpeed);

	void Update(float deltaTime) override;
private:
	int moveSpeed;
	Input* input;
};

