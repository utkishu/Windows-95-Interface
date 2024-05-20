#include "Level.h"
#include"Framework/Utilities.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	if (!windowsTabTex.loadFromFile("gfx/Window_Base.png"))
	{

	}


	font.loadFromFile("font/arial.ttf");
	Text.setFont(font);
	windowsTab.setTexture(windowsTabTex);
	windowsTab.setScale(50.0f, 2.0f); // Example: doubling the size
	//windowsTab.setPosition(SCREEN_WIDTH, SCREEN_HEIGHT-windowsTab.getScale().y);
	//std::cout << "Position: " << SCREEN_WIDTH - windowsTab.getScale().x << ":" << windowsTab.getScale().y << std::endl;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		std::cout << "Exit Button Pressed\n";
		exit(0);
	}
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
