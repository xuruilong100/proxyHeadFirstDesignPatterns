#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::Factory::Abstract {
PRO_DEF_MEM_DISPATCH(MemToString, toString);

// for PizzaIngredientFactory
PRO_DEF_MEM_DISPATCH(MemCreateDough, createDough);
PRO_DEF_MEM_DISPATCH(MemCreateSauce, createSauce);
PRO_DEF_MEM_DISPATCH(MemCreateCheese, createCheese);
PRO_DEF_MEM_DISPATCH(MemCreateVeggies, createVeggies);
PRO_DEF_MEM_DISPATCH(MemCreatePepperoni, createPepperoni);
PRO_DEF_MEM_DISPATCH(MemCreateClam, createClam);

// for PizzaStore
PRO_DEF_MEM_DISPATCH(MemCreatePizza, createPizza);

// for Pizza
PRO_DEF_MEM_DISPATCH(MemDough, dough);
PRO_DEF_MEM_DISPATCH(MemSauce, sauce);
PRO_DEF_MEM_DISPATCH(MemVeggies, veggies);
PRO_DEF_MEM_DISPATCH(MemCheese, cheese);
PRO_DEF_MEM_DISPATCH(MemPepperoni, pepperoni);
PRO_DEF_MEM_DISPATCH(MemClam, clam);
PRO_DEF_MEM_DISPATCH(MemPrepare, prepare);
PRO_DEF_MEM_DISPATCH(MemBake, bake);
PRO_DEF_MEM_DISPATCH(MemCut, cut);
PRO_DEF_MEM_DISPATCH(MemBox, box);
PRO_DEF_MEM_DISPATCH(MemSetName, setName);
PRO_DEF_MEM_DISPATCH(MemGetName, getName);
}  // namespace HeadFirstDesignPatterns::Factory::Abstract