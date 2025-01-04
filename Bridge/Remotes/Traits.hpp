#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::Bridge::Remotes {
PRO_DEF_MEM_DISPATCH(MemOn, on);
PRO_DEF_MEM_DISPATCH(MemOff, off);
PRO_DEF_MEM_DISPATCH(MemTuneChannel, tuneChannel);
PRO_DEF_MEM_DISPATCH(MemSetChannel, setChannel);
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes