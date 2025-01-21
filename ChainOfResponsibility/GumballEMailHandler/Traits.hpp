#pragma once

#include <proxy/proxy.h>

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
PRO_DEF_MEM_DISPATCH(MemCanHandleRequest, canHandleRequest);
PRO_DEF_MEM_DISPATCH(MemPrint, print);
PRO_DEF_MEM_DISPATCH(MemHandleAndStore, handleAndStore);
PRO_DEF_MEM_DISPATCH(MemToNextHandler, toNextHandler);
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler