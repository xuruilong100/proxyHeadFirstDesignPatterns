#include "Pizza.hpp"
#include <iostream>
#include <sstream>

namespace HeadFirstDesignPatterns::Factory::Method {
std::string toString(const pro::proxy<Pizza>& pizza) {
    // code to display pizza name and ingredients
    std::stringstream value;
    value << "---- " << pizza->name() << " ----" << std::endl;
    value << pizza->dough() << std::endl;
    value << pizza->sauce() << std::endl;
    for (const auto& top : pizza->toppings()) {
        value << top << std::endl;
    }
    return value.str();
}
}  // namespace HeadFirstDesignPatterns::Factory::Method