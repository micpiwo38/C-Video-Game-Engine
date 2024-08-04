#include "SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(
	WorkingDirectory& workingDir,
	SceneStateMachine& sceneStateMachine,
	Window& window
): sceneStateMachine(
	sceneStateMachine), 
	workingDir(workingDir), 
	window(window), 
	switchToState(0), 
	currentSeconds(0.f), 
	showForSeconds(3.f){}

void SceneSplashScreen::OnCreate() {
	//Init du splash screen
	splashTexture.loadFromFile(workingDir.Get() + "resources/logo.png");
	splashSprite.setTexture(splashTexture);

	sf::FloatRect spriteSize = splashSprite.getLocalBounds();

	//Origine du sprite au centre de l'ecran
	splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
	splashSprite.setScale(0.5f, 0.5f);
	sf::Vector2u windowCentre = window.GetCentre();
	splashSprite.setPosition(windowCentre.x, windowCentre.y);
}

void SceneSplashScreen::OnActivate() {
	//Reset counter
	currentSeconds = 0.f;
}

void SceneSplashScreen::OnDestroy(){}

void SceneSplashScreen::SetSwitchToScene(unsigned int id) {
	//ID de la scene a transitioner
	switchToState = id;
}

void SceneSplashScreen::Update(float deltatime) {
	currentSeconds += deltatime;
	if (currentSeconds >= showForSeconds) {
		sceneStateMachine.SwitchTo(switchToState);
	}
}

void SceneSplashScreen::Draw(Window& window) {
	window.Draw(splashSprite);
}


