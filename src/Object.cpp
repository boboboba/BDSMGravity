//
// Created by palka228 on 16.02.2025.
//

#include "Object.h"

Vector2f Object::getPosition() const {
    return position;
}

void Object::setPosition(const Vector2f position) {
    this->position = position;
}

void Object::setVelocity(const Vector2f velocity) {
    this->velocity = velocity;
}

void Object::setColor(sf::Color color) {
    this->color = color;
}

sf::Color Object::getColor() {
    return this->color;
}

float Object::getMass() {
    return mass;
}

float Object::getRadius() {
    auto radius = fmax(pow(mass, 0.5), 4);
    return radius;
}

Vector2f Object::getVelocity() const {
    return velocity;
}

void Object::Update(const float deltaTime, const Vector2f velocity) {
    this->velocity += velocity / mass;
    position += deltaTime * this->velocity;

}

void Object::Draw(RenderWindow &window) {
    sf::CircleShape circle(getRadius());
    circle.setPosition(position - Vector2f{getRadius(), getRadius()});
    circle.setFillColor(color);
    window.draw(circle);
}


