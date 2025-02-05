#pragma once

#include <memory>
#include "Beverage.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class Mocha {
   private:
    pro::proxy<Beverage> _beverage;

   public:
    explicit Mocha(pro::proxy<Beverage> beverage)
        : _beverage(std::move(beverage)) {}

    std::string getDescription() const {
        return _beverage->getDescription() + ", Mocha";
    }

    double cost() const { return 0.20 + _beverage->cost(); }
};
}  // namespace HeadFirstDesignPatterns::Decorator