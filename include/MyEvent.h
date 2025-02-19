//
// Created by palka228 on 16.02.2025.
//

#ifndef MYEVENT_H
#define MYEVENT_H
#include <SFML/Window/Event.hpp>

class MyEvent {
public:
    sf::Event event;
    bool handled = false;
    explicit MyEvent(sf::Event event);
};
#endif //MYEVENT_H
