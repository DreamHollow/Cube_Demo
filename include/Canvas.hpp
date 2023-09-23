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
    void render(std::shared_ptr<sf::RenderTarget> target);

private:
    // Variables
    float x;
    float y;

    // Functions

    // Init
    void create_polygon(sf::Vector2f One, sf::Vector2f Two, sf::Vector2f Three, sf::Color color);
    void init_objects();

    // Memory
    //void free(Polygon *poly);
    void free_data();

    // Objects
    sf::RectangleShape background;
    std::vector<std::shared_ptr<Polygon>> polygons;
};

#endif