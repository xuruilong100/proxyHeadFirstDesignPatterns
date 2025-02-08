#pragma once

#include <list>
#include <string>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
struct Pizza
    : pro::facade_builder::                                                 //
      add_convention<MemName, const std::string&() const>::                 //
      add_convention<MemDough, const std::string&() const>::                //
      add_convention<MemSauce, const std::string&() const>::                //
      add_convention<MemToppings, const std::list<std::string>&() const>::  //
      add_convention<MemPrepare, void() const>::                            //
      add_convention<MemBake, void() const>::                               //
      add_convention<MemCut, void() const>::                                //
      add_convention<MemBox, void() const>::                                //
      support_copy<pro::constraint_level::nontrivial>::                     //
      build {};

std::string toString(const pro::proxy<Pizza>& pizza);
}  // namespace HeadFirstDesignPatterns::Factory::Method