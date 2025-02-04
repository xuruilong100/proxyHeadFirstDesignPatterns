#pragma once

#include <memory>
#include "Command.hpp"
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::SimpleRemote {
class LightOnCommand {
   private:
    std::shared_ptr<Light> _light;

   public:
    explicit LightOnCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {}

    void execute() const { _light->on(); }
};
}  // namespace HeadFirstDesignPatterns::Command::SimpleRemote