#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Garlic {
   private:
    inline static const std::string _name{"Garlic"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract