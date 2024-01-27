#include <iostream>
#include <memory>
#include <string>

/*
The Decorator design pattern dynamically adds additional responsibilities to an object. It provides a 
flexible alternative to subclassing for extending functionality.

Key Elements:
- Component: Defines the interface for objects that can have responsibilities added to them dynamically.
- ConcreteComponent: Defines an object to which additional responsibilities can be attached.
- Decorator: Maintains a reference to a Component object and defines an interface that conforms to 
  Component's interface.
- ConcreteDecorator: Adds responsibilities to the component.
*/

// 'Component' Interface
class Component {
public:
    virtual ~Component() {}
    virtual std::string operation() const = 0;
};

// 'ConcreteComponent' Class
class ConcreteComponent : public Component {
public:
    std::string operation() const override {
        return "ConcreteComponent";
    }
};

// 'Decorator' Abstract Class
class Decorator : public Component {
protected:
    std::shared_ptr<Component> component;
public:
    Decorator(std::shared_ptr<Component> component) : component(component) {}
    std::string operation() const override {
        return component->operation();
    }
};

// 'ConcreteDecoratorA' Class
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(std::shared_ptr<Component> component) : Decorator(component) {}

    std::string operation() const override {
        return "ConcreteDecoratorA(" + Decorator::operation() + ")";
    }
};

// 'ConcreteDecoratorB' Class
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(std::shared_ptr<Component> component) : Decorator(component) {}

    std::string operation() const override {
        return "ConcreteDecoratorB(" + Decorator::operation() + ")";
    }
};

// Client code
int main() {
    auto simple = std::make_shared<ConcreteComponent>();
    std::cout << "Client: I've got a simple component:\n";
    std::cout << "RESULT: " << simple->operation();
    std::cout << "\n\n";

    // Decorators can wrap simple components...
    auto decorator1 = std::make_shared<ConcreteDecoratorA>(simple);
    auto decorator2 = std::make_shared<ConcreteDecoratorB>(decorator1);
    std::cout << "Client: Now I've got a decorated component:\n";
    std::cout << "RESULT: " << decorator2->operation();
    std::cout << "\n";

    return 0;
}
