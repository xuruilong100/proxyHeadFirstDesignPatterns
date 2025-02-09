#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class MallardDuck {
   private:
    inline static const std::string _type{"Mallard Duck"};
    inline static const std::string _sound{"Quack"};
    inline static const std::string _swim{"swims"};

   public:
    MallardDuck() = default;

    void quack() const { std::cout << _sound; }

    void swim() const { std::cout << _swim; }

    std::string toString() const { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight