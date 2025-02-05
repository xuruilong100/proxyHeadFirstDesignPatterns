#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Decorator {
class Decaf {
   private:
    inline static const std::string _description{"Decaf Coffee"};

   public:
    Decaf() = default;

    std::string getDescription() const { return _description; }
    double cost() const { return 1.05; }
};
}  // namespace HeadFirstDesignPatterns::Decorator