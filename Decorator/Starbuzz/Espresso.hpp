#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Decorator {
class Espresso {
   private:
    inline static const std::string _description{"Espresso"};

   public:
    Espresso() = default;

    std::string getDescription() const { return _description; }
    double cost() const { return 1.99; }
};
}  // namespace HeadFirstDesignPatterns::Decorator