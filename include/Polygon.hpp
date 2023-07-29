#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Globals.h"

/// @brief Class that creates and renders triangles through coordinates.
class Polygon
{
public:
    Polygon();
    Polygon(sf::Vector2f first, sf::Vector2f second, sf::Vector2f third, sf::Color color);
    virtual ~Polygon();

    // Update
    void update();

    // Render
    void render(sf::RenderTarget* target);

private:
    // Variables

    // Functions

    // Memory

    // Objects
    sf::VertexArray vertices;
    sf::Vertex outlines[3];
};

#endif