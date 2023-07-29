#include "Polygon.hpp"

Polygon::Polygon()
{

}

/// @brief Constructor for a polygon shape that persists in memory until deleted.
Polygon::Polygon(sf::Vector2f first, sf::Vector2f second, sf::Vector2f third, sf::Color color)
{
    sf::Vertex vert;

    vertices.setPrimitiveType(sf::TriangleFan);
    // outlines.setPrimitiveType(sf::LineStrip);

    vert.position = first;
    vert.color = color;
    vertices.append(vert);

    vert.position = second;
    vertices.append(vert);

    vert.position = third;
    vertices.append(vert);

    // Outlines may not actually render over shapes,
    // no idea what causes this.

    outlines[0].position = first;
    outlines[1].position = second;
    outlines[2].position = third;

    for(int i = 0; i < 3; i++)
    {
        outlines[i].color = sf::Color::Black;
    }
}

Polygon::~Polygon()
{
    vertices.clear();
}

void Polygon::render(sf::RenderTarget* target)
{
    target->draw(vertices);
    target->draw(outlines, 3, sf::Lines);
}

void Polygon::update()
{
    vertices.getPrimitiveType();
}