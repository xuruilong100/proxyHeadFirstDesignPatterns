#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include "EventComponent.hpp"

namespace HeadFirstDesignPatterns::Builder {
class Event {
   private:
    std::vector<pro::proxy<EventComponent>> _events;
    std::string _name;
    std::string _description;

   public:
    Event(std::string_view name, std::string_view description)
        : _name(name), _description(description) {}
    Event(const Event&) = default;

    pro::proxy<EventComponent> add(pro::proxy<EventComponent> event) {
        _events.push_back(event);
        return event;
    }

    void remove(pro::proxy<EventComponent> event) {
        auto it = std::remove_if(_events.begin(), _events.end(),
                                 [&](auto x) { return &*x == &*event; });
        _events.erase(it, _events.end());
    }

    const pro::proxy<EventComponent>& getChild(int i) const {
        return _events[i];
    }

    const std::string& getName() const { return _name; }

    const std::string& getDescription() const { return _description; }

    double getPrice() const { throw std::runtime_error("Not implemented!"); }

    void print() const {
        std::cout << "  " << getName();
        std::cout << ", " << getDescription() << std::endl;

        for (const auto& event : _events) {
            event->print();
        }
    }

    int getChildCount() const { return static_cast<int>(_events.size()); }
};
}  // namespace HeadFirstDesignPatterns::Builder