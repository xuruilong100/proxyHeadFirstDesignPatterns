#pragma once

#include <ctime>
#include <iostream>
#include <string>
#include <string_view>
#include "Day.hpp"
#include "Event.hpp"
#include "EventComponent.hpp"
#include "EventItem.hpp"

namespace HeadFirstDesignPatterns::Builder {
namespace {
const std::string hotelGrandFacadion("Grand Facadion");
const std::string hotelNostalgicMomento("Nostalgic Momento");
const std::string ticketPark("Park tickets");
const std::string ticketPatternsOnIce("Patterns On Ice");
const std::string ticketCirqueDuPatterns("Cirque Du Patterns");
const std::string dinnerObjectvilleDiner("Objectville Diner");
const std::string dinnerPancakeHouse("Pancake House");
const std::string specialChocolateFactoryTour("Choc-O-Holic factory tour");
const std::string specialPizzaFactoryTour("Pizza factory tour");
}  // namespace

class VacationBuilder {
   private:
    std::shared_ptr<Event> _vacation{
        std::make_shared<Event>("Vacation Itinerary", "All events")};
    pro::proxy<EventComponent> _currentDay;
    pro::proxy<EventComponent> _currentEvent;

   public:
    VacationBuilder() {
        std::cout << std::endl
                  << "Welcome to Patternsland Vacation Planner!" << std::endl;
    }

    VacationBuilder(const VacationBuilder&) = default;

    ~VacationBuilder() {
        std::cout << std::endl
                  << "Goodbye and have a dreamy vacation!" << std::endl;
    }

    void buildDay(const tm& date) {
        _currentDay = _vacation->add(pro::make_proxy<EventComponent, Day>(
            std::make_shared<Event>(
                "Day", std::to_string(_vacation->getChildCount() + 1)),
            date));
        _currentEvent = _currentDay;
    }

    void addHotel(std::string_view hotel) {
        if (hotel == hotelGrandFacadion) {
            _currentDay->add(pro::make_proxy<EventComponent, EventItem>(
                "Hotel", hotelGrandFacadion, 399.0));
        } else if (hotel == hotelNostalgicMomento) {
            _currentDay->add(pro::make_proxy<EventComponent, EventItem>(
                "Hotel", hotelNostalgicMomento, 199.0));
        }
    }

    void addTickets(std::string_view event) {
        if (event == ticketPark) {
            _currentEvent->add(pro::make_proxy<EventComponent, EventItem>(
                "Tickets", ticketPark, 75.0));
        } else if (event == ticketPatternsOnIce) {
            _currentEvent->add(pro::make_proxy<EventComponent, EventItem>(
                "Tickets", ticketPatternsOnIce, 45.0));
        } else if (event == ticketCirqueDuPatterns) {
            _currentEvent->add(pro::make_proxy<EventComponent, EventItem>(
                "Tickets", ticketCirqueDuPatterns, 60.0));
        }
    }

    void addReservations(std::string_view event) {
        _currentEvent = _currentDay->add(
            pro::make_proxy<EventComponent, Event>("Reservation", "Dinner"));
        _currentEvent->add(pro::make_proxy<EventComponent, Event>(event, ""));
    }

    void addSpecialEvent(std::string_view event) {
        _currentEvent = _currentDay->add(pro::make_proxy<EventComponent, Event>(
            "Reservation", "Special event"));
        if (event.compare(specialChocolateFactoryTour) == 0) {
            _currentEvent->add(pro::make_proxy<EventComponent, EventItem>(
                "Tickets", specialChocolateFactoryTour, 45.0));
        } else if (event.compare(specialPizzaFactoryTour) == 0) {
            _currentEvent->add(pro::make_proxy<EventComponent, EventItem>(
                "Tickets", specialPizzaFactoryTour, 25.0));
        }
    }

    std::shared_ptr<Vacation> getVacationPlanner() {
        return std::make_shared<Vacation>(_vacation);
    }
};
}  // namespace HeadFirstDesignPatterns::Builder