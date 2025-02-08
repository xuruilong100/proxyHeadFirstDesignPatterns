#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ThickCrustDough {
   private:
    inline static const std::string _name{"Thick Crust Dough"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract