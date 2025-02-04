#pragma once

#include "Command.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class NoCommand {
   private:
    inline static const std::string _name{"NoCommand"};

   public:
    NoCommand() = default;

    void execute() {}
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote