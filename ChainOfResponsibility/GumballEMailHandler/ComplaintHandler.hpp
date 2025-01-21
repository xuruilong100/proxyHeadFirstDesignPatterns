#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include "Handler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class ComplaintHandler {
   private:
    std::list<std::string> _requests;
    pro::proxy<Handler> _successor;

   public:
    explicit ComplaintHandler(pro::proxy<Handler> successor = nullptr)
        : _successor(std::move(successor)) {}

    bool canHandleRequest(const std::string& request) const {
        bool value = false;

        if (std::string::npos != request.find("bruisin")) {
            value = true;
        } else if (std::string::npos != request.find("frosted")) {
            value = true;
        } else if (std::string::npos != request.find("no where")) {
            value = true;
        } else if (std::string::npos != request.find("rattle my cage")) {
            value = true;
        } else if (std::string::npos != request.find("tale nightingale")) {
            value = true;
        }
        return value;
    }

    void print() const {
        std::cout << std::endl << "Hate mail, send to Legal:";
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