#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Command::Undo {
class NoCommand {
   private:
    inline static const std::string _name{"NoCommand"};

   public:
    NoCommand() = default;

    void execute() {};
    void undo() {};
    const std::string& name() const { return _name; };
};
}  // namespace HeadFirstDesignPatterns::Command::Undo