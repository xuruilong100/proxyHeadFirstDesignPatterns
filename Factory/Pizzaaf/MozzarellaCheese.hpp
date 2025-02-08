#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class MozzarellaCheese {
   private:
    inline static const std::string _name{"Shredded Mozzarella"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract