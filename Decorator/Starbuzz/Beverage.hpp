#pragma once

#include <string>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Decorator {
struct Beverage : pro::facade_builder::                                     //
                  add_convention<MemGetDescription, std::string() const>::  //
                  add_convention<MemCost, double() const>::                 //
                  support_copy<pro::constraint_level::nontrivial>::         //
                  build {};
}  // namespace HeadFirstDesignPatterns::Decorator