#pragma once

#include <stdexcept>
#include "NYStyleCheesePizza.hpp"
#include "NYStyleClamPizza.hpp"
#include "NYStylePepperoniPizza.hpp"
#include "NYStyleVeggiePizza.hpp"
#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class NYPizzaStore {
   public:
    NYPizzaStore() = default;

    pro::proxy<Pizza> createPizza(std::string_view type) const {
        if (type == "cheese") {
            return pro::make_proxy<Pizza, NYStyleCheesePizza>();
        } else if (type == "veggie") {
            return pro::make_proxy<Pizza, NYStyleVeggiePizza>();
        } else if (type == "clam") {
            return pro::make_proxy<Pizza, NYStyleClamPizza>();
        } else if (type == "pepperoni") {
            return pro::make_proxy<Pizza, NYStylePepperoniPizza>();
        } else {
            throw std::invalid_argument("Invalid pizza type");
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method