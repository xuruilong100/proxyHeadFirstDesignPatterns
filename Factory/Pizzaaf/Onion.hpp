#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Onion {
   private:
    inline static const std::string _name{"Onion"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract