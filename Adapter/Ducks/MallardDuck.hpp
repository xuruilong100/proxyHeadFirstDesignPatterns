#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::Adapter::Ducks {
struct MallardDuck {
   public:
    void fly() const { std::cout << "I'm flying" << std::endl; }
    void quack() const { std::cout << "Quack" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks