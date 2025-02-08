#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class MarinaraSauce {
   private:
    inline static const std::string _name{"Marinara Sauce"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract