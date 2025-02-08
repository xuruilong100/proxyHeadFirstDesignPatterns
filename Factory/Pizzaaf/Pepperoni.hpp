#pragma once

#include <string>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
struct Pepperoni : pro::facade_builder::                                      //
                   add_convention<MemToString, const std::string&() const>::  //
                   support_copy<pro::constraint_level::nontrivial>::          //
                   build {};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract