#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::Adapter::Ducks {
PRO_DEF_MEM_DISPATCH(MemQuack, quack);
PRO_DEF_MEM_DISPATCH(MemGobble, gobble);
PRO_DEF_MEM_DISPATCH(MemFly, fly);
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks