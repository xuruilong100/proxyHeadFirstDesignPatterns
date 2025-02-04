#pragma once

#include <memory>

#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
class DimmerLightOnCommand {
   private:
    std::shared_ptr<Light> _light;
    int _prevLevel;
    inline static const std::string _name{"DimmerLightOnCommand"};

   public:
    explicit DimmerLightOnCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {
        _prevLevel = _light->getLevel();
    }

    void execute() {
        _prevLevel = _light->getLevel();
        _light->dim(75);
    }

    void undo() { _light->dim(_prevLevel); }

    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo