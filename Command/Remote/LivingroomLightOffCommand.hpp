#pragma once

#include <memory>
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class LivingroomLightOffCommand {
   private:
    std::shared_ptr<Light> _light;
    inline static const std::string _name{"LivingroomLightOffCommand"};

   public:
    explicit LivingroomLightOffCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {}

    void execute() { _light->off(); }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote