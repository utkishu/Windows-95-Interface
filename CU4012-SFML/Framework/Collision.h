// Collision Class
// Provides default functions for testing collision detection. Functions for standard axis aligned bounding box, and bounding circle.

#pragma once
#include "GameObject.h"

// Static class provide collision detection functions.
class Collision
{
public:
	// Check AABB for collision. Returns true if collision occurs.
	static bool checkBoundingBox(GameObject* sp1, GameObject* sp2);
	// Check collision with box and point. Returns true if collision occurs.
	static bool checkBoundingBox(GameObject* s1, sf::Vector2i s2);
	// Check bounding circle collision. Returns true if collision occurs.
	static bool checkBoundingCircle(GameObject* sp1, GameObject* sp2);
	//Check collision with box without it being a gameObject and point. Returns true if collision occurs.
	static bool checkBoundingBox(sf::FloatRect s1, sf::Vector2i s2);

};