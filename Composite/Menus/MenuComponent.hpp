#pragma once

#include <memory>
#include <string>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Composite::Menus {
struct MenuComponent
    : pro::facade_builder::                                                //
      add_convention<MemAdd, void(pro::proxy<MenuComponent>)>::            //
      add_convention<MemRemove, void(pro::proxy<MenuComponent>)>::         //
      add_convention<MemGetChild, pro::proxy<MenuComponent>(int) const>::  //
      add_convention<MemGetName, std::string() const>::                    //
      add_convention<MemGetDescription, std::string() const>::             //
      add_convention<MemGetPrice, double() const>::                        //
      add_convention<MemIsVegetarian, bool() const>::                      //
      add_convention<MemPrint, void() const>::                             //
      support_copy<pro::constraint_level::nontrivial>::                    //
      build {};
}  // namespace HeadFirstDesignPatterns::Composite::Menus