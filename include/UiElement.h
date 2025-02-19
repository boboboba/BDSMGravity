//
// Created by palka228 on 16.02.2025.
//

#ifndef UIELEMENT_H
#define UIELEMENT_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "MyEvent.h"

class UiElement{
protected:
    sf::Vector2f position;
    sf::RectangleShape rect;
public:
    virtual ~UiElement() = default;
    UiElement(float x, float y, float width, float height);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);
    virtual void HandleEvent(MyEvent &event);
    virtual void Update();
    virtual void Draw(sf::RenderWindow &window);
};
#endif //UIELEMENT_H
