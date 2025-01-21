#pragma once

#include <iostream>
#include <memory>
#include "Event.hpp"

namespace HeadFirstDesignPatterns::Builder {
class Vacation {
   private:
    std::shared_ptr<Event> _allEvents;

   public:
    explicit Vacation(std::shared_ptr<Event> allEvents)
        : _allEvents(std::move(allEvents)) {}
    Vacation(const Vacation&) = default;

    void printItinerary() const {
        std::cout << std::endl;
        _allEvents->print();
    }
};
}  // namespace HeadFirstDesignPatterns::Builder