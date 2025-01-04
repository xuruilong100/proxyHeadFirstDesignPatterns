#pragma once

#include <memory>
#include <string_view>
#include "RCA.hpp"

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class RCAControl {
   private:
    unsigned int _currentStation;
    std::shared_ptr<RCA> _implementor;

   public:
    explicit RCAControl(std::string_view location) : _currentStation(0) {
        _implementor = std::make_shared<RCA>(location);
    }
    RCAControl(const RCAControl&) = default;

    void on() { _implementor->on(); }

    void off() { _implementor->off(); }

    void setChannel(unsigned int channel) {
        _implementor->tuneChannel(channel);
    }

    void setStation(unsigned int channel) {
        _currentStation = channel;
        setChannel(_currentStation);
    }

    void nextChannel() {
        _currentStation++;
        setChannel(_currentStation);
    }

    void previousChannel() {
        _currentStation--;
        setChannel(_currentStation);
    }
};
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes