#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include "Traits.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
struct Handler
    : pro::facade_builder::                                                  //
      add_convention<MemCanHandleRequest, bool(const std::string&) const>::  //
      add_convention<MemPrint, void() const>::                               //
      add_convention<MemHandleAndStore, void(const std::string&)>::          //
      add_convention<MemToNextHandler, void(const std::string&)>::           //
      support_copy<pro::constraint_level::nontrivial>::                      //
      build {};

void handleRequest(pro::proxy<Handler>& handler, std::string request) {
    std::transform(request.begin(), request.end(), request.begin(), tolower);

    if (handler->canHandleRequest(request) == true) {
        handler->handleAndStore(request);
    } else {
        handler->toNextHandler(request);
    }
}

void printRequests(const std::list<std::string>& requests) {
    std::cout << " count=" << requests.size() << std::endl;
    auto iterator = requests.begin();
    while (iterator != requests.end()) {
        std::cout << " - " << (*iterator) << std::endl;
        iterator++;
    }
}
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler