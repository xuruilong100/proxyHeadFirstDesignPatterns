#pragma once

#include <iostream>
#include <string>
#include "CdPlayer.hpp"
#include "DvdPlayer.hpp"
#include "Tuner.hpp"
#include "memory"

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class Amplifier {
   private:
    std::string _description;
    std::shared_ptr<Tuner> _tuner;
    std::shared_ptr<DvdPlayer> _dvd;
    std::shared_ptr<CdPlayer> _cd;

   public:
    explicit Amplifier(std::string_view description)
        : _description(description) {}
    Amplifier(const Amplifier&) = delete;
    Amplifier& operator=(const Amplifier&) = delete;

    void on() const { std::cout << _description << " on" << std::endl; }

    void off() const { std::cout << _description << " off" << std::endl; }

    void setStereoSound() const {
        std::cout << _description << " stereo mode on" << std::endl;
    }

    void setSurroundSound() const {
        std::cout << _description
                  << " surround sound on (5 speakers, 1 subwoofer)"
                  << std::endl;
    }

    void setVolume(int level) const {
        std::cout << _description << " setting volume to " << level
                  << std::endl;
    }

    void setTuner(std::shared_ptr<Tuner> tuner) {
        _tuner = std::move(tuner);
        std::cout << _description << " setting tuner to " << _tuner->toString()
                  << std::endl;
    }

    void setDvd(std::shared_ptr<DvdPlayer> dvd) {
        _dvd = std::move(dvd);
        std::cout << _description << " setting DVD player to "
                  << _dvd->toString() << std::endl;
    }

    void setCd(std::shared_ptr<CdPlayer> cd) {
        _cd = std::move(cd);
        std::cout << _description << " setting CD player to " << _cd->toString()
                  << std::endl;
    }

    std::string toString() const { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater