#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ParmesanCheese {
   private:
    inline static const std::string _name{"Shredded Parmesan"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract