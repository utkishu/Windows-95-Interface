#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <string>
#include <iostream>



class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
	sf::Texture windowsTabTex;
	sf::Texture windowsStartTex;
	sf::Texture RecycleBinTex;
	
	sf::Sprite windowsTab;

	sf::Text Text;

	sf::Font font;
};