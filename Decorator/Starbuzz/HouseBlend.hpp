#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Decorator {
class HouseBlend {
   private:
    inline static const std::string _description{"House Blend Coffee"};

   public:
    HouseBlend() = default;

    std::string getDescription() const { return _description; }
    double cost() const { return 0.89; }
};
}  // namespace HeadFirstDesignPatterns::Decorator