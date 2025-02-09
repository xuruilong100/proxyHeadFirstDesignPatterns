#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class WildTurkey {
   private:
    inline static const std::string _type{"Wild Turkey"};
    inline static const std::string _sound{"Gobble gobble"};
    inline static const std::string _walk{"struts"};

   public:
    WildTurkey() = default;

    void gobble() const { std::cout << _sound; }

    void walk() const { std::cout << _walk; }

    std::string toString() const { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight