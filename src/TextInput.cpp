//
// Created by palka228 on 17.02.2025.
//

#include "TextInput.h"

#include <iostream>
#include <SFML/Graphics/Text.hpp>

void TextInput::inputText(int character) {
    string << static_cast<char>(character);
}

void TextInput::tryDeleteLastChar() {
    std::string t = string.str();
    if (t.empty()) {
        return;
    }

    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++) {
        newT += t[i];
    }
    string.str("");
    string << newT;
}



TextInput::TextInput(float x, float y, float width, float height, sf::Font &font): UiElement(x, y, width, height) {
    sfText.setPosition(getPosition());
    sfText.setCharacterSize((int)height / 2);
    sfText.setFillColor(sf::Color::Black);
    sfText.setFont(font);
    sfText.setString("");
    // rect.setFillColor(sf::Color::White);
}

std::string TextInput::getText() {
    return string.str();
}

void TextInput::HandleEvent(MyEvent &event) {
    UiElement::HandleEvent(event);

    if (event.handled) {
        return;
    }
    sf::Event sfEvent = event.event;
    if (sfEvent.type == sf::Event::MouseButtonPressed) {
        if (rect.getGlobalBounds().contains(sfEvent.mouseButton.x, sfEvent.mouseButton.y)) {
            active = true;
            event.handled = true;
        }
        else {
            active = false;
        }

    }

    else if (sfEvent.type == sf::Event::TextEntered) {
        if (active) {
            //Backspace
            if (sfEvent.text.unicode != 8) {
                inputText(sfEvent.text.unicode);
            }
            else {
                tryDeleteLastChar();
            }

        }
    }
    sfText.setString(string.str());
}

void TextInput::Draw(sf::RenderWindow &window) {
    UiElement::Draw(window);
    // string += "1";
    window.draw(rect);;
    window.draw(sfText);
}
