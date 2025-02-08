#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class SlicedPepperoni {
   private:
    inline static const std::string _name{"Sliced Pepperoni"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract