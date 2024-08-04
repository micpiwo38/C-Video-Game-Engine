#include "SceneGame.hpp"
#include <iostream>


SceneGame::SceneGame(WorkingDirectory& workingDir) : workingDir(workingDir){}


void SceneGame::OnCreate() {
	player = std::make_shared<Object>();
	//Ici T type generique devient Object C_Sprite
	auto sprite = player->AddComponent<C_Sprite>();
	sprite->Load(workingDir.Get() + "resources/player.png");
	auto movement = player->AddComponent<C_KeyboardMovement>();
	//Deplacer le player => ici Input est un pointeur * donc => on reference avec &
	movement->SetInput(&input);
}

void SceneGame::OnDestroy(){}

void SceneGame::ProcessInput() {
	input.Update();
}

void SceneGame::Update(float deltatime) {
	player->Update(deltatime);
}

void SceneGame::LateUpdate(float deltatime) {
	player->LateUpdate(deltatime);
}

void SceneGame::Draw(Window& window) {
	player->Draw(window);
}