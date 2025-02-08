#pragma once

#include <stdexcept>
#include "ChicagoStyleCheesePizza.hpp"
#include "ChicagoStyleClamPizza.hpp"
#include "ChicagoStylePepperoniPizza.hpp"
#include "ChicagoStyleVeggiePizza.hpp"
#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class ChicagoPizzaStore {
   public:
    ChicagoPizzaStore() = default;

    pro::proxy<Pizza> createPizza(std::string_view type) const {
        if (type == "cheese") {
            return pro::make_proxy<Pizza, ChicagoStyleCheesePizza>();
        } else if (type == "veggie") {
            return pro::make_proxy<Pizza, ChicagoStyleVeggiePizza>();
        } else if (type == "clam") {
            return pro::make_proxy<Pizza, ChicagoStyleClamPizza>();
        } else if (type == "pepperoni") {
            return pro::make_proxy<Pizza, ChicagoStylePepperoniPizza>();
        } else {
            throw std::invalid_argument("Invalid pizza type");
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method