//
// Created by palka228 on 16.02.2025.
//

#ifndef MATH_H
#define MATH_H
#include <SFML/System/Vector2.hpp>

class MyMath {

public:
    static sf::Vector2f Normalized(sf::Vector2f vector);
    static float Length(sf::Vector2f vector);
};
#endif //MATH_H
