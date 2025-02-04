#pragma once

#include <string>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
struct Command : pro::facade_builder::                                  //
                 add_convention<MemExecute, void()>::                   //
                 add_convention<MemUndo, void()>::                      //
                 add_convention<MemName, const std::string&() const>::  //
                 support_copy<pro::constraint_level::nontrivial>::      //
                 build {};
}  // namespace HeadFirstDesignPatterns::Command::Undo