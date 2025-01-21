#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include "EventComponent.hpp"

namespace HeadFirstDesignPatterns::Builder {
class EventItem {
   private:
    std::string _name;
    std::string _description;
    double _price;

   public:
    EventItem(std::string_view name,
              std::string_view description,
              double price = 0.0)
        : _name(name), _description(description), _price(price) {}
    EventItem(const EventItem&) = default;

    pro::proxy<EventComponent> add(pro::proxy<EventComponent> event) {
        throw std::runtime_error("Not implemented!");
    }
    void remove(pro::proxy<EventComponent> event) {
        throw std::runtime_error("Not implemented!");
    }
    const pro::proxy<EventComponent>& getChild(int i) const {
        throw std::runtime_error("Not implemented!");
    }

    const std::string& getName() const { return _name; }
    const std::string& getDescription() const { return _description; }
    double getPrice() const { return _price; }
    void print() const {
        std::cout << "   " << getName();
        std::cout << " , " << getDescription();
        std::cout << "- $" << getPrice() << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Builder