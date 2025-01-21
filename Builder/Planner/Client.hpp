#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include "VacationBuilder.hpp"

namespace HeadFirstDesignPatterns::Builder {
namespace {
static inline int promptUser(std::string_view prompt) {
    int value = 0;
    std::cout << prompt << std::endl;
    std::cin >> value;
    return value;
}
}  // namespace

class Client {
   public:
    explicit Client(std::shared_ptr<VacationBuilder> builder)
        : _builder(std::move(builder)) {}
    Client(const Client&) = delete;
    void operator=(const Client&) = delete;

    auto constructPlanner() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        tm local;
        localtime_s(&local, &now_c);

        do {
            std::cout << std::endl
                      << "Enter vacation date (YYYY MM DD) where..."
                      << std::endl;
            std::cout << "YYYY=2006, 2007, etc..., MM=1-12, DD=1-31, separated "
                         "by spaces"
                      << std::endl;
            std::cout << "YYYY MM DD" << std::endl;
            std::cin >> local.tm_year >> local.tm_mon >> local.tm_mday;

            local.tm_year -= 1900;
            local.tm_mon -= 1;

            _builder->buildDay(local);

            switch (promptUser(
                "hotel? (0=No, 1=Grand Facadion, 2=Nostalgic Momento)")) {
                case 1: {
                    _builder->addHotel(hotelGrandFacadion);
                } break;
                case 2: {
                    _builder->addHotel(hotelNostalgicMomento);
                } break;
            }

            switch (promptUser("Park tickets? (0=No, 1=Yes)")) {
                case 1: {
                    _builder->addTickets(ticketPark);
                } break;
            }

            switch (
                promptUser("Dinner Reservations? (0=No, 1=Pancake House, "
                           "2=Objectville Diner)")) {
                case 1: {
                    _builder->addReservations(dinnerPancakeHouse);
                } break;
                case 2: {
                    _builder->addReservations(dinnerObjectvilleDiner);
                } break;
            }

            switch (
                promptUser("Special Events? (0=No, 1=Choc-O-Holic factory "
                           "tour, 2=Pizza factory tour)")) {
                case 1: {
                    _builder->addSpecialEvent(specialChocolateFactoryTour);
                } break;
                case 2: {
                    _builder->addSpecialEvent(specialPizzaFactoryTour);
                } break;
            }
        } while (promptUser(
                     "Would you like to plan another day? (0=No, 1=Yes)") == 1);

        return _builder->getVacationPlanner();
    }

   private:
    std::shared_ptr<VacationBuilder> _builder;
};
}  // namespace HeadFirstDesignPatterns::Builder