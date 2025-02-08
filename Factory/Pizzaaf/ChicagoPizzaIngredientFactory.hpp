#pragma once

#include <proxy/proxy.h>
#include "BlackOlives.hpp"
#include "Eggplant.hpp"
#include "FrozenClams.hpp"
#include "MozzarellaCheese.hpp"
#include "PlumTomatoSauce.hpp"
#include "SlicedPepperoni.hpp"
#include "Spinach.hpp"
#include "ThickCrustDough.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ChicagoPizzaIngredientFactory {
   public:
    pro::proxy<Dough> createDough() const {
        return pro::make_proxy<Dough, ThickCrustDough>();
    }

    pro::proxy<Sauce> createSauce() const {
        return pro::make_proxy<Sauce, PlumTomatoSauce>();
    }

    pro::proxy<Cheese> createCheese() const {
        return pro::make_proxy<Cheese, MozzarellaCheese>();
    }

    std::vector<pro::proxy<Veggies>> createVeggies() const {
        std::vector<pro::proxy<Veggies>> value;
        value.push_back(pro::make_proxy<Veggies, BlackOlives>());
        value.push_back(pro::make_proxy<Veggies, Spinach>());
        value.push_back(pro::make_proxy<Veggies, Eggplant>());
        return value;
    }

    pro::proxy<Pepperoni> createPepperoni() const {
        return pro::make_proxy<Pepperoni, SlicedPepperoni>();
    }

    pro::proxy<Clams> createClam() const {
        return pro::make_proxy<Clams, FrozenClams>();
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract