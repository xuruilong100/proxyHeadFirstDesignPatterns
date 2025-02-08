#pragma once

#include <iostream>
#include <memory>
#include "Pizza.hpp"
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
struct PizzaStore
    : pro::facade_builder::  //
      add_convention<MemCreatePizza,
                     pro::proxy<Pizza>(std::string_view type) const>::  //
      support_copy<pro::constraint_level::nontrivial>::                 //
      build {};

inline pro::proxy<Pizza> orderPizza(const pro::proxy<PizzaStore>& store,
                                    std::string_view type) {
    auto pizza = store->createPizza(type);
    std::cout << "--- Making a " << pizza->getName() << " ---" << std::endl;
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
}
}  // namespace HeadFirstDesignPatterns::Factory::Abstract