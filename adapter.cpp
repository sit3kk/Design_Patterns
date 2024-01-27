#include <iostream>
#include <memory>

/*
The Adapter design pattern is a structural design pattern that allows objects with incompatible 
interfaces to work together. It acts as a bridge between two incompatible interfaces. This pattern 
involves a single class, known as the Adapter, which joins the functionalities of an independent 
or incompatible class/interface to another class/interface.

Key Elements of the Adapter Pattern:

1. Target (Target): This is the interface that the client expects or needs to use. It defines the 
   domain-specific interface that Client uses.

2. Client (Client): The class that interacts with the Target interface, but requires a different 
   interface (Adaptee) to function properly.

3. Adaptee (Adaptee): The class that needs adapting. It has a specific interface that needs to be 
   converted into a more general or compatible interface that the Client expects.

4. Adapter (Adapter): This is a class that implements the Target interface and includes a reference 
   to an instance of the Adaptee class. The Adapter translates calls to the Target interface into 
   calls to the Adaptee's interface. It allows the client to access the functionality of the Adaptee 
   class without modifying its code.

The Adapter pattern is often used to make existing classes work with others without modifying their 
source code. An example of this could be when a library or system provides classes that need to be 
integrated into an existing system.
*/


// The 'Target' interface represents the interface that the client expects.
class Target {
public:
    virtual void request() const {
        std::cout << "Target: Default target's behavior." << std::endl;
    }
};

// The 'Adaptee' contains some useful behavior, but its interface is incompatible
// with the existing client code. The Adaptee needs some adaptation before the
// client code can use it.
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee: Specific request." << std::endl;
    }
};

// The 'Adapter' class makes the Adaptee's interface compatible with the Target's
// interface via multiple inheritance.
class Adapter : public Target, private Adaptee {
public:
    Adapter() = default;
    void request() const override {
        std::cout << "Adapter: Translated call to the adaptee's specificRequest." << std::endl;
        specificRequest();
    }
};

// Client code supports all classes that follow the Target interface.
void clientCode(const Target& target) {
    target.request();
}

// Main function: Entry point of the program which demonstrates Adapter pattern.
int main() {
    std::cout << "Client: I can work just fine with the Target objects." << std::endl;
    Target target;
    clientCode(target);
    
    std::cout << "\nClient: The Adaptee class has a weird interface. See, I don't understand it:" << std::endl;
    Adaptee adaptee;
    adaptee.specificRequest();
    
    std::cout << "\nClient: But I can work with it via the Adapter:" << std::endl;
    Adapter adapter;
    clientCode(adapter);
    
    return 0;
}
