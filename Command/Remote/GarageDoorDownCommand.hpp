#pragma once

#include <memory>
#include "GarageDoor.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class GarageDoorDownCommand {
   private:
    std::shared_ptr<GarageDoor> _garageDoor;
    inline static const std::string _name{"GarageDoorDownCommand"};

   public:
    explicit GarageDoorDownCommand(std::shared_ptr<GarageDoor> garageDoor)
        : _garageDoor(std::move(garageDoor)) {}

    void execute() { _garageDoor->down(); }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote