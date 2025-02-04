#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::Composite::Menus {
PRO_DEF_MEM_DISPATCH(MemAdd, add);
PRO_DEF_MEM_DISPATCH(MemRemove, remove);
PRO_DEF_MEM_DISPATCH(MemGetChild, getChild);
PRO_DEF_MEM_DISPATCH(MemGetName, getName);
PRO_DEF_MEM_DISPATCH(MemGetDescription, getDescription);
PRO_DEF_MEM_DISPATCH(MemGetPrice, getPrice);
PRO_DEF_MEM_DISPATCH(MemIsVegetarian, isVegetarian);
PRO_DEF_MEM_DISPATCH(MemPrint, print);
}  // namespace HeadFirstDesignPatterns::Composite::Menus