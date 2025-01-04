#pragma once

#include <iostream>
#include <string_view>

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class Sony {
   private:
    std::string _location;

   public:
    explicit Sony(std::string_view location) : _location(location) {}

    void on() { std::cout << "Sony " << _location << " TV is on" << std::endl; }

    void off() {
        std::cout << "Sony " << _location << " TV is off" << std::endl;
    }

    void tuneChannel(unsigned int channel) {
        std::cout << "Sony " << _location << " tuned to channel " << channel
                  << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes