#pragma once

#include <stdexcept>
#include "CheesePizza.hpp"
#include "ClamPizza.hpp"
#include "PepperoniPizza.hpp"
#include "Pizza.hpp"
#include "VeggiePizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Simple {
class SimplePizzaFactory {
   public:
    pro::proxy<Pizza> createPizza(std::string_view type) const {
        if (type == "cheese") {
            return pro::make_proxy<Pizza, CheesePizza>();
        } else if (type == "pepperoni") {
            return pro::make_proxy<Pizza, PepperoniPizza>();
        } else if (type == "clam") {
            return pro::make_proxy<Pizza, ClamPizza>();
        } else if (type == "veggie") {
            return pro::make_proxy<Pizza, VeggiePizza>();
        } else {
            throw std::invalid_argument("Invalid pizza type");
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple