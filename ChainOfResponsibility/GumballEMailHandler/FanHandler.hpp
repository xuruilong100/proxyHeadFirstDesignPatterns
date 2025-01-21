#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include "Handler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class FanHandler {
   private:
    std::list<std::string> _requests;
    pro::proxy<Handler> _successor;

   public:
    explicit FanHandler(pro::proxy<Handler> successor = nullptr)
        : _successor(std::move(successor)) {}

    bool canHandleRequest(const std::string& request) const {
        bool value = false;

        if (std::string::npos != request.find("razz")) {
            value = true;
        } else if (std::string::npos != request.find("hip")) {
            value = true;
        } else if (std::string::npos != request.find("radioactive")) {
            value = true;
        } else if (std::string::npos != request.find("blast")) {
            value = true;
        } else if (std::string::npos != request.find("boss")) {
            value = true;
        } else if (std::string::npos != request.find("orbit")) {
            value = true;
        } else if (std::string::npos != request.find("kick")) {
            value = true;
        }
        return value;
    }

    void print() const {
        std::cout << std::endl << "Fan mail, send to CEO:";
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