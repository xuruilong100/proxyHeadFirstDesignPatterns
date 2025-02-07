#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class Screen {
   private:
    std::string _description;

   public:
    explicit Screen(std::string_view description) : _description(description) {}
    Screen(const Screen&) = delete;
    Screen& operator=(const Screen&) = delete;

    void up() const { std::cout << _description << " going up" << std::endl; }

    void down() const {
        std::cout << _description << " going down" << std::endl;
    }

    std::string toString() const { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater