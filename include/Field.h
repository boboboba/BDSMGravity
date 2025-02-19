//
// Created by palka228 on 16.02.2025.
//
#pragma once

#include "Object.h"
#include "Field.h"
#include <vector>

#include "MyEvent.h"
#include "SomeLocator.h"

using namespace sf;
#ifndef FIELD_H
#define FIELD_H


class Field {
private:
    std::vector<std::shared_ptr<Object>> objects;
    void removeObject(std::vector<std::shared_ptr<Object>> &objects);
    void uniteObjects(std::vector<std::shared_ptr<Object>> &objects);
public:
    SomeLocator locator;
    void Update(float deltaTime);
    void AddObject(std::shared_ptr<Object> object);
    void RemoveObject(std::shared_ptr<Object> object);
    void Draw(RenderWindow &window);
    void HandleEvent(MyEvent &event);
};

#endif //FIELD_H
