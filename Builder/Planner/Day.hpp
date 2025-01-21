#pragma once

#include <ctime>
#include <iostream>
#include <string>
#include "Event.hpp"
#include "EventComponent.hpp"

namespace HeadFirstDesignPatterns::Builder {
class Day {
   private:
    std::shared_ptr<Event> _event;
    tm _date;

   public:
    Day(std::shared_ptr<Event> event, const tm& date)
        : _event(event), _date(date) {}
    Day(const Day&) = default;
    Day& operator=(const Day&) = default;

    pro::proxy<EventComponent> add(pro::proxy<EventComponent> event) {
        return _event->add(event);
    }

    void remove(pro::proxy<EventComponent> event) {
        throw std::runtime_error("Not implemented!");
    }

    const pro::proxy<EventComponent>& getChild(int i) const {
        throw std::runtime_error("Not implemented!");
    }

    const std::string& getName() const {
        throw std::runtime_error("Not implemented!");
    }

    const std::string& getDescription() const {
        throw std::runtime_error("Not implemented!");
    }

    double getPrice() const { throw std::runtime_error("Not implemented!"); }

    void print() const {
        std::cout << _date.tm_year + 1900 << "-";
        std::cout << _date.tm_mon + 1 << "-";
        std::cout << _date.tm_mday << " : ";
        _event->print();
    }
};
}  // namespace HeadFirstDesignPatterns::Builder