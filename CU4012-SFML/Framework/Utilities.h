#ifndef UTILITY_H
#define UTILITY_H

#include <wtypes.h>
#include <SFML/Graphics.hpp>
#include <windows.h>

// Inline variables introduced in C++17 to handle definitions directly in header files
inline int SCREEN_WIDTH;
inline int SCREEN_HEIGHT;

inline sf::RenderWindow* window;

inline void GetActualResolution(int& horizontal, int& vertical) {
    DEVMODE devMode;
    ZeroMemory(&devMode, sizeof(DEVMODE));
    devMode.dmSize = sizeof(DEVMODE);

    if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode)) {
        horizontal = devMode.dmPelsWidth;
        vertical = devMode.dmPelsHeight;
    }
    else {
        // Fallback if the EnumDisplaySettings fails
        horizontal = GetSystemMetrics(SM_CXSCREEN);
        vertical = GetSystemMetrics(SM_CYSCREEN);
    }
}

inline void InitializeResolution(sf::RenderWindow* win) {
    GetActualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);
    window = win;
}
#endif // UTILITY_H


// Function to create and display a debug message on the screen
void printDebugMessage(sf::RenderWindow& win, const std::string& msg, ...) {
    // Create a buffer to hold the formatted message
    std::string formattedMsg;

    // Use variadic arguments to format the message
    va_list args;
    va_start(args, msg);
    formattedMsg = std::vsnprintf(nullptr, 0, msg.c_str(), args);
    va_end(args);

    // Create an sf::Text object to display the message
    sf::Font font;
    if (!font.loadFromFile("font/arial.ttf")) {
        // Handle error
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24); // Set the font size
    text.setFillColor(sf::Color::Green); // Set the font color
    text.setString(formattedMsg);

    // Assuming you have a window object to draw the text
    sf::RenderWindow& window = win;// Or any other window object you have

    // Clear the window
    window.clear();

    // Draw the text on the window
    window.draw(text);

    // Display the window
    window.display();
}