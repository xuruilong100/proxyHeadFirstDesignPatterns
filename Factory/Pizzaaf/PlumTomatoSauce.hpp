#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class PlumTomatoSauce {
   private:
    inline static const std::string _name{"Tomato sauce with plum tomatoes"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract