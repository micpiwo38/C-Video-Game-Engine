#pragma once

//FSM = finite state machine = stock des etats

#include <memory>
#include "Scene.hpp"
#include "Window.hpp"
#include <unordered_map>
#include <utility>

class SceneStateMachine
{
public: 
	SceneStateMachine();
	void ProcessInput();
	void Update(float deltatime);
	void LateUpdate(float deltatime);
	void Draw(Window& window);
	//Ajouter une scene a state machine et retourne un ID
	unsigned int Add(std::shared_ptr<Scene> scene);
	//Transition de scene a l'aide de l'id
	void SwitchTo(unsigned int id);
	//Supprimer une scene du state machine
	void Remove(unsigned int id);

private:
	//Stock toutes les scenes associée au state machine
	std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
	//Stock une reference a la scene courante
	std::shared_ptr<Scene> curScene;
	//Stock de l'id de la scene courante (les scenes ID sont autoincremente a chaque Scene => Add())
	unsigned int insertedSceneID;
};

