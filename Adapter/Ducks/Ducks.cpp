#include "Ducks.hpp"

using namespace HeadFirstDesignPatterns::Adapter::Ducks;

void testDuck(const pro::proxy<Duck>& duck) {
    duck->quack();
    duck->fly();
}

int main() {
    auto duck = pro::make_proxy<Duck, MallardDuck>();
    auto turkey = pro::make_proxy<Turkey, WildTurkey>();
    auto turkeyAdapter = pro::make_proxy<Duck, TurkeyAdapter>(turkey);

    std::cout << "The Turkey says..." << std::endl;
    turkey->gobble();
    turkey->fly();

    std::cout << std::endl << "The Duck says..." << std::endl;
    testDuck(duck);

    std::cout << std::endl << "The TurkeyAdapter says..." << std::endl;
    testDuck(turkeyAdapter);

    return EXIT_SUCCESS;
}

// Output:
/*
The Turkey says...
Gobble gobble
I'm flying a short distance

The Duck says...
Quack
I'm flying

The TurkeyAdapter says...
Gobble gobble
I'm flying a short distance
I'm flying a short distance
I'm flying a short distance
I'm flying a short distance
I'm flying a short distance
*/