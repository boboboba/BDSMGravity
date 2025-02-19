//
// Created by palka228 on 16.02.2025.
//
#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

#ifndef OBJECT_H
#define OBJECT_H

class Object {
private:
    float mass = 10;
    Vector2f velocity;
    Vector2f position;
    sf::Color color = sf::Color::White;

public:
    Object() = default;
    Object(const Vector2f position, const Vector2f velocity, float mass = 1) : velocity(velocity), position(position), mass(mass) {};
    Vector2f getVelocity() const;
    Vector2f getPosition() const;
    void setPosition(Vector2f position);
    void setVelocity(Vector2f velocity);
    void setColor(sf::Color color);
    sf::Color getColor();
    float getMass();
    float getRadius();
    void Update(float deltaTime, Vector2f velocity);
    void Draw(RenderWindow &window);
};
#endif //OBJECT_H
