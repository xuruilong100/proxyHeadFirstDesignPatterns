#pragma once

#include <memory>
#include <string>
#include "ComplaintHandler.hpp"
#include "FanHandler.hpp"
#include "Handler.hpp"
#include "LastHandler.hpp"
#include "NewLocationHandler.hpp"
#include "SpamHandler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class Client {
   private:
    pro::proxy<Handler> _lastHandler{pro::make_proxy<Handler, LastHandler>()};
    pro::proxy<Handler> _newHandler{
        pro::make_proxy<Handler, NewLocationHandler>(_lastHandler)};
    pro::proxy<Handler> _hateHandler{
        pro::make_proxy<Handler, ComplaintHandler>(_newHandler)};
    pro::proxy<Handler> _fanHandler{
        pro::make_proxy<Handler, FanHandler>(_hateHandler)};
    pro::proxy<Handler> _spamHandler{
        pro::make_proxy<Handler, SpamHandler>(_fanHandler)};

   public:
    Client() = default;
    Client(const Client&) = delete;
    void operator=(const Client&) = delete;

    void handleRequest(const std::string& request) {
        HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler::
            handleRequest(_spamHandler, request);
    }

    void print() const { _spamHandler->print(); }
};
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler