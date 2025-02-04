#include "Remote.hpp"

using namespace HeadFirstDesignPatterns::Command::Remote;

int main() {
    auto remoteControl = std::make_shared<RemoteControl>();

    auto livingRoomLight = std::make_shared<Light>("Living Room");
    auto kitchenLight = std::make_shared<Light>("Kitchen");
    auto ceilingFan = std::make_shared<CeilingFan>("Living Room");
    auto garageDoor = std::make_shared<GarageDoor>("Garage");
    auto stereo = std::make_shared<Stereo>("Living Room");

    auto livingRoomLightOn =
        pro::make_proxy<Command, LightOnCommand>(livingRoomLight);
    auto livingRoomLightOff =
        pro::make_proxy<Command, LightOffCommand>(livingRoomLight);
    auto kitchenLightOn =
        pro::make_proxy<Command, LightOnCommand>(kitchenLight);
    auto kitchenLightOff =
        pro::make_proxy<Command, LightOffCommand>(kitchenLight);

    auto ceilingFanOn =
        pro::make_proxy<Command, CeilingFanOnCommand>(ceilingFan);
    auto ceilingFanOff =
        pro::make_proxy<Command, CeilingFanOffCommand>(ceilingFan);

    auto garageDoorUp =
        pro::make_proxy<Command, GarageDoorUpCommand>(garageDoor);
    auto garageDoorDown =
        pro::make_proxy<Command, GarageDoorDownCommand>(garageDoor);

    auto stereoOnWithCD =
        pro::make_proxy<Command, StereoOnWithCDCommand>(stereo);
    auto stereoOff = pro::make_proxy<Command, StereoOffCommand>(stereo);

    remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);
    remoteControl->setCommand(1, kitchenLightOn, kitchenLightOff);
    remoteControl->setCommand(2, ceilingFanOn, ceilingFanOff);
    remoteControl->setCommand(3, stereoOnWithCD, stereoOff);
    remoteControl->setCommand(4, garageDoorUp, garageDoorDown);

    std::cout << remoteControl->toString() << std::endl;

    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    remoteControl->onButtonWasPushed(1);
    remoteControl->offButtonWasPushed(1);
    remoteControl->onButtonWasPushed(2);
    remoteControl->offButtonWasPushed(2);
    remoteControl->onButtonWasPushed(3);
    remoteControl->offButtonWasPushed(3);
    remoteControl->onButtonWasPushed(4);
    remoteControl->offButtonWasPushed(4);

    return EXIT_SUCCESS;
}

// Output:
/*
------ Remote Control -------

[slot 0] LightOnCommand    LightOffCommand
[slot 1] LightOnCommand    LightOffCommand
[slot 2] CeilingFanOnCommand    CeilingFanOffCommand
[slot 3] StereoOnWithCDCommand    StereoOffCommand
[slot 4] GarageDoorUpCommand    GarageDoorDownCommand
[slot 5] NoCommand    NoCommand
[slot 6] NoCommand    NoCommand

Living Room light is on
Living Room light is off
Kitchen light is on
Kitchen light is off
Living Room ceiling fan is on high
Living Room ceiling fan is off
Living Room stereo is on
Living Room stereo is set for CD input
Living Room Stereo volume set to 11
Living Room stereo is off
Garage Door is Up
Garage Door is Down
*/