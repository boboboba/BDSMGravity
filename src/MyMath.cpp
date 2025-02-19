//
// Created by palka228 on 16.02.2025.
//
#include "MyMath.h"
#include <cmath>


sf::Vector2f MyMath::Normalized(sf::Vector2f vector) {
    float length = Length(vector);
    return length != 0? vector / length : vector;
}

float MyMath::Length(sf::Vector2f vector) {
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}
