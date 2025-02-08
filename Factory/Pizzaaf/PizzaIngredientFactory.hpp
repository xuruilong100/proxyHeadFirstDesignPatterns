#pragma once

#include <vector>
#include "Cheese.hpp"
#include "Clams.hpp"
#include "Dough.hpp"
#include "Pepperoni.hpp"
#include "Sauce.hpp"
#include "Traits.hpp"
#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
struct PizzaIngredientFactory
    : pro::facade_builder::                                          //
      add_convention<MemCreateDough, pro::proxy<Dough>() const>::    //
      add_convention<MemCreateSauce, pro::proxy<Sauce>() const>::    //
      add_convention<MemCreateCheese, pro::proxy<Cheese>() const>::  //
      add_convention<MemCreateVeggies,
                     std::vector<pro::proxy<Veggies>>() const>::           //
      add_convention<MemCreatePepperoni, pro::proxy<Pepperoni>() const>::  //
      add_convention<MemCreateClam, pro::proxy<Clams>() const>::           //
      support_copy<pro::constraint_level::nontrivial>::                    //
      build {};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract