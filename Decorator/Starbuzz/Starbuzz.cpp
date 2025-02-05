#include "Starbuzz.hpp"
#include <iostream>

using namespace HeadFirstDesignPatterns::Decorator;

int main() {
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(3);

    auto beverage = pro::make_proxy<Beverage, Espresso>();
    std::cout << beverage->getDescription() << " $" << beverage->cost()
              << std::endl;

    auto beverage2 = pro::make_proxy<Beverage, DarkRoast>();
    beverage2 = pro::make_proxy<Beverage, Mocha>(beverage2);
    beverage2 = pro::make_proxy<Beverage, Mocha>(beverage2);
    beverage2 = pro::make_proxy<Beverage, Whip>(beverage2);
    std::cout << beverage2->getDescription() << " $" << beverage2->cost()
              << std::endl;

    auto beverage3 = pro::make_proxy<Beverage, HouseBlend>();
    beverage3 = pro::make_proxy<Beverage, Soy>(beverage3);
    beverage3 = pro::make_proxy<Beverage, Mocha>(beverage3);
    beverage3 = pro::make_proxy<Beverage, Whip>(beverage3);
    std::cout << beverage3->getDescription() << " $" << beverage3->cost()
              << std::endl;

    return EXIT_SUCCESS;
}

// Output:
/*
Espresso $1.99
Dark Roast Coffee, Mocha, Mocha, Whip $1.49
House Blend Coffee, Soy, Mocha, Whip $1.34
*/