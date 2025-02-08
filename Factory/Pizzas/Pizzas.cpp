#include "Pizzas.hpp"
#include <iostream>

using namespace HeadFirstDesignPatterns::Factory::Simple;

int main() {
    auto factory = std::make_shared<SimplePizzaFactory>();
    PizzaStore store(factory);

    auto pizza = store.orderPizza("cheese");
    std::cout << "We ordered a " << pizza->name() << std::endl;

    pizza = store.orderPizza("veggie");
    std::cout << "We ordered a " << pizza->name() << std::endl;

    return EXIT_SUCCESS;
}

// Output:
/*
Preparing Cheese Pizza
Baking Cheese Pizza
Cutting Cheese Pizza
Boxing Cheese Pizza
We ordered a Cheese Pizza
Preparing Veggie Pizza
Baking Veggie Pizza
Cutting Veggie Pizza
Boxing Veggie Pizza
We ordered a Veggie Pizza
*/