//
// Created by palka228 on 16.02.2025.
//

#ifndef UI_H
#define UI_H
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Field.h"
#include "MyEvent.h"
#include "UiElement.h"

class UI {
    std::vector<UiElement*> elements;
    Field *field = nullptr;
    public:
    void SetDefaultPreset(Field *field);
    void AddElement(UiElement* element);
    void Update();
    void HandleEvent(MyEvent &event);
    void Draw(sf::RenderWindow &window);
};
#endif //UI_H
