#pragma once

#include <random>
#include "Duck.hpp"

namespace HeadFirstDesignPatterns::Adapter::Ducks {
class DuckAdapter {
   private:
    pro::proxy<Duck> _duck;
    int _random;

   public:
    explicit DuckAdapter(pro::proxy<Duck> duck) : _duck(std::move(duck)) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution dis(1, 5);
        _random = dis(gen);
    }

    void fly() const {
        for (int i = 0; i < _random; ++i) {
            _duck->fly();
        }
    }

    void gobble() const { _duck->quack(); }
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks