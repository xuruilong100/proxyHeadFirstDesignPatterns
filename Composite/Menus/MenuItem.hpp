#pragma once

#include <exception>
#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Composite::Menus {
class MenuItem {
   private:
    std::string _name;
    std::string _description;
    bool _vegetarian;
    double _price;

   public:
    MenuItem(std::string_view name,
             std::string_view description,
             bool vegetarian,
             double price)
        : _name(name),
          _description(description),
          _vegetarian(vegetarian),
          _price(price) {}
    MenuItem(const MenuItem&) = default;
    MenuItem& operator=(const MenuItem&) = default;

    void add(pro::proxy<MenuComponent> menuComponent) {
        throw std::runtime_error("No implementation");
    }

    void remove(pro::proxy<MenuComponent> menuComponent) {
        throw std::runtime_error("No implementation");
    }

    pro::proxy<MenuComponent> getChild(int i) const {
        throw std::runtime_error("No implementation");
    }

    const std::string& getName() const { return _name; }

    const std::string& getDescription() const { return _description; }

    double getPrice() const { return _price; }

    bool isVegetarian() const { return _vegetarian; }

    void print() const {
        std::cout << "  " << getName();
        if (isVegetarian()) {
            std::cout << "(v)";
        }
        std::cout << ", " << getPrice() << std::endl;
        std::cout << "     -- " << getDescription() << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Composite::Menus