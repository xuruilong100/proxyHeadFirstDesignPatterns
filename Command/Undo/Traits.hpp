#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::Command::Undo {
PRO_DEF_MEM_DISPATCH(MemExecute, execute);
PRO_DEF_MEM_DISPATCH(MemUndo, undo);
PRO_DEF_MEM_DISPATCH(MemName, name);
}  // namespace HeadFirstDesignPatterns::Command::Undo