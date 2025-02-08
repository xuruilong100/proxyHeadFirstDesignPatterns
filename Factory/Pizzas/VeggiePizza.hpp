#pragma once

#include <list>
#include <string>

namespace HeadFirstDesignPatterns::Factory::Simple {
class VeggiePizza {
   private:
    inline static const std::string _name{"Veggie Pizza"};
    inline static const std::string _dough{"Crust"};
    inline static const std::string _sauce{"Marinara Sauce"};
    inline static const std::list<std::string> _toppings{
        "Fresh Mozzarella", "Grated Parmesan",   "Diced onion",
        "Sliced mushrooms", "Sliced red pepper", "Sliced black olives"};

   public:
    VeggiePizza() = default;

    const std::string& name() const { return _name; }
    const std::string& dough() const { return _dough; }
    const std::string& sauce() const { return _sauce; }
    const std::list<std::string>& toppings() const { return _toppings; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple