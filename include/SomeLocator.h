//
// Created by palka228 on 19.02.2025.
//

#ifndef SOMELOCATOR_H
#define SOMELOCATOR_H
#include <functional>
#include <string>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

class SomeLocator {
    public:
    std::function<std::string()> getMass;
    std::function<std::string()> getVelocity;
    std::function<std::string()> getColor;
};
#endif //SOMELOCATOR_H
