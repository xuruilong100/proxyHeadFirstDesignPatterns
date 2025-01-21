#pragma once

#include <ctime>
#include <memory>
#include <string_view>
#include "Traits.hpp"
#include "Vacation.hpp"

namespace HeadFirstDesignPatterns::Builder {
struct Builder
    : pro::facade_builder::                                                 //
      add_convention<MemBuildDay, void(const tm&)>::                        //
      add_convention<MemAddHotel, void(std::string_view)>::                 //
      add_convention<MemAddTickets, void(std::string_view)>::               //
      add_convention<MemAddReservations, void(std::string_view)>::          //
      add_convention<MemAddSpecialEvent, void(std::string_view)>::          //
      add_convention<MemGetVacationPlanner, std::shared_ptr<Vacation>()>::  //
      support_copy<pro::constraint_level::nontrivial>::                     //
      build {};
}  // namespace HeadFirstDesignPatterns::Builder