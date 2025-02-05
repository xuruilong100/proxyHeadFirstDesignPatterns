#pragma once

#include <memory>
#include "Beverage.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class Soy {
   private:
    pro::proxy<Beverage> _beverage;

   public:
    explicit Soy(pro::proxy<Beverage> beverage)
        : _beverage(std::move(beverage)) {}

    std::string getDescription() const {
        return _beverage->getDescription() + ", Soy";
    }

    double cost() const { return 0.15 + _beverage->cost(); }
};
}  // namespace HeadFirstDesignPatterns::Decorator