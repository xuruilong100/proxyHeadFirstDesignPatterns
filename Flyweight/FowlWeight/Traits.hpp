#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
PRO_DEF_MEM_DISPATCH(MemToString, toString);

// for Fowl
PRO_DEF_MEM_DISPATCH(MemQuack, quack);
PRO_DEF_MEM_DISPATCH(MemSwim, swim);

// for Turkey
PRO_DEF_MEM_DISPATCH(MemGobble, gobble);
PRO_DEF_MEM_DISPATCH(MemWalk, walk);
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight