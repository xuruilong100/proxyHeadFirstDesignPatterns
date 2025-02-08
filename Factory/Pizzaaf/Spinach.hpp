#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Spinach {
   private:
    inline static const std::string _name{"Spinach"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract