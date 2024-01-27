#include <iostream>
#include <string>

/*
The Facade design pattern provides a simplified interface to a complex system of classes, a library, 
or a framework. It doesn't encapsulate the subsystem but provides a simplified interface to it.

Key Elements of the Facade Pattern:
- Facade: Provides a simple interface to the complex functionality of a subsystem. It delegates 
  client requests to appropriate subsystem objects and takes care of their lifecycle.
- Complex Subsystem: Consists of multiple classes that work together. The subsystem may be complex 
  due to its functionality or because it's a legacy system.
- Client: Uses the Facade to access the functionality of the subsystem in a simplified manner.
*/

// Subsystem Class 1
class Subsystem1 {
public:
    std::string operation1() const {
        return "Subsystem1: Ready!\n";
    }

    std::string operationN() const {
        return "Subsystem1: Go!\n";
    }
};

// Subsystem Class 2
class Subsystem2 {
public:
    std::string operation1() const {
        return "Subsystem2: Get ready!\n";
    }

    std::string operationZ() const {
        return "Subsystem2: Fire!\n";
    }
};

// Facade Class
class Facade {
protected:
    Subsystem1* subsystem1;
    Subsystem2* subsystem2;

public:
    Facade(Subsystem1* s1 = nullptr, Subsystem2* s2 = nullptr) {
        subsystem1 = s1 ?: new Subsystem1;
        subsystem2 = s2 ?: new Subsystem2;
    }

    ~Facade() {
        delete subsystem1;
        delete subsystem2;
    }

    std::string operation() {
        std::string result = "Facade initializes subsystems:\n";
        result += subsystem1->operation1();
        result += subsystem2->operation1();
        result += "Facade orders subsystems to perform the action:\n";
        result += subsystem1->operationN();
        result += subsystem2->operationZ();
        return result;
    }
};

// Client code
int main() {
    Subsystem1* subsystem1 = new Subsystem1;
    Subsystem2* subsystem2 = new Subsystem2;
    Facade* facade = new Facade(subsystem1, subsystem2);
    std::cout << facade->operation();

    delete facade;

    return 0;
}
