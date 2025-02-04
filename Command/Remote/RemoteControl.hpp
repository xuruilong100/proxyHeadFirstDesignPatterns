#pragma once

#include <array>
#include <iostream>
#include <memory>
#include <sstream>
#include <typeinfo>
#include "Command.hpp"
#include "NoCommand.hpp"
#include "Remote.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
//
// This is the invoker
//
class RemoteControl {
   private:
    static const int SLOTS = 7;
    std::array<pro::proxy<Command>, SLOTS> _onCommands;
    std::array<pro::proxy<Command>, SLOTS> _offCommands;
    pro::proxy<Command> _noCommand{pro::make_proxy<Command, NoCommand>()};

   public:
    RemoteControl() {
        for (int i = 0; i < SLOTS; i++) {
            _onCommands[i] = _noCommand;
            _offCommands[i] = _noCommand;
        }
    }
    ~RemoteControl() = default;

    void setCommand(int slot,
                    pro::proxy<Command> onCommand,
                    pro::proxy<Command> offCommand) {
        _onCommands[slot] = std::move(onCommand);
        _offCommands[slot] = std::move(offCommand);
    }

    void onButtonWasPushed(int slot) { _onCommands[slot]->execute(); }
    void offButtonWasPushed(int slot) { _offCommands[slot]->execute(); }

    std::string toString() const {
        std::stringstream value;
        value << "\n------ Remote Control -------\n" << std::endl;
        for (int i = 0; i < SLOTS; i++) {
            value << "[slot " << i << "] ";
            value << _onCommands[i]->name();
            value << "    ";
            value << _offCommands[i]->name();
            value << std::endl;
        }
        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote