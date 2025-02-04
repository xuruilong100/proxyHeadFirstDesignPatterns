#pragma once

#include <memory>
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class LightOnCommand {
   private:
    std::shared_ptr<Light> _light;
    inline static const std::string _name{"LightOnCommand"};

   public:
    explicit LightOnCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {}

    void execute() { _light->on(); }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote