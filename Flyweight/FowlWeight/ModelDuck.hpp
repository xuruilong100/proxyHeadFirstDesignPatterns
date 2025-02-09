#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class ModelDuck {
   private:
    inline static const std::string _type{"Model duck"};
    inline static const std::string _sound{"<< Silence >>"};
    inline static const std::string _swim{"sinks"};

   public:
    ModelDuck() = default;

    void quack() const { std::cout << _sound; }

    void swim() const { std::cout << _swim; }

    std::string toString() const { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight