#include <iostream>
#include <memory>

/*
The Proxy design pattern provides a surrogate or placeholder for another object to control access 
to it. This pattern is used when we want to add some additional functionalities like access control, 
caching, lazy initialization, etc., to an existing class without changing its code.

Key Elements:
- Subject: An interface which both the real object and the proxy will implement.
- RealSubject: The real object that the proxy represents.
- Proxy: Maintains a reference to the RealSubject, controls access to it, and can also be responsible 
  for its creation and deletion.
- Client: Interacts with the Proxy object.
*/

// 'Subject' Interface
class Subject {
public:
    virtual void request() const = 0;
    virtual ~Subject() {}
};

// 'RealSubject' Class
class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// 'Proxy' Class
class Proxy : public Subject {
private:
    std::unique_ptr<RealSubject> realSubject;

    bool checkAccess() const {
        // Some access control logic
        std::cout << "Proxy: Checking access prior to firing a real request." << std::endl;
        return true;
    }

    void logAccess() const {
        std::cout << "Proxy: Logging the time of request." << std::endl;
    }

public:
    Proxy() : realSubject(std::make_unique<RealSubject>()) {}

    void request() const override {
        if (this->checkAccess()) {
            this->realSubject->request();
            this->logAccess();
        }
    }
};

// Client code
void clientCode(const Subject& subject) {
    // ...
    subject.request();
    // ...
}

int main() {
    Proxy proxy;
    clientCode(proxy);
    return 0;
}
