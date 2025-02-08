#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Mushroom {
   private:
    inline static const std::string _name{"Mushrooms"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract