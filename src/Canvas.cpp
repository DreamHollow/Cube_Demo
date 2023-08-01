#include "Canvas.hpp"

Canvas::Canvas()
{

}

Canvas::Canvas(sf::Vector2f size)
{
    x = 0.f;
    y = 0.f;

    background.setPosition(sf::Vector2f(x,y));
    background.setFillColor(sf::Color(50,50,50));
    background.setSize(size);

    init_objects();
}

Canvas::~Canvas()
{
    free_data();
}

void Canvas::init_objects()
{
    sf::Vector2f one{300.f, 200.f};
    sf::Vector2f two{500.f, 200.f};
    sf::Vector2f three{500.f, 400.f};

    Polygon first_poly(one,two,three,sf::Color::Blue); // Top half of front face
    polygons.push_back(first_poly);

    one = sf::Vector2f(500.f, 400.f);
    two = sf::Vector2f(300.f, 200.f);
    three = sf::Vector2f(300.f, 400.f);

    Polygon second_poly(one,two, three,sf::Color::Blue); // Bottom half of front face
    polygons.push_back(second_poly);

    one = sf::Vector2f(300.f, 200.f);
    two = sf::Vector2f(400.f, 100.f);
    three = sf::Vector2f(600.f, 100.f);

    Polygon third_poly(one,two,three,sf::Color::Red); // Top half of top face
    polygons.push_back(third_poly);

    one = sf::Vector2f(300.f, 200.f);
    two = sf::Vector2f(500.f, 200.f);
    three = sf::Vector2f(600.f, 100.f);

    Polygon fourth_poly(one,two,three,sf::Color::Red); // Bottom half of top face
    polygons.push_back(fourth_poly);

    one = sf::Vector2f(600.f, 100.f);
    two = sf::Vector2f(600.f, 300.f);
    three = sf::Vector2f(500.f, 200.f);

    Polygon fifth_poly(one,two,three,sf::Color::Green); // Top half of side face
    polygons.push_back(fifth_poly);

    one = sf::Vector2f(500.f, 200.f);
    two = sf::Vector2f(500.f, 400.f);
    three= sf::Vector2f(600.f, 300.f);

    Polygon sixth_poly(one,two,three,sf::Color::Green); // Bottom half of side face
    polygons.push_back(sixth_poly);
}

void Canvas::render(sf::RenderTarget* target)
{
    target->draw(background);
    // target->draw();

    for(auto it : polygons)
    {
        it.render(target);
    }
}

void Canvas::update()
{
    background.getPosition();
    background.getFillColor();
    background.getSize();

    for(auto it : polygons)
    {
        it.update();
    }
}

void Canvas::free_data()
{
    polygons.clear();
    polygons.shrink_to_fit();

    if(debug)
    {
        std::cout << db_string << "Polygons vector cleared.\n";
    }
}