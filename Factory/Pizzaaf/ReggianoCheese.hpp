#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ReggianoCheese {
   private:
    inline static const std::string _name{"Reggiano Cheese"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract