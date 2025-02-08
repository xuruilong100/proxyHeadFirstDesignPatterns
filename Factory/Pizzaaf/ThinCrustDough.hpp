#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ThinCrustDough {
   private:
    inline static const std::string _name{"Thin Crust Dough"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract