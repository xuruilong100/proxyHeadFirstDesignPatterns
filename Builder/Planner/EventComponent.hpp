#pragma once

#include <memory>
#include <string>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Builder {
struct EventComponent
    : pro::facade_builder::  //
      add_convention<MemAdd,
                     pro::proxy<EventComponent>(
                         pro::proxy<EventComponent>)>::                      //
      add_convention<MemRemove, void(pro::proxy<EventComponent>)>::          //
      add_convention<MemGetChild, const pro::proxy<EventComponent>&(int)>::  //
      add_convention<MemGetName, const std::string&() const>::               //
      add_convention<MemGetDescription, const std::string&() const>::        //
      add_convention<MemGetPrice, double() const>::                          //
      add_convention<MemPrint, void() const>::                               //
      support_copy<pro::constraint_level::nontrivial>::                      //
      build {};
}  // namespace HeadFirstDesignPatterns::Builder