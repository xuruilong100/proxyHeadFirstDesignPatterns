#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class TheaterLights {
   private:
    std::string _description;

   public:
    explicit TheaterLights(std::string_view description)
        : _description(description) {}
    TheaterLights(const TheaterLights&) = delete;
    TheaterLights& operator=(const TheaterLights&) = delete;

    void on() const { std::cout << _description << " on" << std::endl; }

    void off() const { std::cout << _description << " off" << std::endl; }

    void dim(int level) const {
        std::cout << _description << " dimming to " << level << "%"
                  << std::endl;
    }

    std::string toString() const { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater