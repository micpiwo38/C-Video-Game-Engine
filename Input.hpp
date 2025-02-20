#pragma once
#include <SFML/Graphics.hpp>
#include "Bitmask.hpp"

class Input
{
public:
	enum class Key {
		None = 0,
		Left = 1,
		Right = 2,
		Up = 3,
		Down = 4,
		Esc = 5
	};

	void Update();

	bool IsKeyPressed(Key keycode); 
	bool IsKeyDown(Key keycode);
	bool IsKeyUp(Key keycode);

private:
	Bitmask thisFrameKeys; //Touche courante
	Bitmask lastFrameKeys; //Derni�re touche utilis�e
};

