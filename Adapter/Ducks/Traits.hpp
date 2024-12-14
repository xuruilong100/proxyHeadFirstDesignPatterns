#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::Adapter::Ducks {
PRO_DEF_MEM_DISPATCH(memQuack, quack);
PRO_DEF_MEM_DISPATCH(memGobble, gobble);
PRO_DEF_MEM_DISPATCH(memFly, fly);
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks