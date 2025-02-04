#pragma once

#include <memory>
#include "Stereo.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class StereoOnWithCDCommand {
   private:
    std::shared_ptr<Stereo> _stereo;
    inline static const std::string _name{"StereoOnWithCDCommand"};

   public:
    explicit StereoOnWithCDCommand(std::shared_ptr<Stereo> stereo)
        : _stereo(std::move(stereo)) {}

    void execute() {
        _stereo->on();
        _stereo->setCD();
        _stereo->setVolume(11);
    }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote