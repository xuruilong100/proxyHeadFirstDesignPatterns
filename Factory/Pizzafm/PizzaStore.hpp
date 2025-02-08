#pragma once

#include "Pizza.hpp"
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
struct PizzaStore
    : pro::facade_builder::  //
      add_convention<MemCreatePizza,
                     pro::proxy<Pizza>(std::string_view) const>::  //
      support_copy<pro::constraint_level::nontrivial>::            //
      build {};

inline pro::proxy<Pizza> orderPizza(const pro::proxy<PizzaStore>& store,
                                    std::string_view type) {
    auto pizza = store->createPizza(type);
    std::cout << "--- Making a " << pizza->name() << " ---" << std::endl;
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
}
}  // namespace HeadFirstDesignPatterns::Factory::Method