#pragma once

#include <iostream>
#include <list>
#include <string>

namespace HeadFirstDesignPatterns::Factory::Method {
class NYStyleClamPizza {
   private:
    inline static const std::string _name{"NY Style Clam Pizza"};
    inline static const std::string _dough{"Thin Crust Dough"};
    inline static const std::string _sauce{"Marinara Sauce"};
    inline static const std::list<std::string> _toppings{
        "Grated Reggiano Cheese", "Fresh Clams from Long Island Sound"};

   public:
    NYStyleClamPizza() = default;

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
        std::cout << "Cutting the pizza into diagonal slices" << std::endl;
    }

    void box() const {
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method