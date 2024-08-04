#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine(): scenes(0), curScene(0){}

void SceneStateMachine::ProcessInput() {
	if (curScene) {
		//Acces a la classe parente Scene-> methode Process Input
		curScene->ProcessInput();
	}
}

void SceneStateMachine::Update(float deltatime) {
	if (curScene) {
		curScene->Update(deltatime);
	}
}

void SceneStateMachine::LateUpdate(float deltatime) {
	if (curScene) {
		curScene->LateUpdate(deltatime);
	}
}

void SceneStateMachine::Draw(Window& window) {
	if (curScene) {
		curScene->Draw(window);
	}
}

unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene) {
	//Auto deduit le type de variable
	auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
	//Incremente ID de la scene ajouée au state machine
	insertedSceneID++;
	inserted.first->second->OnCreate();
	//Retourne la scene - 1 car tableau commence par 0 dans state machine
	return insertedSceneID - 1;
}

void SceneStateMachine::Remove(unsigned int id) {
	auto it = scenes.find(id);
	//Si différent de la dernière scene dans le tableau
	if (it != scenes.end()) {
		if (curScene == it->second) {
			//Si la scene retirée est la scene courante -> elle n'est plus mise a jour
			curScene = nullptr;
		}
		it->second->OnDestroy();
		scenes.erase(it);
	}
}

void SceneStateMachine::SwitchTo(unsigned int id) {
	auto it = scenes.find(id);

	if (it != scenes.end()) {
		if (curScene) {
			curScene->OnDeactivate();
		}

		curScene = it->second;

		curScene->OnActivate();
	}
}
