#include <iostream>
#include "Game.hpp"

//POWER TUTO : https://thatgamesguy.co.uk/cpp-game-dev-6/

int main() {
	Game game;

	while (game.IsRunning())
	{
		//Inputs
		
		game.Update();
		game.LateUpdate();
		game.Draw();
		//FPS
		game.CalculateDeltaTime();
	}
	std::cout << "Test de SFML" << std::endl;
	return 0;
}