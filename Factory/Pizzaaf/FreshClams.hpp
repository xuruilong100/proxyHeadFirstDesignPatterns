#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class FreshClams {
   private:
    inline static const std::string _name{"Fresh Clams from Long Island Sound"};

   public:
    const std::string& toString() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract