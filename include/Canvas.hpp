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
    void free(Polygon *poly);
    void free_data();

    // Objects
    sf::RectangleShape background;
    Polygon *first_poly;
    Polygon *second_poly;
    Polygon *third_poly;
    Polygon *fourth_poly;
    Polygon *fifth_poly;
    Polygon *sixth_poly;
    std::vector<Polygon*> polygons;
};

#endif