
#include "Game.hpp"
#include <iostream>

Game::Game() : window("Mic SFML") {
	//Pointer intelligent
	std::shared_ptr<SceneSplashScreen> splashScreen =
		std::make_shared<SceneSplashScreen>(workingDir, sceneStateMachine, window);
	std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>(workingDir);
	//Les ID des scenes a charger = ajout de la scene au state Machine
	unsigned int splashScreenID = sceneStateMachine.Add(splashScreen);
	unsigned int gameSceneID = sceneStateMachine.Add(gameScene);

	//Get scene ID -> transition
	splashScreen->SetSwitchToScene(gameSceneID);
	//Scene starter -> entry point
	sceneStateMachine.SwitchTo(splashScreenID);

	deltaTime = clock.restart().asSeconds();
}

//Input from GameScene
void Game::ProcessInput() {
	sceneStateMachine.ProcessInput();
}

//FPS
void Game::CalculateDeltaTime() {
	deltaTime = clock.restart().asSeconds();
}


void Game::Update() {
	window.Update();
	sceneStateMachine.Update(deltaTime);
}

void Game::LateUpdate() {
	sceneStateMachine.LateUpdate(deltaTime);
}

void Game::Draw() {
	window.BeginDraw();

	sceneStateMachine.Draw(window);

	window.EndDraw();
}

bool Game::IsRunning() const {
	return window.IsOpen();
}