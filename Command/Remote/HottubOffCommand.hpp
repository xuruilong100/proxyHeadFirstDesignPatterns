#pragma once

#include <memory>
#include "Hottub.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class HottubOffCommand {
   private:
    std::shared_ptr<Hottub> _hottub;
    inline static const std::string _name{"HottubOffCommand"};

   public:
    explicit HottubOffCommand(std::shared_ptr<Hottub> hottub)
        : _hottub(std::move(hottub)) {}

    void execute() {
        _hottub->cool();
        _hottub->off();
    }
    const std::string& name() const { return _name; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote