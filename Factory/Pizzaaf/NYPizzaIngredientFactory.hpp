#pragma once

#include <proxy/proxy.h>
#include "FreshClams.hpp"
#include "Garlic.hpp"
#include "MarinaraSauce.hpp"
#include "Mushroom.hpp"
#include "Onion.hpp"
#include "RedPepper.hpp"
#include "ReggianoCheese.hpp"
#include "SlicedPepperoni.hpp"
#include "ThinCrustDough.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class NYPizzaIngredientFactory {
   public:
    pro::proxy<Dough> createDough() const {
        return pro::make_proxy<Dough, ThinCrustDough>();
    }

    pro::proxy<Sauce> createSauce() const {
        return pro::make_proxy<Sauce, MarinaraSauce>();
    }

    pro::proxy<Cheese> createCheese() const {
        return pro::make_proxy<Cheese, ReggianoCheese>();
    }

    std::vector<pro::proxy<Veggies>> createVeggies() const {
        std::vector<pro::proxy<Veggies>> veggies;
        veggies.push_back(pro::make_proxy<Veggies, Garlic>());
        veggies.push_back(pro::make_proxy<Veggies, Onion>());
        veggies.push_back(pro::make_proxy<Veggies, Mushroom>());
        veggies.push_back(pro::make_proxy<Veggies, RedPepper>());
        return veggies;
    }

    pro::proxy<Pepperoni> createPepperoni() const {
        return pro::make_proxy<Pepperoni, SlicedPepperoni>();
    }

    pro::proxy<Clams> createClam() const {
        return pro::make_proxy<Clams, FreshClams>();
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract