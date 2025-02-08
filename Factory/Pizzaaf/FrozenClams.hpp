#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class FrozenClams {
   private:
    inline static const std::string _name{"Frozen Clams from Chesapeake Bay"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract