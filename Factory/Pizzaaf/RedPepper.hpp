#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class RedPepper {
   private:
    inline static const std::string _name{"Red Pepper"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract