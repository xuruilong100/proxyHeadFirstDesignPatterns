#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class BlackOlives {
   private:
    inline static const std::string _name{"Black Olives"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract