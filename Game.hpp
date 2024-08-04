#pragma once

#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "Input.hpp"
#include "SceneStateMachine.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneGame.hpp"

class Game {
public:
	Game();
	void ProcessInput();
	void Update();
	void LateUpdate();
	void Draw();
	bool IsRunning() const;
	void CalculateDeltaTime();

private:
	Window window;
	WorkingDirectory workingDir;

	//FPS
	sf::Clock clock;
	float deltaTime;

	SceneStateMachine sceneStateMachine;
};