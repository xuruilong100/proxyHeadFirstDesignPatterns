#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::Factory::Simple {
PRO_DEF_MEM_DISPATCH(MemName, name);
PRO_DEF_MEM_DISPATCH(MemDough, dough);
PRO_DEF_MEM_DISPATCH(MemSauce, sauce);
PRO_DEF_MEM_DISPATCH(MemToppings, toppings);
}  // namespace HeadFirstDesignPatterns::Factory::Simple