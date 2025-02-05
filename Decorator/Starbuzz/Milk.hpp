#pragma once

#include <memory>
#include "Beverage.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class Milk {
   private:
    pro::proxy<Beverage> _beverage;

   public:
    explicit Milk(pro::proxy<Beverage> beverage)
        : _beverage(std::move(beverage)) {}

    std::string getDescription() const {
        return _beverage->getDescription() + ", Milk";
    }

    double cost() const { return 0.10 + _beverage->cost(); }
};
}  // namespace HeadFirstDesignPatterns::Decorator