#pragma once

#include <memory>
#include "GarageDoor.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class GarageDoorUpCommand {
   private:
    std::shared_ptr<GarageDoor> _garageDoor;
    inline static const std::string _name{"GarageDoorUpCommand"};

   public:
    explicit GarageDoorUpCommand(std::shared_ptr<GarageDoor> garageDoor)
        : _garageDoor(std::move(garageDoor)) {}

    void execute() { _garageDoor->up(); }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote