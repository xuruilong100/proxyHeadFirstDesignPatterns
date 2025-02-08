#include "Pizza.hpp"
#include <iostream>
#include <sstream>

namespace HeadFirstDesignPatterns::Factory::Simple {
void prepare(const pro::proxy<Pizza>& pizza) {
    std::cout << "Preparing " << pizza->name() << std::endl;
}

void bake(const pro::proxy<Pizza>& pizza) {
    std::cout << "Baking " << pizza->name() << std::endl;
}

void cut(const pro::proxy<Pizza>& pizza) {
    std::cout << "Cutting " << pizza->name() << std::endl;
}

void box(const pro::proxy<Pizza>& pizza) {
    std::cout << "Boxing " << pizza->name() << std::endl;
}

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
}  // namespace HeadFirstDesignPatterns::Factory::Simple