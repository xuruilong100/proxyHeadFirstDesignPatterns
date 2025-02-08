#pragma once

#include <list>
#include <string>

namespace HeadFirstDesignPatterns::Factory::Simple {
class CheesePizza {
   private:
    inline static const std::string _name{"Cheese Pizza"};
    inline static const std::string _dough{"Regular Crust"};
    inline static const std::string _sauce{"Marinara Pizza Sauce"};
    inline static const std::list<std::string> _toppings{"Shredded Mozzarella",
                                                         "Parmesan"};

   public:
    CheesePizza() = default;

    const std::string& name() const { return _name; }
    const std::string& dough() const { return _dough; }
    const std::string& sauce() const { return _sauce; }
    const std::list<std::string>& toppings() const { return _toppings; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple