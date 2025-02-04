#pragma once

#include <memory>
#include "Command.hpp"
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class LivingroomLightOnCommand {
   private:
    std::shared_ptr<Light> _light;
    inline static const std::string _name{"LivingroomLightOnCommand"};

   public:
    explicit LivingroomLightOnCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {}

    void execute() { _light->on(); }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote