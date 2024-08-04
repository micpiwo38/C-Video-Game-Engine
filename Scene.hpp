#pragma once
#include "Window.hpp"

class Scene
{
public:
	//Virtual Methode = Heritage 
	// 1 - Appelé a la creation de la scene (une seule fois)
	virtual void OnCreate() = 0;

	//Supprimer 
	virtual void OnDestroy() = 0;

	//Les 2 methodes suivante sont des fonctions pures = impossible a instancié

	//Activé
	virtual void OnActivate() {};

	//Deactivé
	virtual void OnDeactivate() {};

	//Surchage des methodes de Game.cpp
	virtual void ProcessInput() {};
	virtual void Update(float deltatime) {};
	virtual void LateUpdate(float deltatime) {};
	virtual void Draw(Window& window) {};

};

