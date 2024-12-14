#pragma once

#include "Turkey.hpp"

namespace HeadFirstDesignPatterns::Adapter::Ducks {
class TurkeyAdapter {
   private:
    pro::proxy<Turkey> _turkey;

   public:
    explicit TurkeyAdapter(pro::proxy<Turkey> turkey)
        : _turkey(std::move(turkey)) {}

    void fly() const {
        for (int i = 0; i < 5; i++) {
            _turkey->fly();
        }
    }

    void quack() const { _turkey->gobble(); }
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks