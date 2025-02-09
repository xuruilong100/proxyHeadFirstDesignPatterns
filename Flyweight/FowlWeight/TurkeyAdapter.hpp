#pragma once

#include "Turkey.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class TurkeyAdapter {
   private:
    pro::proxy<Turkey> _turkey;

   public:
    explicit TurkeyAdapter(pro::proxy<Turkey> turkey)
        : _turkey(std::move(turkey)) {}

    void quack() const { _turkey->gobble(); }

    void swim() const { _turkey->walk(); }

    std::string toString() const { return _turkey->toString(); }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight