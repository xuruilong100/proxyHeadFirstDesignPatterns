#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::Command::Remote {
PRO_DEF_MEM_DISPATCH(MemExecute, execute);
PRO_DEF_MEM_DISPATCH(MemName, name);
}  // namespace HeadFirstDesignPatterns::Command::Remote