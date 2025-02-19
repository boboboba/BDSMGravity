//
// Created by palka228 on 16.02.2025.
//
#include "Button.h"

Button::Button(float x, float y, float w, float h, sf::Text &text): UiElement(x, y, w, h) {
    this->text = text;
    this->text.setPosition(x, y);
}

void Button::SetOnClick(std::function<void()> *onClick) {
    this->onClick = *onClick;
}

void Button::HandleEvent(MyEvent &event) {
    UiElement::HandleEvent(event);
}

void Button::Update() {
    UiElement::Update();
}

void Button::Draw(sf::RenderWindow &window) {
    UiElement::Draw(window);
    window.draw(rect);
    window.draw(text);
}
