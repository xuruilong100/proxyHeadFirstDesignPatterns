#include "Pizzaaf.hpp"

using namespace HeadFirstDesignPatterns::Factory::Abstract;

int main() {
    auto nyStore = pro::make_proxy<PizzaStore, NYPizzaStore>();
    auto chicagoStore = pro::make_proxy<PizzaStore, ChicagoPizzaStore>();

    auto pizza = orderPizza(nyStore, "cheese");
    std::cout << "Ethan ordered a " << toString(pizza) << std::endl;

    pizza = orderPizza(chicagoStore, "cheese");
    std::cout << "Joel ordered a " << toString(pizza) << std::endl;

    pizza = orderPizza(nyStore, "clam");
    std::cout << "Ethan ordered a " << toString(pizza) << std::endl;

    pizza = orderPizza(chicagoStore, "clam");
    std::cout << "Joel ordered a " << toString(pizza) << std::endl;

    pizza = orderPizza(nyStore, "pepperoni");
    std::cout << "Ethan ordered a " << toString(pizza) << std::endl;

    pizza = orderPizza(chicagoStore, "pepperoni");
    std::cout << "Joel ordered a " << toString(pizza) << std::endl;

    pizza = orderPizza(nyStore, "veggie");
    std::cout << "Ethan ordered a " << toString(pizza) << std::endl;

    pizza = orderPizza(chicagoStore, "veggie");
    std::cout << "Joel ordered a " << toString(pizza) << std::endl;

    return EXIT_SUCCESS;
}

// Output:
/*
--- Making a New York Style Cheese Pizza ---
Preparing New York Style Cheese Pizza
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Ethan ordered a ---- New York Style Cheese Pizza ----
Thin Crust Dough
Marinara Sauce
Reggiano Cheese

--- Making a Chicago Style Cheese Pizza ---
Preparing Chicago Style Cheese Pizza
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Joel ordered a ---- Chicago Style Cheese Pizza ----
Thick Crust Dough
Tomato sauce with plum tomatoes
Shredded Mozzarella

--- Making a New York Style Clam Pizza ---
Preparing New York Style Clam Pizza
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Ethan ordered a ---- New York Style Clam Pizza ----
Thin Crust Dough
Marinara Sauce
Reggiano Cheese
Fresh Clams from Long Island Sound

--- Making a Chicago Style Clam Pizza ---
Preparing Chicago Style Clam Pizza
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Joel ordered a ---- Chicago Style Clam Pizza ----
Thick Crust Dough
Tomato sauce with plum tomatoes
Shredded Mozzarella
Frozen Clams from Chesapeake Bay

--- Making a New York Style Pepperoni Pizza ---
Preparing New York Style Pepperoni Pizza
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Ethan ordered a ---- New York Style Pepperoni Pizza ----
Thin Crust Dough
Marinara Sauce
Reggiano Cheese
Sliced Pepperoni
Garlic, Onion, Mushrooms, Red Pepper,

--- Making a Chicago Style Pepperoni Pizza ---
Preparing Chicago Style Pepperoni Pizza
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Joel ordered a ---- Chicago Style Pepperoni Pizza ----
Thick Crust Dough
Tomato sauce with plum tomatoes
Shredded Mozzarella
Sliced Pepperoni
Black Olives, Spinach, Eggplant,

--- Making a New York Style Veggie Pizza ---
Preparing New York Style Veggie Pizza
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Ethan ordered a ---- New York Style Veggie Pizza ----
Thin Crust Dough
Marinara Sauce
Reggiano Cheese
Garlic, Onion, Mushrooms, Red Pepper,

--- Making a Chicago Style Veggie Pizza ---
Preparing Chicago Style Veggie Pizza
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Joel ordered a ---- Chicago Style Veggie Pizza ----
Thick Crust Dough
Tomato sauce with plum tomatoes
Shredded Mozzarella
Black Olives, Spinach, Eggplant,
*/