#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include "Handler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class NewLocationHandler {
   private:
    std::list<std::string> _requests;
    pro::proxy<Handler> _successor;

   public:
    explicit NewLocationHandler(pro::proxy<Handler> successor = nullptr)
        : _successor(std::move(successor)) {}

    bool canHandleRequest(const std::string& request) const {
        bool value = false;
        if (std::string::npos != request.find("store")) {
            value = true;
        }
        return value;
    }

    void print() const {
        std::cout << std::endl << "Request mail, send to Business Development:";
        printRequests(_requests);
        if (_successor) {
            _successor->print();
        }
    }

    void handleAndStore(const std::string& request) {
        _requests.push_back(request);
    }

    void toNextHandler(const std::string& request) {
        if (_successor) {
            handleRequest(_successor, request);
        }
    }
};
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler