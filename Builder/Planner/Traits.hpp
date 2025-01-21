#pragma once
#include <proxy/proxy.h>
#include <stdexcept>

namespace HeadFirstDesignPatterns::Builder {
PRO_DEF_MEM_DISPATCH(MemBuildDay, buildDay);
PRO_DEF_MEM_DISPATCH(MemAddHotel, addHotel);
PRO_DEF_MEM_DISPATCH(MemAddTickets, addTickets);
PRO_DEF_MEM_DISPATCH(MemAddReservations, addReservations);
PRO_DEF_MEM_DISPATCH(MemAddSpecialEvent, addSpecialEvent);
PRO_DEF_MEM_DISPATCH(MemGetVacationPlanner, getVacationPlanner);

PRO_DEF_MEM_DISPATCH(MemAdd, add);
PRO_DEF_MEM_DISPATCH(MemRemove, remove);
PRO_DEF_MEM_DISPATCH(MemGetChild, getChild);
PRO_DEF_MEM_DISPATCH(MemGetName, getName);
PRO_DEF_MEM_DISPATCH(MemGetDescription, getDescription);
PRO_DEF_MEM_DISPATCH(MemGetPrice, getPrice);
PRO_DEF_MEM_DISPATCH(MemPrint, print);

// struct NotImplemented {
//     explicit NotImplemented(auto&&...) {
//         throw std::runtime_error("Not implemented!");
//     }
//
//     template <class T>
//     operator T() const noexcept {
//         std::terminate();
//     }
// };

// PRO_DEF_WEAK_DISPATCH(WEakMemAdd, MemAdd, NotImplemented);
// PRO_DEF_WEAK_DISPATCH(WEakMemRemove, MemRemove, NotImplemented);
// PRO_DEF_WEAK_DISPATCH(WEakMemGetChild, MemGetChild, NotImplemented);
// PRO_DEF_WEAK_DISPATCH(WEakMemGetName, MemGetName, NotImplemented);
// PRO_DEF_WEAK_DISPATCH(WEakMemGetDescription, MemGetDescription,
// NotImplemented); PRO_DEF_WEAK_DISPATCH(WEakMemGetPrice, MemGetPrice,
// NotImplemented); PRO_DEF_WEAK_DISPATCH(WEakMemPrint, MemPrint,
// NotImplemented);
}  // namespace HeadFirstDesignPatterns::Builder