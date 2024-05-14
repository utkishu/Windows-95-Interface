// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.

#include <iostream>
#include "Level.h"



sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) {

	// Compares the aspect ratio of the window to the aspect ratio of the view,
	// and sets the view's viewport accordingly in order to archieve a letterbox effect.
	// A new view (with a new viewport set) is returned.

	float windowRatio = windowWidth / (float)windowHeight;
	float viewRatio = view.getSize().x / (float)view.getSize().y;
	float sizeX = 1;
	float sizeY = 1;
	float posX = 0;
	float posY = 0;

	bool horizontalSpacing = true;
	if (windowRatio < viewRatio)
		horizontalSpacing = false;

	// If horizontalSpacing is true, the black bars will appear on the left and right side.
	// Otherwise, the black bars will appear on the top and bottom.

	if (horizontalSpacing) {
		sizeX = viewRatio / windowRatio;
		posX = (1 - sizeX) / 2.f;
	}

	else {
		sizeY = windowRatio / viewRatio;
		posY = (1 - sizeY) / 2.f;
	}

	view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

	return view;

}
void windowProcess(sf::RenderWindow* window, Input* in, sf::View& view)
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::Resized:
            // Update the view to maintain the letterbox effect
            view = getLetterboxView(view, event.size.width, event.size.height);
            break;
        case sf::Event::KeyPressed:
            in->setKeyDown(event.key.code);
            break;
        case sf::Event::KeyReleased:
            in->setKeyUp(event.key.code);
            break;
        case sf::Event::MouseMoved:
            in->setMousePosition(event.mouseMove.x, event.mouseMove.y);
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                in->setLeftMouse(Input::MouseState::DOWN);
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                in->setRightMouse(Input::MouseState::DOWN);
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                in->setLeftMouse(Input::MouseState::UP);
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                in->setRightMouse(Input::MouseState::UP);
            }
            break;
        default:
            break;
        }
    }
}

int main()
{
    sf::View view;

    // Create the main window with a fixed size
    sf::RenderWindow window(sf::VideoMode(800, 600), "WindowsXP", sf::Style::Fullscreen);

    // Initialize the view with a fixed size and center
    view.setSize(282, 282);
    view.setCenter(view.getSize().x / 2, view.getSize().y / 2);

    // Set the initial letterbox view based on the window size
    view = getLetterboxView(view, 800, 600);

    // Initialise input and level objects.
    Input input;
    Level level(&window, &input);

    // Initialise objects for delta time
    sf::Clock clock;
    float deltaTime;

    // Game Loop
    while (window.isOpen())
    {
        // Process window events
        windowProcess(&window, &input, view);

        // Calculate delta time
        deltaTime = clock.restart().asSeconds();

        // Call standard game loop functions (input, update and render)
        level.handleInput(deltaTime);
        level.update(deltaTime);
        level.render();

        // Update input class, handle pressed keys
        // Must be done last.
        input.update();
    }

    return 0;
}


