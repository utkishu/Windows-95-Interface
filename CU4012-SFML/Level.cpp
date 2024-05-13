#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	if (!windowsTabTex.loadFromFile("gfx/Window_Base.png"))
	{

	}

	windowsTab.setTexture(windowsTabTex);
	windowsTab.setScale(50.0f, 2.0f); // Example: doubling the size

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{

	// Check for collision with mouse
	sf::Vector2i mousePos(input->getMouseX(),input->getMouseY());
	sf::Vector2f mousePosFloat(mousePos.x, mousePos.y);

	if (windowsTab.getGlobalBounds().contains(mousePosFloat))
	{
		std::cout << "Sprite is colliding with the mouse." << std::endl;
	}

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(windowsTab);
	endDraw();
}
