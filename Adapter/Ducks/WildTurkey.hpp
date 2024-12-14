#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::Adapter::Ducks {
struct WildTurkey {
   public:
    void fly() const {
        std::cout << "I'm flying a short distance" << std::endl;
    }
    void gobble() const { std::cout << "Gobble gobble" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks