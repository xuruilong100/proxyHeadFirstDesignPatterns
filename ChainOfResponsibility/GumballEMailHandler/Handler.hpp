#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
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

// class Handler {
//    private:
//     std::list<std::string> _requests;
//     std::shared_ptr<Handler> _successor;
//
//     void handleAndStore(const std::string& request) {
//         _requests.push_back(request);
//     }
//
//     void toNextHandler(const std::string& request) {
//         if (_successor) {
//             _successor->handleRequest(request);
//         }
//     }
//
//    public:
//     explicit Handler(std::shared_ptr<Handler> successor = nullptr)
//         : _successor(std::move(successor)) {}
//     virtual ~Handler() = default;
//
//     void handleRequest(std::string request) {
//         std::transform(request.begin(), request.end(), request.begin(),
//                        tolower);
//
//         if (canHandleRequest(request) == true) {
//             handleAndStore(request);
//         } else {
//             toNextHandler(request);
//         }
//     }
//
//     virtual bool canHandleRequest(const std::string& request) const = 0;
//
//     virtual void print() const = 0 {
//         std::cout << " count=" << _requests.size() << std::endl;
//         auto iterator = _requests.begin();
//         while (iterator != _requests.end()) {
//             std::cout << " - " << (*iterator) << std::endl;
//             iterator++;
//         }
//         if (_successor) {
//             _successor->print();
//         }
//     }
// };
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler