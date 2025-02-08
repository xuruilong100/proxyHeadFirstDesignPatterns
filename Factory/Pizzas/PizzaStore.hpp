#pragma once

#include <memory>
#include "SimplePizzaFactory.hpp"

namespace HeadFirstDesignPatterns::Factory::Simple {
class PizzaStore {
   private:
    std::shared_ptr<SimplePizzaFactory> _factory;

   public:
    explicit PizzaStore(std::shared_ptr<SimplePizzaFactory> factory)
        : _factory(std::move(factory)) {}

    pro::proxy<Pizza> orderPizza(std::string_view type) {
        auto pizza = _factory->createPizza(type);
        prepare(pizza);
        bake(pizza);
        cut(pizza);
        box(pizza);
        return pizza;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple