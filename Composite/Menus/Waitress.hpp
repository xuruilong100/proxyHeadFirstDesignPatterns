#pragma once

#include "MenuComponent.hpp"

namespace HeadFirstDesignPatterns::Composite::Menus {
class Waitress {
   private:
    pro::proxy<MenuComponent> _allMenus;

   public:
    explicit Waitress(pro::proxy<MenuComponent> allMenus)
        : _allMenus(std::move(allMenus)) {}

    void printMenu() const { _allMenus->print(); }
};
}  // namespace HeadFirstDesignPatterns::Composite::Menus