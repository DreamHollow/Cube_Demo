#include "Application.hpp"

int main()
{
    Application app(sf::Vector2i(800,600), 32);

    app.run();

    return 0;
}