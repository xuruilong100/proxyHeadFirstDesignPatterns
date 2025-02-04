#pragma once

#include <memory>
#include "Stereo.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class StereoOffCommand {
   private:
    std::shared_ptr<Stereo> _stereo;
    inline static const std::string _name{"StereoOffCommand"};

   public:
    explicit StereoOffCommand(std::shared_ptr<Stereo> stereo)
        : _stereo(std::move(stereo)) {}

    void execute() { _stereo->off(); }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote