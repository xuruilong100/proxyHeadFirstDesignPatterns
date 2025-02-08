#include "Pizzafm.hpp"

using namespace HeadFirstDesignPatterns::Factory::Method;

int main(int argc, char* argv[]) {
    auto nyStore = pro::make_proxy<PizzaStore, NYPizzaStore>();
    auto chicagoStore = pro::make_proxy<PizzaStore, ChicagoPizzaStore>();

    auto pizza = orderPizza(nyStore, "cheese");
    std::cout << "Ethan ordered a " << pizza->name() << std::endl;

    pizza = orderPizza(chicagoStore, "cheese");
    std::cout << "Joel ordered a " << pizza->name() << std::endl;

    pizza = orderPizza(nyStore, "clam");
    std::cout << "Ethan ordered a " << pizza->name() << std::endl;

    pizza = orderPizza(chicagoStore, "clam");
    std::cout << "Joel ordered a " << pizza->name() << std::endl;

    pizza = orderPizza(nyStore, "pepperoni");
    std::cout << "Ethan ordered a " << pizza->name() << std::endl;

    pizza = orderPizza(chicagoStore, "pepperoni");
    std::cout << "Joel ordered a " << pizza->name() << std::endl;

    pizza = orderPizza(nyStore, "veggie");
    std::cout << "Ethan ordered a " << pizza->name() << std::endl;

    pizza = orderPizza(chicagoStore, "veggie");
    std::cout << "Joel ordered a " << pizza->name() << std::endl;

    return 0;
}

// Output:
/*
--- Making a NY Style Sauce and Cheese Pizza ---
Preparing NY Style Sauce and Cheese Pizza
Tossing dough...
Adding sauce...
Adding toppings:
   Grated Reggiano Cheese
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Ethan ordered a NY Style Sauce and Cheese Pizza
--- Making a Chicago Style Deep Dish Cheese Pizza ---
Preparing Chicago Style Deep Dish Cheese Pizza
Tossing dough...
Adding sauce...
Adding toppings:
   Shredded Mozzarella Cheese
Bake for 25 minutes at 350
Cutting the pizza into square slices
Place pizza in official PizzaStore box
Joel ordered a Chicago Style Deep Dish Cheese Pizza
--- Making a NY Style Clam Pizza ---
Preparing NY Style Clam Pizza
Tossing dough...
Adding sauce...
Adding toppings:
   Grated Reggiano Cheese
   Fresh Clams from Long Island Sound
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Ethan ordered a NY Style Clam Pizza
--- Making a Chicago Style Clam Pizza ---
Preparing Chicago Style Clam Pizza
Tossing dough...
Adding sauce...
Adding toppings:
   Shredded Mozzarella Cheese
   Frozen Clams from Chesapeake Bay
Bake for 25 minutes at 350
Cutting the pizza into square slices
Place pizza in official PizzaStore box
Joel ordered a Chicago Style Clam Pizza
--- Making a NY Style Pepperoni Pizza ---
Preparing NY Style Pepperoni Pizza
Tossing dough...
Adding sauce...
Adding toppings:
   Grated Reggiano Cheese
   Sliced Pepperoni
   Garlic
   Onion
   Mushrooms
   Red Pepper
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Ethan ordered a NY Style Pepperoni Pizza
--- Making a Chicago Style Pepperoni Pizza ---
Preparing Chicago Style Pepperoni Pizza
Tossing dough...
Adding sauce...
Adding toppings:
   Shredded Mozzarella Cheese
   Black Olives
   Spinach
   Eggplant
   Sliced Pepperoni
Bake for 25 minutes at 350
Cutting the pizza into square slices
Place pizza in official PizzaStore box
Joel ordered a Chicago Style Pepperoni Pizza
--- Making a NY Style Veggie Pizza ---
Preparing NY Style Veggie Pizza
Tossing dough...
Adding sauce...
Adding toppings:
   Grated Reggiano Cheese
   Garlic
   Onion
   Mushrooms
   Red Pepper
Bake for 25 minutes at 350
Cutting the pizza into diagonal slices
Place pizza in official PizzaStore box
Ethan ordered a NY Style Veggie Pizza
--- Making a Chicago Deep Dish Veggie Pizza ---
Preparing Chicago Deep Dish Veggie Pizza
Tossing dough...
Adding sauce...
Adding toppings:
   Shredded Mozzarella Cheese
   Black Olives
   Spinach
   Eggplant
Bake for 25 minutes at 350
Cutting the pizza into square slices
Place pizza in official PizzaStore box
Joel ordered a Chicago Deep Dish Veggie Pizza
*/