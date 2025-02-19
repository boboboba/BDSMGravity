//
// Created by palka228 on 16.02.2025.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <functional>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

#include "MyEvent.h"
#include "UiElement.h"

class Button final : public UiElement {
    std::function<void()> onClick;
    sf::RectangleShape rect;
    sf::Text text;
public:
    Button(float x, float y, float w, float h, sf::Text& text);
    void SetOnClick(std::function<void()> *onClick);
    void HandleEvent(MyEvent &event) override;
    void Update() override;
    void Draw(sf::RenderWindow &window) override;
};
#endif //BUTTON_H
