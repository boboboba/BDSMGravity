//
// Created by palka228 on 16.02.2025.
//

#include "Field.h"

#include <iostream>

#include "MyMath.h"
#include "MyEvent.h"
#include <random>
#include <sstream>

double generateRandomDouble(double min, double max) {
    // Создаем генератор случайных чисел
    std::random_device rd;  // Источник случайных чисел
    std::mt19937 gen(rd()); // Генератор Мерсенна
    std::uniform_real_distribution<> dis(min, max); // Равномерное распределение

    return dis(gen); // Генерируем случайное дробное число
}

Vector2f calculateVelocity(Object object, Object other) {
    const Vector2f velocity(other.getPosition() - object.getPosition());
    constexpr float G = 1;
    float R = MyMath::Length(velocity);
    float coefficient = G * object.getMass() * other.getMass() / (R * R);
    if (std::isnan(coefficient))
        coefficient = 0.001;
    return MyMath::Normalized(velocity) * coefficient;
}



void Field::removeObject(std::vector<std::shared_ptr<Object>> &objects) {
    std::vector<std::shared_ptr<Object>> toRemove;
    for (const auto& object : objects  ) {
        const Vector2f position = object->getPosition();
        if (position.y > 2000 || position.y < -2000 || position.x < -2000 || position.x > 2000) {
            toRemove.push_back(object);
        }
    }
    std::erase_if(objects,
                  [&toRemove](const std::shared_ptr<Object>& obj) {
                      return std::ranges::find(toRemove, obj) != toRemove.end();
                  });
}

void Field::uniteObjects(std::vector<std::shared_ptr<Object>> &objects) {
    std::vector<std::shared_ptr<Object>> toRemove;
    std::vector<std::shared_ptr<Object>> toAdd;
    for (int i = 0; i < objects.size(); i++) {
        for (int j = i + 1; j < objects.size(); j++) {
            const auto& first = objects[i];
            const auto& second= objects[j];
            if (first != second) {
                float distance = MyMath::Length(first->getPosition() - second->getPosition());
                if (distance < (std::max(first->getRadius(), second->getRadius()))) {

                    Vector2f v1 = first->getVelocity();
                    Vector2f v2 = second->getVelocity();
                    float m1 = first->getMass();
                    float m2 = second->getMass();
                    Vector2f velocity = (v1 * m1 + v2 * m2) / (m1 + m2) / 10.0f;
                    Vector2f position;
                    sf::Color color;
                    if (first->getMass() > second->getMass()) {
                        position = first->getPosition();
                        color = first->getColor();
                    }
                    else {
                        position = second->getPosition();
                        color = second->getColor();
                    }
                    float mass = first->getMass() + second->getMass();
                    toRemove.push_back(first);
                    toRemove.push_back(second);
                    auto object = std::make_shared<Object>(position, velocity, mass);
                    object->setColor(color);
                    toAdd.push_back(object);
                }
            }
        }
    }
    std::erase_if(objects,
                  [&toRemove](const std::shared_ptr<Object>& obj) {
                      return std::ranges::find(toRemove, obj) != toRemove.end();
                  });
    for (const auto& object : toAdd) {
        AddObject(object);
    }

}

void Field::Update(float deltaTime) {
    for (const auto& object: objects) {
        Vector2f velocity(0,0);
        for (const auto& other: objects) {
            if (object != other) {
                velocity += calculateVelocity(*object, *other);
            }
        }
        object->Update(deltaTime, velocity);
    }
    removeObject(objects);
    uniteObjects(objects);
}

void Field::AddObject(std::shared_ptr<Object> object) {
    objects.push_back(object);
}

void Field::RemoveObject(std::shared_ptr<Object> object) {
    std::erase_if(objects,
                  [&object](const std::shared_ptr<Object>& obj) {
                      return obj == object; // Сравниваем указатели
                  });
}

void Field::Draw(RenderWindow &window) {
    for (const auto& object: objects) {
        object->Draw(window);
    }
}

void Field::HandleEvent(MyEvent &event) {
    if (event.handled)
        return;
    if (const Event sfEvent = event.event; sfEvent.type == Event::MouseButtonPressed) {
        Vector2f position(sfEvent.mouseButton.x, sfEvent.mouseButton.y);
        float mass = 10;
        float velX = 0;
        float velY = 0;
        sf::Color color = sf::Color::White;
        std::istringstream iss(locator.getMass());
        iss >> mass;
        iss = std::istringstream(locator.getVelocity());
        iss >> velX >> velY;
        iss = std::istringstream(locator.getColor());
        int r, g, b;
        iss >> r >> g >> b;
        color = sf::Color(r, g, b);
        // Vector2f randomVelocity(generateRandomDouble(-10, 1000 / mass), generateRandomDouble(-10, 10));
        auto object = std::make_shared<Object>(position, sf::Vector2f(velX, velY), mass);
        object->setColor(color);
        AddObject(object);
    }
    event.handled = true;
}



