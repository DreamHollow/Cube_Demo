#include "Application.hpp"

Application::Application()
{

}

Application::Application(sf::Vector2i size, unsigned int bits)
{
    init_vars();

    vid_mode.width = size.x;
    vid_mode.height = size.y;
    vid_mode.bitsPerPixel = bits;

    try
    {
        if(!vid_mode.isValid())
        {
            std::cout << "ERROR: Invalid window arguments. ";
            std::cout << "Window object could not be created.\n";

            free_data();

            throw "Invalid window settings!";
        }
        else
        {
            sf::Vector2i window_pos{
                static_cast<int>(sf::VideoMode::getDesktopMode().width / 3.5),
                static_cast<int>(sf::VideoMode::getDesktopMode().height / 4)
            };

            window = new sf::RenderWindow(vid_mode, window_name, sf::Style::Close);
            window->setPosition(window_pos);
            canvas = new Canvas(sf::Vector2f(vid_mode.width, vid_mode.height));
        }
    }
    catch(const std::exception e)
    {
        std::cerr << e.what();
    }
}

Application::~Application()
{
    free_data();

    if(debug)
    {
        std::cout.clear();
        std::cin.clear();

        std::cout << db_string << "Memory objects freed.\n";
    }
}

void Application::init_vars()
{
    this->window_name = "Cube Demo";
}

void Application::update(sf::Time dt)
{
    canvas->update();
}

void Application::update_events()
{
    while(window->pollEvent(w_event))
    {
        switch(w_event.type)
        {
            case sf::Event::Closed:
            {
                window->close();
                break;
            }
        }
    }
}

void Application::render()
{
    window->clear();

    // Render Items
    canvas->render(window);

    window->display();
}

void Application::run()
{
    sf::Clock dt_clock;
    sf::Time time_since_update = sf::Time::Zero;

    while(window->isOpen())
    {
        update_events();
        time_since_update += dt_clock.restart();
        while(time_since_update > time_per_frame)
        {
            time_since_update -= time_per_frame;
            update_events();
            update(time_per_frame);
        }
        render();
    }
}

/// @brief Calls functions that check and delete heap memory.
void Application::free_data()
{
    free(window);
    free(canvas);
}

/// @brief Function deletes a memory object, if it exists.
/// Not to be confused with C based 'free()' which serves a similar purpose.
void Application::free(sf::RenderWindow* win)
{
    if(win)
    {
        delete win;
    }
    else
    {
        if(debug)
        {
            std::cout << db_string << "Could not free window object, not allocated.\n";
        }
    }
}

void Application::free(Canvas* can)
{
    if(can)
    {
        delete can;
    }
    else
    {
        if(debug)
        {
            std::cout << db_string << "Could not free canvas object, not allocated.\n";
        }
    }
}