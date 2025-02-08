#pragma once

#include <list>
#include <string>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Factory::Simple {
struct Pizza
    : pro::facade_builder::                                                 //
      add_convention<MemName, const std::string&() const>::                 //
      add_convention<MemDough, const std::string&() const>::                //
      add_convention<MemSauce, const std::string&() const>::                //
      add_convention<MemToppings, const std::list<std::string>&() const>::  //
      support_copy<pro::constraint_level::nontrivial>::                     //
      build {};

void prepare(const pro::proxy<Pizza>& pizza);
void bake(const pro::proxy<Pizza>& pizza);
void cut(const pro::proxy<Pizza>& pizza);
void box(const pro::proxy<Pizza>& pizza);
std::string toString(const pro::proxy<Pizza>& pizza);
}  // namespace HeadFirstDesignPatterns::Factory::Simple