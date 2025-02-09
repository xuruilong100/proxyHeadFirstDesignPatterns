#pragma once

#include <string>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
struct Fowl : pro::facade_builder::                               //
              add_convention<MemQuack, void() const>::            //
              add_convention<MemSwim, void() const>::             //
              add_convention<MemToString, std::string() const>::  //
              support_copy<pro::constraint_level::nontrivial>::   //
              build {
    enum class type {
        mallard = 0,
        redhead = 1,
        rubber = 2,
        model = 3,
        turkey = 4,
        last = 5
    };
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight