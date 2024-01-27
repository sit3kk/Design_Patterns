#include <iostream>
#include <memory>

/*
The Chain of Responsibility design pattern creates a chain of receiver objects for a request. This pattern 
delegates the request along the chain until an object handles it. It allows an object to send a command without 
knowing which object will handle the command, thus achieving decoupling between sender and receiver.

Key Elements:
- Handler: An interface for handling requests and optionally implementing the successor link.
- ConcreteHandlers: Concrete classes that handle requests they are responsible for. If a handler can't handle a 
  request, it passes it to the next handler in the chain.
- Client: Initiates the request to a ConcreteHandler object in the chain.
*/

// The 'Handler' abstract class with a method for setting the next handler and for handling requests
class Handler {
protected:
    std::shared_ptr<Handler> nextHandler;

public:
    virtual ~Handler() {}

    void setNext(std::shared_ptr<Handler> handler) {
        nextHandler = handler;
    }

    virtual void handleRequest(const std::string& request) {
        if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

// Concrete Handlers either handle a request or pass it to the next handler in the chain
class ConcreteHandler1 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Request1") {
            std::cout << "ConcreteHandler1 handled the request: " << request << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Request2") {
            std::cout << "ConcreteHandler2 handled the request: " << request << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

class ConcreteHandler3 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        std::cout << "ConcreteHandler3 handled the request: " << request << std::endl;
    }
};

// Client code forms a chain of handlers and then passes requests to it
int main() {
    std::shared_ptr<Handler> handler1 = std::make_shared<ConcreteHandler1>();
    std::shared_ptr<Handler> handler2 = std::make_shared<ConcreteHandler2>();
    std::shared_ptr<Handler> handler3 = std::make_shared<ConcreteHandler3>();

    handler1->setNext(handler2);
    handler2->setNext(handler3);

    handler1->handleRequest("Request1");
    handler1->handleRequest("Request2");
    handler1->handleRequest("UnknownRequest");

    return 0;
}
