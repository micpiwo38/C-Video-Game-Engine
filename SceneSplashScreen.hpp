#pragma once

#include <SFML/Graphics.hpp>

#include "SceneStateMachine.hpp"
#include "WorkingDirectory.hpp"

class SceneSplashScreen : public Scene {
public:
	SceneSplashScreen(WorkingDirectory& workingDir, SceneStateMachine& sceneStateMachine, Window& window);
	void OnCreate() override;
	void OnDestroy() override;
	void OnActivate() override;
	void SetSwitchToScene(unsigned int id);
	void Update(float deltaTime) override;
	void Draw(Window& window) override;

private:
	sf::Texture splashTexture;
	sf::Sprite splashSprite;

	WorkingDirectory& workingDir;
	SceneStateMachine& sceneStateMachine;
	Window& window;

	float showForSeconds;
	float currentSeconds;

	unsigned int switchToState;


};