#pragma once

#include <stdexcept>
#include "CheesePizza.hpp"
#include "ClamPizza.hpp"
#include "NYPizzaIngredientFactory.hpp"
#include "PepperoniPizza.hpp"
#include "Pizza.hpp"
#include "VeggiePizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class NYPizzaStore {
   public:
    pro::proxy<Pizza> createPizza(std::string_view item) const {
        auto ingredientFactory =
            pro::make_proxy<PizzaIngredientFactory, NYPizzaIngredientFactory>();

        if (item == "cheese") {
            auto pizza = pro::make_proxy<Pizza, CheesePizza>(ingredientFactory);
            pizza->setName("New York Style Cheese Pizza");
            return pizza;
        } else if (item == "veggie") {
            auto pizza = pro::make_proxy<Pizza, VeggiePizza>(ingredientFactory);
            pizza->setName("New York Style Veggie Pizza");
            return pizza;
        } else if (item == "clam") {
            auto pizza = pro::make_proxy<Pizza, ClamPizza>(ingredientFactory);
            pizza->setName("New York Style Clam Pizza");
            return pizza;
        } else if (item == "pepperoni") {
            auto pizza =
                pro::make_proxy<Pizza, PepperoniPizza>(ingredientFactory);
            pizza->setName("New York Style Pepperoni Pizza");
            return pizza;
        } else {
            throw std::invalid_argument("Unknown pizza type");
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract