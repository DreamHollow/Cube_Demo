#ifndef CANVAS_HPP
#define CANVAS_HPP
#include "Polygon.hpp"

/// @brief Rendering area. Translates all render objects to window.
class Canvas
{
public:
    Canvas();
    Canvas(sf::Vector2f size);
    virtual ~Canvas();

    // Update
    void update();

    // Render
    void render(sf::RenderTarget* target);

private:
    // Variables
    float x;
    float y;

    // Functions

    // Init
    void init_objects();

    // Memory
    void free();

    // Objects
    sf::RectangleShape background;
    std::vector<Polygon> polygons;
};

#endif