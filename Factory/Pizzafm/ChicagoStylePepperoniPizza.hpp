#pragma once

#include <iostream>
#include <list>
#include <string>

namespace HeadFirstDesignPatterns::Factory::Method {
class ChicagoStylePepperoniPizza {
   private:
    inline static const std::string _name{"Chicago Style Pepperoni Pizza"};
    inline static const std::string _dough{"Extra Thick Crust Dough"};
    inline static const std::string _sauce{"Plum Tomato Sauce"};
    inline static const std::list<std::string> _toppings{
        "Shredded Mozzarella Cheese", "Black Olives", "Spinach", "Eggplant",
        "Sliced Pepperoni"};

   public:
    ChicagoStylePepperoniPizza() = default;

    const std::string& name() const { return _name; }
    const std::string& dough() const { return _dough; }
    const std::string& sauce() const { return _sauce; }
    const std::list<std::string>& toppings() const { return _toppings; }

    void prepare() const {
        std::cout << "Preparing " << _name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings: " << std::endl;
        for (const auto& top : _toppings) {
            std::cout << "   " << top << std::endl;
        }
    }

    void bake() const {
        std::cout << "Bake for 25 minutes at 350" << std::endl;
    }

    void cut() const {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }

    void box() const {
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method