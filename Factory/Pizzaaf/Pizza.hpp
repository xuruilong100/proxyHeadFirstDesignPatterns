#pragma once

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "Cheese.hpp"
#include "Clams.hpp"
#include "Dough.hpp"
#include "Pepperoni.hpp"
#include "Sauce.hpp"
#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
struct Pizza
    : pro::facade_builder::                                         //
      add_convention<MemDough, const pro::proxy<Dough>&() const>::  //
      add_convention<MemSauce, const pro::proxy<Sauce>&() const>::  //
      add_convention<MemVeggies,
                     const std::vector<pro::proxy<Veggies>>&() const>::     //
      add_convention<MemCheese, const pro::proxy<Cheese>&() const>::        //
      add_convention<MemPepperoni, const pro::proxy<Pepperoni>&() const>::  //
      add_convention<MemClam, const pro::proxy<Clams>&() const>::           //
      add_convention<MemPrepare, void()>::                                  //
      add_convention<MemBake, void() const>::                               //
      add_convention<MemCut, void() const>::                                //
      add_convention<MemBox, void() const>::                                //
      add_convention<MemSetName, void(std::string_view)>::                  //
      add_convention<MemGetName, const std::string&() const>::              //
      support_copy<pro::constraint_level::nontrivial>::                     //
      build {};

inline std::string toString(const pro ::proxy<Pizza>& pizza) {
    std::stringstream value;
    value << "---- " << pizza->getName() << " ----" << std::endl;

    if (pizza->dough().has_value()) {
        value << pizza->dough()->toString();
        value << std::endl;
    }
    if (pizza->sauce().has_value()) {
        value << pizza->sauce()->toString();
        value << std::endl;
    }
    if (pizza->cheese().has_value()) {
        value << pizza->cheese()->toString();
        value << std::endl;
    }
    if (pizza->clam().has_value()) {
        value << pizza->clam()->toString();
        value << std::endl;
    }
    if (pizza->pepperoni().has_value()) {
        value << pizza->pepperoni()->toString();
        value << std::endl;
    }
    if (pizza->veggies().empty() == false) {
        for (const auto& v : pizza->veggies()) {
            value << v->toString() << ", ";
        }
        value << std::endl;
    }

    return value.str();
}
}  // namespace HeadFirstDesignPatterns::Factory::Abstract