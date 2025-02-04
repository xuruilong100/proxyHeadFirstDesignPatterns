#pragma once

#include <memory>
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
class LightOffCommand {
   private:
    std::shared_ptr<Light> _light;
    inline static const std::string _name{"LightOffCommand"};

   public:
    explicit LightOffCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {}

    void execute() { _light->off(); }

    void undo() { _light->on(); }

    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo