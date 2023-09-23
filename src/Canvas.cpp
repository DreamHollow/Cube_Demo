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

void Canvas::create_polygon(sf::Vector2f One, sf::Vector2f Two, sf::Vector2f Three, sf::Color color)
{
    std::shared_ptr<Polygon> poly = std::make_shared<Polygon>(One, Two, Three, color);

    polygons.push_back(poly);
}

void Canvas::init_objects()
{
    sf::Vector2f one{300.f, 200.f};
    sf::Vector2f two{500.f, 200.f};
    sf::Vector2f three{500.f, 400.f};

    create_polygon(one, two, three, sf::Color::Blue);

    one = sf::Vector2f(500.f, 400.f);
    two = sf::Vector2f(300.f, 200.f);
    three = sf::Vector2f(300.f, 400.f);

    create_polygon(one, two, three, sf::Color::Blue);

    one = sf::Vector2f(300.f, 200.f);
    two = sf::Vector2f(400.f, 100.f);
    three = sf::Vector2f(600.f, 100.f);

    create_polygon(one, two, three, sf::Color::Red);

    one = sf::Vector2f(300.f, 200.f);
    two = sf::Vector2f(500.f, 200.f);
    three = sf::Vector2f(600.f, 100.f);

    create_polygon(one, two, three, sf::Color::Red);

    one = sf::Vector2f(600.f, 100.f);
    two = sf::Vector2f(600.f, 300.f);
    three = sf::Vector2f(500.f, 200.f);

    create_polygon(one, two, three, sf::Color::Green);

    one = sf::Vector2f(500.f, 200.f);
    two = sf::Vector2f(500.f, 400.f);
    three = sf::Vector2f(600.f, 300.f);

    create_polygon(one, two, three, sf::Color::Green);
}

void Canvas::render(std::shared_ptr<sf::RenderTarget> target)
{
    target->draw(background);
    // target->draw();

    for(auto it : polygons)
    {
        it->render(target);
    }
}

void Canvas::update()
{
    background.getPosition();
    background.getFillColor();
    background.getSize();

    for(auto it : polygons)
    {
        it->update();
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