#include <iostream>

/*
The Visitor design pattern is a way of separating an algorithm from an object structure it operates on.
It allows adding new operations to existing object structures without modifying them.

Key Components:
- Visitor: An interface or abstract class declaring the visit methods for each type of element.
- Concrete Visitors: Implement the Visitor interface and define the operations to be performed on elements.
- Elements: Classes of objects that are visited. They have an accept method that takes a visitor.
- Accept: A method in elements that accepts a visitor and calls the appropriate visit method.
*/

// Forward declaration of element classes
class ConcreteElementA;
class ConcreteElementB;

// 'Visitor' Interface
class Visitor {
public:
    virtual void visitElementA(ConcreteElementA* element) = 0;
    virtual void visitElementB(ConcreteElementB* element) = 0;
    virtual ~Visitor() {}
};

// 'Concrete Elements' Classes
class ConcreteElementA {
public:
    void accept(Visitor* visitor) {
        visitor->visitElementA(this);
    }
    void operationA() {
        std::cout << "ConcreteElementA Operation." << std::endl;
    }
};

class ConcreteElementB {
public:
    void accept(Visitor* visitor) {
        visitor->visitElementB(this);
    }
    void operationB() {
        std::cout << "ConcreteElementB Operation." << std::endl;
    }
};

// 'Concrete Visitor' Class
class ConcreteVisitor : public Visitor {
public:
    void visitElementA(ConcreteElementA* element) override {
        std::cout << "Visitor processing ConcreteElementA." << std::endl;
        element->operationA();
    }

    void visitElementB(ConcreteElementB* element) override {
        std::cout << "Visitor processing ConcreteElementB." << std::endl;
        element->operationB();
    }
};

// Client code
int main() {
    ConcreteElementA elementA;
    ConcreteElementB elementB;
    ConcreteVisitor visitor;

    elementA.accept(&visitor);
    elementB.accept(&visitor);

    return 0;
}
