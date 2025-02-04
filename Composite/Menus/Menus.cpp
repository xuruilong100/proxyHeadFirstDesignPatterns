#include "Menus.hpp"

using namespace HeadFirstDesignPatterns::Composite::Menus;

int main() {
    auto pancakeHouseMenu =
        std::make_shared<Menu>("PANCAKE HOUSE MENU", "Breakfast");
    auto dinerMenu = std::make_shared<Menu>("DINER MENU", "Lunch");
    auto cafeMenu = std::make_shared<Menu>("CAFE MENU", "Dinner");
    auto dessertMenu =
        std::make_shared<Menu>("DESSERT MENU", "Dessert of course!");
    auto coffeeMenu = std::make_shared<Menu>(
        "COFFEE MENU", "Stuff to go with your afternoon coffee");

    auto allMenus = std::make_shared<Menu>("ALL MENUS", "All menus combined");

    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    allMenus->add(cafeMenu);

    pancakeHouseMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "K&B's Pancake Breakfast", "Pancakes with scrambled eggs, and toast",
        true, 2.99));
    pancakeHouseMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Regular Pancake Breakfast", "Pancakes with fried eggs, sausage", false,
        2.99));
    pancakeHouseMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Blueberry Pancakes",
        "Pancakes made with fresh blueberries, and blueberry syrup", true,
        3.49));
    pancakeHouseMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Waffles", "Waffles, with your choice of blueberries or strawberries",
        true, 3.59));
    dinerMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat",
        true, 2.99));
    dinerMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99));
    dinerMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Soup of the day",
        "A bowl of the soup of the day, with a side of potato salad", false,
        3.29));
    dinerMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Hotdog",
        "A hot dog, with saurkraut, relish, onions, topped with cheese", false,
        3.05));
    dinerMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Steamed Veggies and Brown Rice", "Steamed vegetables over brown rice",
        true, 3.99));
    dinerMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Pasta",
        "Spaghetti with Marinara Sauce, and a slice of sourdough bread", true,
        3.89));

    dinerMenu->add(dessertMenu);

    dessertMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Apple Pie",
        "Apple pie with a flakey crust, topped with vanilla icecream", true,
        1.59));
    dessertMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Cheesecake",
        "Creamy New York cheesecake, with a chocolate graham crust", true,
        1.99));
    dessertMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Sorbet", "A scoop of raspberry and a scoop of lime", true, 1.89));
    cafeMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Veggie Burger and Air Fries",
        "Veggie burger on a whole wheat bun, lettuce, tomato, and fries", true,
        3.99));
    cafeMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Soup of the day", "A cup of the soup of the day, with a side salad",
        false, 3.69));
    cafeMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Burrito", "A large burrito, with whole pinto beans, salsa, guacamole",
        true, 4.29));

    cafeMenu->add(coffeeMenu);

    coffeeMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Coffee Cake", "Crumbly cake topped with cinnamon and walnuts", true,
        1.59));
    coffeeMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Bagel", "Flavors include sesame, poppyseed, cinnamon raisin, pumpkin",
        false, 0.69));
    coffeeMenu->add(pro::make_proxy<MenuComponent, MenuItem>(
        "Biscotti", "Three almond or hazelnut biscotti cookies", true, 0.89));

    auto waitress = std::make_shared<Waitress>(allMenus);
    waitress->printMenu();

    return EXIT_SUCCESS;
}

// Output:
/*
ALL MENUS, All menus combined
---------------------

PANCAKE HOUSE MENU, Breakfast
---------------------
  K&B's Pancake Breakfast(v), 2.99
     -- Pancakes with scrambled eggs, and toast
  Regular Pancake Breakfast, 2.99
     -- Pancakes with fried eggs, sausage
  Blueberry Pancakes(v), 3.49
     -- Pancakes made with fresh blueberries, and blueberry syrup
  Waffles(v), 3.59
     -- Waffles, with your choice of blueberries or strawberries

DINER MENU, Lunch
---------------------
  Vegetarian BLT(v), 2.99
     -- (Fakin') Bacon with lettuce & tomato on whole wheat
  BLT, 2.99
     -- Bacon with lettuce & tomato on whole wheat
  Soup of the day, 3.29
     -- A bowl of the soup of the day, with a side of potato salad
  Hotdog, 3.05
     -- A hot dog, with saurkraut, relish, onions, topped with cheese
  Steamed Veggies and Brown Rice(v), 3.99
     -- Steamed vegetables over brown rice
  Pasta(v), 3.89
     -- Spaghetti with Marinara Sauce, and a slice of sourdough bread

DESSERT MENU, Dessert of course!
---------------------
  Apple Pie(v), 1.59
     -- Apple pie with a flakey crust, topped with vanilla icecream
  Cheesecake(v), 1.99
     -- Creamy New York cheesecake, with a chocolate graham crust
  Sorbet(v), 1.89
     -- A scoop of raspberry and a scoop of lime

CAFE MENU, Dinner
---------------------
  Veggie Burger and Air Fries(v), 3.99
     -- Veggie burger on a whole wheat bun, lettuce, tomato, and fries
  Soup of the day, 3.69
     -- A cup of the soup of the day, with a side salad
  Burrito(v), 4.29
     -- A large burrito, with whole pinto beans, salsa, guacamole

COFFEE MENU, Stuff to go with your afternoon coffee
---------------------
  Coffee Cake(v), 1.59
     -- Crumbly cake topped with cinnamon and walnuts
  Bagel, 0.69
     -- Flavors include sesame, poppyseed, cinnamon raisin, pumpkin
  Biscotti(v), 0.89
     -- Three almond or hazelnut biscotti cookies
*/