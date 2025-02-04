#pragma once

#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "MenuComponent.hpp"

namespace HeadFirstDesignPatterns::Composite::Menus {
class Menu {
   private:
    std::string _name;
    std::string _description;
    std::vector<pro::proxy<MenuComponent>> _menuComponents;

   public:
    Menu(std::string_view name, std::string_view description)
        : _name(name), _description(description) {}
    Menu(const Menu&) = default;
    Menu& operator=(const Menu&) = default;

    void add(pro::proxy<MenuComponent> menuComponent) {
        _menuComponents.push_back(std::move(menuComponent));
    }

    void remove(pro::proxy<MenuComponent> menuComponent) {
        auto idx = std::remove_if(
            _menuComponents.begin(), _menuComponents.end(),
            [&](const auto& c) { return &*menuComponent == &*c; });
        _menuComponents.erase(idx, _menuComponents.end());
    }

    const pro::proxy<MenuComponent>& getChild(int i) const {
        return _menuComponents[i];
    }

    std::string getName() const { return _name; }

    std::string getDescription() const { return _description; }

    double getPrice() const { throw std::runtime_error("No implementation"); }

    bool isVegetarian() const { throw std::runtime_error("No implementation"); }

    void print() const {
        std::cout << std::endl << getName();
        std::cout << ", " << getDescription() << std::endl;
        std::cout << "---------------------" << std::endl;

        for (const auto& menuComponent : _menuComponents) {
            menuComponent->print();
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Composite::Menus