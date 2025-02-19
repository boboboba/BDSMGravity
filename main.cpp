#include <iostream>
#include <SFML//Graphics.hpp>

#include "Button.h"
#include "Field.h"
#include "TextInput.h"
#include "UI.h"

int main() {
    Field field;
    Object object;
    object.setPosition(Vector2f(0,0));
    object.setVelocity(Vector2f(10,10));
    field.AddObject(std::make_shared<Object>(object));

    UI ui;
    ui.SetDefaultPreset(&field);

    sf::RenderWindow window(sf::VideoMode(1360, 720), "15");

    window.setFramerateLimit(60);
    sf::Event event{};

    Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        time /= 100;
        clock.restart();
        window.clear();

        field.Update(time);
        field.Draw(window);

        ui.Draw(window);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) window.close();
                if (event.key.code == sf::Keyboard::Q) field = Field();
            }
            MyEvent myEvent(event);
            ui.HandleEvent(myEvent);
            field.HandleEvent(myEvent);
        }

        window.display();
    }

    return 0;
}
