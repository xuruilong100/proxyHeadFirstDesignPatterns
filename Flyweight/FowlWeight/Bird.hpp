#pragma once

#include <memory>
#include <sstream>
#include "Fowl.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class Bird {
   private:
    pro::proxy<Fowl> _fowl;
    int _number;
    double _weight;

   public:
    Bird(pro::proxy<Fowl> fowl, int number = 0, double weight = 0.0)
        : _fowl(std::move(fowl)), _number(number), _weight(weight) {}

    void quack() const { _fowl->quack(); }

    void swim() const { _fowl->swim(); }

    double getWeight() const { return _weight; }

    double getNumber() const { return _number; }

    std::string toString() const {
        std::stringstream value;
        value << "Bird #" << _number + 1 << ", ";
        value << "weighs " << _weight << " pounds, ";
        value << "is a " << _fowl->toString();
        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight