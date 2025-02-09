#pragma once

#include <iostream>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
struct Turkey : pro::facade_builder::                               //
                add_convention<MemGobble, void() const>::           //
                add_convention<MemWalk, void() const>::             //
                add_convention<MemToString, std::string() const>::  //
                support_copy<pro::constraint_level::nontrivial>::   //
                build {};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight