#pragma once

#include <list>
#include <string>

namespace HeadFirstDesignPatterns::Factory::Simple {
class PepperoniPizza {
   private:
    inline static const std::string _name{"Pepperoni Pizza"};
    inline static const std::string _dough{"Crust"};
    inline static const std::string _sauce{"Marinara sauce"};
    inline static const std::list<std::string> _toppings{
        "Sliced Pepperoni", "Sliced Onion", "Grated parmesan cheese"};

   public:
    PepperoniPizza() = default;

    const std::string& name() const { return _name; }
    const std::string& dough() const { return _dough; }
    const std::string& sauce() const { return _sauce; }
    const std::list<std::string>& toppings() const { return _toppings; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple