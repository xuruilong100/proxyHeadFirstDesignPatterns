#include "Remotes.hpp"
#include <proxy/proxy.h>
#include <vector>

using namespace HeadFirstDesignPatterns::Bridge::Remotes;

int main() {
    std::vector<pro::proxy<RemoteControl>> remotes;

    SonyControl sonyControl("XBR in living room");
    remotes.push_back(&sonyControl);

    RCAControl rcaControl("19 inch in kitchen");
    remotes.push_back(&rcaControl);

    // turn on all tv's
    for (auto& r : remotes) {
        r->on();
    }

    sonyControl.nextChannel();
    rcaControl.setStation(35);

    // turn off all tv's
    for (auto& r : remotes) {
        r->off();
    }

    return EXIT_SUCCESS;
}

// Output:
/*
Sony XBR in living room TV is on
RCA 19 inch in kitchen TV is on
Sony XBR in living room tuned to channel 1
RCA 19 inch in kitchen tuned to channel 35
Sony XBR in living room TV is off
RCA 19 inch in kitchen TV is off
*/