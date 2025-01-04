#pragma once

#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Adapter::Ducks {
struct Turkey : pro::facade_builder::                              //
                add_convention<MemGobble, void() const>::          //
                add_convention<MemFly, void() const>::             //
                support_copy<pro::constraint_level::nontrivial>::  //
                build {};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks