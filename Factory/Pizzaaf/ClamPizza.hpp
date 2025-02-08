#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "PizzaIngredientFactory.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ClamPizza {
   private:
    std::string _name;
    pro::proxy<Dough> _dough;
    pro::proxy<Sauce> _sauce;
    std::vector<pro::proxy<Veggies>> _veggies;
    pro::proxy<Cheese> _cheese;
    pro::proxy<Pepperoni> _pepperoni;
    pro::proxy<Clams> _clam;
    pro::proxy<PizzaIngredientFactory> _ingredientFactory;

   public:
    explicit ClamPizza(pro::proxy<PizzaIngredientFactory> ingredientFactory)
        : _ingredientFactory(std::move(ingredientFactory)) {}

    const pro::proxy<Dough>& dough() const { return _dough; }
    const pro::proxy<Sauce>& sauce() const { return _sauce; }
    const std::vector<pro::proxy<Veggies>>& veggies() const { return _veggies; }
    const pro::proxy<Cheese>& cheese() const { return _cheese; }
    const pro::proxy<Pepperoni>& pepperoni() const { return _pepperoni; }
    const pro::proxy<Clams>& clam() const { return _clam; }

    void prepare() {
        std::cout << "Preparing " << getName() << std::endl;
        _dough = _ingredientFactory->createDough();
        _sauce = _ingredientFactory->createSauce();
        _cheese = _ingredientFactory->createCheese();
        _clam = _ingredientFactory->createClam();
    }

    void bake() const {
        std::cout << "Bake for 25 minutes at 350" << std::endl;
    }

    void cut() const {
        std::cout << "Cutting the pizza into diagonal slices" << std::endl;
    }

    void box() const {
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    }

    void setName(std::string_view name) { _name = name; }

    const std::string& getName() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract