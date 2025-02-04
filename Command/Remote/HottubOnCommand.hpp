#pragma once

#include <memory>
#include "Hottub.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class HottubOnCommand {
   private:
    std::shared_ptr<Hottub> _hottub;
    inline static const std::string _name{"HottubOnCommand"};

   public:
    explicit HottubOnCommand(std::shared_ptr<Hottub> hottub)
        : _hottub(std::move(hottub)) {}

    void execute() {
        _hottub->on();
        _hottub->heat();
        _hottub->bubblesOn();
    }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote