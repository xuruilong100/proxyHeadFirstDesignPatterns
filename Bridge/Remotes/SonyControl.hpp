#pragma once

#include <memory>
#include <string_view>
#include "Sony.hpp"

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class SonyControl {
   private:
    unsigned int _currentStation;
    std::shared_ptr<Sony> _implementor;

   public:
    explicit SonyControl(std::string_view location) : _currentStation(0) {
        _implementor = std::make_shared<Sony>(location);
    }
    SonyControl(const SonyControl&) = default;

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