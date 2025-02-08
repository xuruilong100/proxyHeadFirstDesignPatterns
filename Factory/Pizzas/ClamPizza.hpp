#pragma once

#include <list>
#include <string>

namespace HeadFirstDesignPatterns::Factory::Simple {
class ClamPizza {
   private:
    inline static const std::string _name{"Clam Pizza"};
    inline static const std::string _dough{"Thin Crust"};
    inline static const std::string _sauce{"White garlic Sauce"};
    inline static const std::list<std::string> _toppings{
        "Grated parmesan cheese", "Clams"};

   public:
    ClamPizza() = default;

    const std::string& name() const { return _name; }
    const std::string& dough() const { return _dough; }
    const std::string& sauce() const { return _sauce; }
    const std::list<std::string>& toppings() const { return _toppings; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple