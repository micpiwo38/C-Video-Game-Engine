#pragma once

#include "Component.hpp"
#include "C_Transform.hpp"

class C_Sprite : public Component {
public:
	C_Sprite(Object* owner);
	//Charger les sprites depuis un fichier
	void Load(const std::string& filePath);
	//Surcharger le methode Draw
	void Draw(Window& window) override;
	//Update sprite based et position
	void LateUpdate(float deltaTime) override;

private:
	sf::Texture texture;
	sf::Sprite sprite;
};