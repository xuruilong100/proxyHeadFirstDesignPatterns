#pragma once

#include <memory>
#include "Command.hpp"

namespace HeadFirstDesignPatterns::Command::SimpleRemote {
class SimpleRemoteControl {
   private:
    pro::proxy<Command> _slot{nullptr};

   public:
    SimpleRemoteControl() = default;

    void setCommand(pro::proxy<Command> command) { _slot = std::move(command); }
    void buttonWasPressed() const { _slot->execute(); }
};
}  // namespace HeadFirstDesignPatterns::Command::SimpleRemote