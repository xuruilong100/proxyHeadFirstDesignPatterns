#pragma once

#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Adapter::Ducks {
struct Duck : pro::facade_builder::                              //
              add_convention<MemFly, void() const>::             //
              add_convention<MemQuack, void() const>::           //
              support_copy<pro::constraint_level::nontrivial>::  //
              build {};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks