#pragma once

#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Command::SimpleRemote {
struct Command : pro::facade_builder::                              //
                 add_convention<MemExecute, void() const>::         //
                 support_copy<pro::constraint_level::nontrivial>::  //
                 build {};
}  // namespace HeadFirstDesignPatterns::Command::SimpleRemote