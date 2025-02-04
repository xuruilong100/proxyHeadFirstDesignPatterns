#pragma once

#include <array>
#include <sstream>
#include <string>
#include "Command.hpp"
#include "NoCommand.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
//
// This is the invoker
//
class RemoteControlWithUndo {
   private:
    static const int SLOTS = 7;

    std::array<pro::proxy<Command>, SLOTS> _onCommands;
    std::array<pro::proxy<Command>, SLOTS> _offCommands;
    pro::proxy<Command> _noCommand{pro::make_proxy<Command, NoCommand>()};
    pro::proxy<Command> _undoCommand{pro::make_proxy<Command, NoCommand>()};

   public:
    RemoteControlWithUndo() {
        for (int i = 0; i < SLOTS; i++) {
            _onCommands[i] = _noCommand;
            _offCommands[i] = _noCommand;
        }
        _undoCommand = _noCommand;
    }

    ~RemoteControlWithUndo() = default;

    void setCommand(int slot,
                    pro::proxy<Command> onCommand,
                    pro::proxy<Command> offCommand) {
        _onCommands[slot] = std::move(onCommand);
        _offCommands[slot] = std::move(offCommand);
    }

    void onButtonWasPushed(int slot) {
        _onCommands[slot]->execute();
        _undoCommand = _onCommands[slot];
    }

    void offButtonWasPushed(int slot) {
        _offCommands[slot]->execute();
        _undoCommand = _offCommands[slot];
    }

    void undoButtonWasPushed() { _undoCommand->undo(); }

    std::string toString() const {
        std::stringstream value;
        value << std::endl << "------ Remote Control -------" << std::endl;
        for (int i = 0; i < SLOTS; i++) {
            value << "[slot " << i << "] ";
            value << _onCommands[i]->name();
            value << "    ";
            value << _offCommands[i]->name();
            value << std::endl;
        }
        value << "[undo] " << _undoCommand->name() << std::endl;

        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo