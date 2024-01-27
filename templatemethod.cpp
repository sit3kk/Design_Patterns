#include <iostream>

/*
The Template Method design pattern defines the skeleton of an algorithm in a base class method but 
lets derived classes override specific steps of the algorithm without changing its structure.

Key Components:
- Abstract Class: Contains the template method and abstract definitions of operations used in the 
  template method.
- Template Method: A method in the abstract class that defines the skeleton of an algorithm. It 
  calls abstract operations as well as operations defined in the abstract class or those overridden 
  by concrete classes.
- Concrete Classes: Classes that inherit from the abstract class and implement its abstract operations.
*/

// 'AbstractClass' with the Template Method
class AbstractClass {
protected:
    virtual void requiredOperation1() const = 0;
    virtual void requiredOperation2() const = 0;

    virtual void hook1() const {}
    virtual void hook2() const {}

public:
    // The Template Method
    void templateMethod() const {
        this->requiredOperation1();
        this->hook1();
        this->requiredOperation2();
        this->hook2();
    }
};

// 'ConcreteClass1' implementing the AbstractClass
class ConcreteClass1 : public AbstractClass {
protected:
    void requiredOperation1() const override {
        std::cout << "ConcreteClass1 says: Implemented Operation1" << std::endl;
    }
    void requiredOperation2() const override {
        std::cout << "ConcreteClass1 says: Implemented Operation2" << std::endl;
    }
};

// 'ConcreteClass2' implementing the AbstractClass
class ConcreteClass2 : public AbstractClass {
protected:
    void requiredOperation1() const override {
        std::cout << "ConcreteClass2 says: Implemented Operation1" << std::endl;
    }
    void requiredOperation2() const override {
        std::cout << "ConcreteClass2 says: Implemented Operation2" << std::endl;
    }
    void hook1() const override {
        std::cout << "ConcreteClass2 says: Overridden Hook1" << std::endl;
    }
};

// Client code
int main() {
    std::cout << "Same client code can work with different subclasses:" << std::endl;
    ConcreteClass1 concreteClass1;
    concreteClass1.templateMethod();

    std::cout << "\nSame client code can work with different subclasses:" << std::endl;
    ConcreteClass2 concreteClass2;
    concreteClass2.templateMethod();
    return 0;
}
