#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class RubberDuck {
   private:
    inline static const std::string _type{"Rubber Duck"};
    inline static const std::string _sound{"Squeak"};
    inline static const std::string _swim{"floats"};

   public:
    RubberDuck() = default;

    void quack() const { std::cout << _sound; }

    void swim() const { std::cout << _swim; }

    std::string toString() const { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight