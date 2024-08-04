#include "Input.hpp"

void Input::Update() {
	lastFrameKeys.SetMask(thisFrameKeys);

	//Mutateur GAUCHE
	thisFrameKeys.SetBit((int)Key::Left,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)));

	thisFrameKeys.SetBit((int)Key::Right,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::D)));

	thisFrameKeys.SetBit((int)Key::Up,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)));

	thisFrameKeys.SetBit((int)Key::Down,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::S)));

	thisFrameKeys.SetBit((int)Key::Esc,
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)));
}

//Retourne TRUE si une touche est pressée
bool Input::IsKeyPressed(Key keycode) {
	return thisFrameKeys.GetBit((int)keycode);
}

//Retourne TRUE si une touche est pressée a la frame courante
bool Input::IsKeyDown(Key keycode) {
	//Dernière frames
	bool lastFrame = lastFrameKeys.GetBit((int)keycode);
	//Frame courante
	bool thisFrame = thisFrameKeys.GetBit((int)keycode);

	return thisFrame && !lastFrame;
}

//Retourne TRUE si une touche est relachée a la frame courante
bool Input::IsKeyUp(Key keycode) {
	//Dernière frames
	bool lastFrame = lastFrameKeys.GetBit((int)keycode);
	//Frame courante
	bool thisFrame = thisFrameKeys.GetBit((int)keycode);

	return !thisFrame && lastFrame;
}
