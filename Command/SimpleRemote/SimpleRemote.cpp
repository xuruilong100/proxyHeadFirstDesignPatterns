#include "SimpleRemote.hpp"

using namespace HeadFirstDesignPatterns::Command::SimpleRemote;

int main() {
    auto remote = std::make_shared<SimpleRemoteControl>();
    auto light = std::make_shared<Light>();
    auto garageDoor = std::make_shared<GarageDoor>();
    auto lightOn = pro::make_proxy<Command, LightOnCommand>(light);
    auto garageOpen =
        pro::make_proxy<Command, GarageDoorOpenCommand>(garageDoor);

    remote->setCommand(lightOn);
    remote->buttonWasPressed();
    remote->setCommand(garageOpen);
    remote->buttonWasPressed();

    return EXIT_SUCCESS;
}

// Output:
/*
Light is on
Garage Door is Open
*/