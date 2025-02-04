#include "Undo.hpp"

using namespace HeadFirstDesignPatterns::Command::Undo;

int main() {
    auto remoteControl = std::make_shared<RemoteControlWithUndo>();

    auto livingRoomLight = std::make_shared<Light>("Living Room");

    auto livingRoomLightOn =
        pro::make_proxy<Command, LightOnCommand>(livingRoomLight);
    auto livingRoomLightOff =
        pro::make_proxy<Command, LightOffCommand>(livingRoomLight);

    remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);

    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    std::cout << remoteControl->toString() << std::endl;
    remoteControl->undoButtonWasPushed();
    remoteControl->offButtonWasPushed(0);
    remoteControl->onButtonWasPushed(0);
    std::cout << remoteControl->toString() << std::endl;
    remoteControl->undoButtonWasPushed();

    auto ceilingFan = std::make_shared<CeilingFan>("Living Room");

    auto ceilingFanMedium =
        pro::make_proxy<Command, CeilingFanMediumCommand>(ceilingFan);
    auto ceilingFanHigh =
        pro::make_proxy<Command, CeilingFanHighCommand>(ceilingFan);
    auto ceilingFanOff =
        pro::make_proxy<Command, CeilingFanOffCommand>(ceilingFan);

    remoteControl->setCommand(0, ceilingFanMedium, ceilingFanOff);
    remoteControl->setCommand(1, ceilingFanHigh, ceilingFanOff);

    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    std::cout << remoteControl->toString() << std::endl;
    remoteControl->undoButtonWasPushed();

    remoteControl->onButtonWasPushed(1);
    std::cout << remoteControl->toString() << std::endl;
    remoteControl->undoButtonWasPushed();

    return EXIT_SUCCESS;
}

// Output:
/*
Living Room light is on
Living Room light is off

------ Remote Control -------
[slot 0] LightOnCommand    LightOffCommand
[slot 1] NoCommand    NoCommand
[slot 2] NoCommand    NoCommand
[slot 3] NoCommand    NoCommand
[slot 4] NoCommand    NoCommand
[slot 5] NoCommand    NoCommand
[slot 6] NoCommand    NoCommand
[undo] LightOffCommand

Living Room light is on
Living Room light is off
Living Room light is on

------ Remote Control -------
[slot 0] LightOnCommand    LightOffCommand
[slot 1] NoCommand    NoCommand
[slot 2] NoCommand    NoCommand
[slot 3] NoCommand    NoCommand
[slot 4] NoCommand    NoCommand
[slot 5] NoCommand    NoCommand
[slot 6] NoCommand    NoCommand
[undo] LightOnCommand

Living Room light is off
Living Room ceiling fan is on medium
Living Room ceiling fan is off

------ Remote Control -------
[slot 0] CeilingFanMediumCommand    CeilingFanOffCommand
[slot 1] CeilingFanHighCommand    CeilingFanOffCommand
[slot 2] NoCommand    NoCommand
[slot 3] NoCommand    NoCommand
[slot 4] NoCommand    NoCommand
[slot 5] NoCommand    NoCommand
[slot 6] NoCommand    NoCommand
[undo] CeilingFanOffCommand

Living Room ceiling fan is on medium
Living Room ceiling fan is on high

------ Remote Control -------
[slot 0] CeilingFanMediumCommand    CeilingFanOffCommand
[slot 1] CeilingFanHighCommand    CeilingFanOffCommand
[slot 2] NoCommand    NoCommand
[slot 3] NoCommand    NoCommand
[slot 4] NoCommand    NoCommand
[slot 5] NoCommand    NoCommand
[slot 6] NoCommand    NoCommand
[undo] CeilingFanHighCommand

Living Room ceiling fan is on medium
*/