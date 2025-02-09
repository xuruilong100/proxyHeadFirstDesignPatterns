#pragma once

#include <map>
#include <memory>
#include "Bird.hpp"
#include "Fowl.hpp"
#include "MallardDuck.hpp"
#include "ModelDuck.hpp"
#include "RedHeadDuck.hpp"
#include "RubberDuck.hpp"
#include "TurkeyAdapter.hpp"
#include "WildTurkey.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
// As also mentioned by GoF [pp 205] we could omit the operation getBird() and
// let clients instantiate unshared objects directly; however, if we decided to
// make these objects sharable later, we'll have to change client code that
// creates them.

class FowlFactory {
   private:
    inline static const std::map<Fowl::type, pro::proxy<Fowl>> map{
        {Fowl::type::mallard, pro::make_proxy<Fowl, MallardDuck>()},
        {Fowl::type::redhead, pro::make_proxy<Fowl, RedheadDuck>()},
        {Fowl::type::rubber, pro::make_proxy<Fowl, RubberDuck>()},
        {Fowl::type::model, pro::make_proxy<Fowl, ModelDuck>()},
        {Fowl::type::turkey, pro::make_proxy<Fowl, TurkeyAdapter>(
                                 pro::make_proxy<Turkey, WildTurkey>())},
    };

   public:
    FowlFactory() = default;
    FowlFactory(const FowlFactory&) = delete;
    FowlFactory& operator=(const FowlFactory&) = delete;

    pro::proxy<Fowl> getFowl(Fowl::type type) const {
        auto iterator = map.find(type);
        if (iterator == map.end()) {
            throw std::invalid_argument("Invalid fowl type");
        } else {
            return iterator->second;
        }
    }

    std::shared_ptr<Bird> getBird(Fowl::type type,
                                  int number,
                                  double weight) const {
        auto bird = std::make_shared<Bird>(getFowl(type), number, weight);
        return bird;
    }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight