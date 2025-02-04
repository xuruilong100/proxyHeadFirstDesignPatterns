#pragma once

#include <memory>
#include "CeilingFan.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
class CeilingFanLowCommand {
   private:
    std::shared_ptr<CeilingFan> _ceilingFan;
    int _prevSpeed;
    inline static const std::string _name{"CeilingFanLowCommand"};

   public:
    explicit CeilingFanLowCommand(std::shared_ptr<CeilingFan> ceilingFan)
        : _ceilingFan(std::move(ceilingFan)) {
        _prevSpeed = _ceilingFan->getSpeed();
    }

    void execute() {
        _prevSpeed = _ceilingFan->getSpeed();
        _ceilingFan->low();
    }

    void undo() {
        if (_prevSpeed == CeilingFan::HIGH) {
            _ceilingFan->high();
        } else if (_prevSpeed == CeilingFan::MEDIUM) {
            _ceilingFan->medium();
        } else if (_prevSpeed == CeilingFan::LOW) {
            _ceilingFan->low();
        } else if (_prevSpeed == CeilingFan::OFF) {
            _ceilingFan->off();
        }
    }

    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo