#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class RedheadDuck {
   private:
    inline static const std::string _type{"Redhead Duck"};
    inline static const std::string _sound{"Quack"};
    inline static const std::string _swim{"swims"};

   public:
    RedheadDuck() = default;

    void quack() const { std::cout << _sound; }

    void swim() const { std::cout << _swim; }

    std::string toString() const { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight