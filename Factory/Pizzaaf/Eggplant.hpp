#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Eggplant {
   private:
    inline static const std::string _name{"Eggplant"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract