#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::Factory::Method {
// for Pizza
PRO_DEF_MEM_DISPATCH(MemName, name);
PRO_DEF_MEM_DISPATCH(MemDough, dough);
PRO_DEF_MEM_DISPATCH(MemSauce, sauce);
PRO_DEF_MEM_DISPATCH(MemToppings, toppings);
PRO_DEF_MEM_DISPATCH(MemPrepare, prepare);
PRO_DEF_MEM_DISPATCH(MemBake, bake);
PRO_DEF_MEM_DISPATCH(MemCut, cut);
PRO_DEF_MEM_DISPATCH(MemBox, box);

// for PizzaStore
PRO_DEF_MEM_DISPATCH(MemCreatePizza, createPizza);
}  // namespace HeadFirstDesignPatterns::Factory::Method