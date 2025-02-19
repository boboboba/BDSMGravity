//
// Created by palka228 on 16.02.2025.
//
#include "UiElement.h"

UiElement::UiElement(float x, float y, float width, float height) {
    rect.setSize(sf::Vector2f(width, height));
    rect.setPosition(sf::Vector2f(x, y));
    setPosition(sf::Vector2f(x, y));
}

sf::Vector2f UiElement::getPosition() {
    return position;
}

void UiElement::setPosition(sf::Vector2f position) {
    this->position = position;
    rect.setPosition(position.x, position.y);
}

void UiElement::HandleEvent(MyEvent &event) {
}

void UiElement::Update() {
}

void UiElement::Draw(sf::RenderWindow &window) {
}
