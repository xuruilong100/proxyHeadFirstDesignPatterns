#pragma once

#include <iostream>
#include <string_view>

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class RCA {
   private:
    std::string _location;

   public:
    explicit RCA(std::string_view location) : _location(location) {}

    void on() { std::cout << "RCA " << _location << " TV is on" << std::endl; }

    void off() {
        std::cout << "RCA " << _location << " TV is off" << std::endl;
    }

    void tuneChannel(unsigned int channel) {
        std::cout << "RCA " << _location << " tuned to channel " << channel
                  << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes