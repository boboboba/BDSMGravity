//
// Created by palka228 on 16.02.2025.
//
#include <functional>
#include "UI.h"

#include "Button.h"
#include "TextInput.h"


void UI::SetDefaultPreset(Field *field) {
    Font *font = new Font;
    font->loadFromFile("sans.ttf");
    float h = 50;
    float w = 200;
    auto *massInput = new TextInput(0,h,w,h,*font);
    auto *velocityInput = new TextInput(0,3*h,w,h,*font);
    auto *colorInput = new TextInput(0,5 * h,w,h,*font);

    sf::Text text1("mass", *font);
    sf::Text text2("velocity", *font);
    sf::Text text3("color", *font);
    auto *button1 = new Button(0,0, w, h, text1);
    auto *button2 = new Button(0,2 * h, w, h, text2);
    auto *button3 = new Button(0,4 * h, w, h, text3);

    AddElement(massInput);
    AddElement(velocityInput);
    AddElement(colorInput);
    AddElement(button1);
    AddElement(button2);
    AddElement(button3);

    field->locator.getMass = [massInput] { return massInput->getText(); };
    field->locator.getColor = [colorInput] { return colorInput->getText(); };
    field->locator.getVelocity = [velocityInput] { return velocityInput->getText(); };
}

void UI::AddElement(UiElement *element) {
    elements.push_back(element);
}

void UI::Update() {
}

void UI::HandleEvent(MyEvent &event) {
    for (auto element : elements) {
        element->HandleEvent(event);
    }
}

void UI::Draw(sf::RenderWindow &window) {
    for (auto & element : elements) {
        element->Draw(window);
    }
}
