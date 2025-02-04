#pragma once

#include <memory>
#include "CeilingFan.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class CeilingFanOnCommand {
   private:
    std::shared_ptr<CeilingFan> _ceilingFan;
    inline static const std::string _name{"CeilingFanOnCommand"};

   public:
    explicit CeilingFanOnCommand(std::shared_ptr<CeilingFan> ceilingFan)
        : _ceilingFan(std::move(ceilingFan)) {}

    void execute() { _ceilingFan->high(); }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote