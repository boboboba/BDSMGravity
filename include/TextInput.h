//
// Created by palka228 on 17.02.2025.
//

#ifndef TEXTINPUT_H
#define TEXTINPUT_H
#include <sstream>
#include <SFML/Graphics/Text.hpp>

#include "UiElement.h"

class TextInput : public UiElement {
    std::ostringstream string;
    sf::Text sfText;
    bool active = false;
    void inputText(int character);
    void tryDeleteLastChar();
    public:
    TextInput(float x, float y, float width, float height, sf::Font& font);
    std::string getText();
    void HandleEvent(MyEvent &event) override;
    void Draw(sf::RenderWindow &window) override;
};
#endif //TEXTINPUT_H
