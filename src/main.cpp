#include "main.h"


sf::Vector2f normalize(const sf::Vector2f& vector) {
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    if (magnitude != 0) {
        return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
    } else {
        // Handle the case where the vector has zero magnitude to avoid division by zero.
        return sf::Vector2f(0.f, 0.f);
    }
    }

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 450), "Hello, World!"); // Create the window

    sf::CircleShape shape(30.f); // Draw a shape
    shape.setFillColor(sf::Color::Green); // Color the shape

    sf::Clock clock; // Initialize clock
    window.setFramerateLimit(60); // Set framerate limit

    float speed = 2.0f; // Set default movement speed

    

    // Main application loop
    while (window.isOpen())
    {
        // Reset timer to zero and return time elapsed since last restart
        float currentTime = clock.restart().asSeconds();

        // Calculate fps (currentTime is equivalent of seconds per frame. The reciprocal gives frames per second.)
        float fps = 1.0f / currentTime;

        std::cout << "fps: " << fps << std::endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        sf::Vector2f direction;

        if(sf::Event::KeyPressed){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                direction.x -= 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                direction.x += 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                direction.y -= 1;
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                direction.y += 1;
             }

            sf::Vector2f normalizedDirection = normalize(direction);

            shape.move(normalizedDirection * speed);
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}