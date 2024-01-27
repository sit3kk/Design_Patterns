#include <iostream>
#include <memory>

/*
The Bridge design pattern is a structural design pattern that decouples an abstraction from its
implementation, allowing them to vary independently. The pattern involves an interface which acts
as a bridge between the abstraction and its implementation, ensuring that they can vary independently
without affecting each other.

Key Elements of the Bridge Pattern:

1. Implementor (Implementor): This is an interface that defines the operations to be implemented.
   In the Bridge pattern, the Implementor interface provides a way to perform the operations in
   different ways, but it is separate from the Abstraction's interface.

2. ConcreteImplementor (Concrete Implementor): These are concrete classes that implement the
   Implementor interface. Each ConcreteImplementor provides a specific implementation of the
   Implementor interface.

3. Abstraction (Abstraction): This is a class that contains a reference to an Implementor object
   and defines the high-level interface that the client will use.

4. RefinedAbstraction (Refined Abstraction): This is a class that extends the interface defined
   by Abstraction. It is the 'refined' version of the abstraction that clients call into.

5. Client (Client): The Client interacts with the Abstraction. It doesn't need to know about the
   Implementor interface or the ConcreteImplementor classes, which makes the system easier to
   manage and extend.

The Bridge pattern is especially useful when an abstraction can have multiple implementations,
and it is expected to change or extend independently. It's a way to avoid a proliferation of
classes that would result from an Abstraction having to have a subclass for each possible
implementation variation.
*/


// Implementor - defines the interface for implementation classes
class Implementor {
public:
    virtual void operationImpl() const = 0;
    virtual ~Implementor() {}
};

// ConcreteImplementorA and ConcreteImplementorB - concrete implementation classes
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorA Operation" << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorB Operation" << std::endl;
    }
};

// Abstraction - defines the abstraction's interface
class Abstraction {
protected:
    std::unique_ptr<Implementor> implementor;
public:
    Abstraction(std::unique_ptr<Implementor> impl) : implementor(std::move(impl)) {}
    virtual void operation() const {
        implementor->operationImpl();
    }
    virtual ~Abstraction() {}
};

// RefinedAbstraction - extends the interface defined by Abstraction
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(std::unique_ptr<Implementor> impl) : Abstraction(std::move(impl)) {}
    void operation() const override {
        std::cout << "RefinedAbstraction: ";
        implementor->operationImpl();
    }
};

// Client code
int main() {
    std::unique_ptr<Implementor> implementorA = std::make_unique<ConcreteImplementorA>();
    std::unique_ptr<Abstraction> abstractionA = std::make_unique<RefinedAbstraction>(std::move(implementorA));
    abstractionA->operation();

    std::unique_ptr<Implementor> implementorB = std::make_unique<ConcreteImplementorB>();
    std::unique_ptr<Abstraction> abstractionB = std::make_unique<RefinedAbstraction>(std::move(implementorB));
    abstractionB->operation();

    return 0;
}
