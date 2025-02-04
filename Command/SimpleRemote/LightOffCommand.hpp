#pragma once

#include <memory>
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::SimpleRemote {
class LightOffCommand {
   private:
    std::shared_ptr<Light> _light;

   public:
    explicit LightOffCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {}

    void execute() const { _light->off(); }
};
}  // namespace HeadFirstDesignPatterns::Command::SimpleRemote