#pragma once

#include <proxy/proxy.h>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::Bridge::Remotes {
struct RemoteControl
    : pro::facade_builder::add_convention<MemOn, void()>::add_convention<
          MemOff,
          void()>::add_convention<MemSetChannel, void(unsigned int)>::
          support_copy<pro::constraint_level::nontrivial>::build {};
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes