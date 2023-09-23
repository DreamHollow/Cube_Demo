#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "Canvas.hpp"

/// @brief Actually handles program data; called in main.
class Application
{
public:
    Application();
    Application(sf::Vector2i size, unsigned int bits);
    virtual ~Application();

    void run();

private:
    // Variables
    std::string window_name;

    // Const
    const sf::Time time_per_frame = sf::seconds(1.f / 60.f);

    // Functions

    // Init
    void init_vars();

    // Update
    void update(sf::Time dt);
    void update_events();

    // Render
    void render();

    // Memory
    void free_data();

    // Objects
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event w_event;
    sf::VideoMode vid_mode;
    // sf::Time delta_time;
    std::unique_ptr<Canvas> canvas;
};

#endif