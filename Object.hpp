#pragma once

#include <vector>
#include "Window.hpp"

#include "Component.hpp"
#include "C_Transform.hpp"

class Object
{
public:
	Object();
	
	void Awake();
	//After Awake
	void Start();

	void Update(float deltaTime);
	void LateUpdate(float deltaTime);
	void Draw(Window& window);
	//Add et Get sont génériques et utilisable dans chaque classe qui hérite ed Component
	template <typename T> std::shared_ptr<T> AddComponent() {
		//S'assurer que Add derive de Component
		static_assert(std::is_base_of<Component, T>::value, "T doit derivé de la classe Component");
		//Verifié que l'on n'a pas deja un component de ce type
		for (auto& existingComponent : components) {
			//Aviter d'ajouter le meme composant 2 fois
			if (std::dynamic_pointer_cast<T>(existingComponent)) {
				return std::dynamic_pointer_cast<T>(existingComponent);
			}
		}
		//L'objet n'a pas CE composant => on le creer
		std::shared_ptr<T> newComponent = std::make_shared<T>(this);
		//Ajouter a la fin du tableau
		components.push_back(newComponent);
		return newComponent;
	};

	template <typename T> std::shared_ptr<T> GetComponent() {
		static_assert(std::is_base_of<Component, T>::value, "T doit dérivé de la classe Component");

		for (auto& existingComponent : components) {
			if (std::dynamic_pointer_cast<T>(existingComponent)) {
				//Cast une super classe ne subclass
				//Comme on utilise des smart pointer => si le cast est invalide <=> on retourne un pointer partagé vide
				return std::dynamic_pointer_cast<T>(existingComponent);
			}
		}
		return nullptr;
	};

	std::shared_ptr<C_Transform> transform;

private:
	std::vector<std::shared_ptr<Component>> components;
};

