#pragma once

#include <memory>
#include "CeilingFan.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class CeilingFanOffCommand {
   private:
    std::shared_ptr<CeilingFan> _ceilingFan;
    inline static const std::string _name{"CeilingFanOffCommand"};

   public:
    explicit CeilingFanOffCommand(std::shared_ptr<CeilingFan> ceilingFan)
        : _ceilingFan(std::move(ceilingFan)) {}

    void execute() { _ceilingFan->off(); }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote