#pragma once

#include <iostream>
#include <string>
#include "Handler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class LastHandler {
   private:
    std::list<std::string> _requests;

   public:
    LastHandler() = default;

    bool canHandleRequest(const std::string& request) const { return true; }

    void print() const {
        std::cout << std::endl << "Unclassified, send to AI team:";
        printRequests(_requests);
    }

    void handleAndStore(const std::string& request) {
        _requests.push_back(request);
    }

    void toNextHandler(const std::string& request) {}
};
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler