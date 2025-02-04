#pragma once

#include <memory>
#include "GarageDoor.hpp"

namespace HeadFirstDesignPatterns::Command::SimpleRemote {
class GarageDoorOpenCommand {
   private:
    std::shared_ptr<GarageDoor> _garageDoor;

   public:
    explicit GarageDoorOpenCommand(std::shared_ptr<GarageDoor> garageDoor)
        : _garageDoor(std::move(garageDoor)) {}

    void execute() const { _garageDoor->up(); }
};
}  // namespace HeadFirstDesignPatterns::Command::SimpleRemote