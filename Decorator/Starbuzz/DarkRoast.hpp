#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Decorator {
class DarkRoast {
   private:
    inline static const std::string _description{"Dark Roast Coffee"};

   public:
    DarkRoast() = default;

    std::string getDescription() const { return _description; }
    double cost() const { return 0.99; }
};
}  // namespace HeadFirstDesignPatterns::Decorator