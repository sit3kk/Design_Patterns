#include <iostream>
#include <memory>

/*
The Abstract Factory design pattern is a creational design pattern that provides an interface for 
creating families of related or dependent objects without specifying their concrete classes. It 
allows for the creation of objects that follow a theme and is useful when creating a suite of 
products designed to work together.

Key Elements of the Abstract Factory Pattern:

1. Abstract Factory (Abstract Factory): An interface with methods for creating abstract products. 
   These methods will be implemented by concrete factories to create concrete products.

2. Concrete Factory (Concrete Factory): A class that implements the Abstract Factory interface to 
   create concrete products. Each concrete factory corresponds to a specific "variant" or "family" 
   of products.

3. Abstract Product (Abstract Product): An interface for a kind of product with methods that all 
   objects of that product kind must implement.

4. Concrete Product (Concrete Product): Classes that implement the Abstract Product interface to 
   define product objects that will be created by the corresponding Concrete Factory.

5. Client (Client): The part of the application that calls the Abstract Factory methods to create 
   and use the abstract products. The client only deals with the interfaces provided by the Abstract 
   Factory and Abstract Products.

This pattern is particularly useful when a system needs to be independent from how its products 
are created, composed, and represented, and when the family of products is designed to be used 
together.
*/




// Abstract Product A
class AbstractProductA {
public:
    virtual void display() const = 0;
    virtual ~AbstractProductA() {}
};

// Abstract Product B
class AbstractProductB {
public:
    virtual void display() const = 0;
    virtual ~AbstractProductB() {}
};

// Concrete Product A1
class ProductA1 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "ProductA1 displayed." << std::endl;
    }
};

// Concrete Product A2
class ProductA2 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "ProductA2 displayed." << std::endl;
    }
};

// Concrete Product B1
class ProductB1 : public AbstractProductB {
public:
    void display() const override {
        std::cout << "ProductB1 displayed." << std::endl;
    }
};

// Concrete Product B2
class ProductB2 : public AbstractProductB {
public:
    void display() const override {
        std::cout << "ProductB2 displayed." << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
    virtual ~AbstractFactory() {}
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ProductA1>();
    }
    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ProductB1>();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ProductA2>();
    }
    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ProductB2>();
    }
};

// Client code
void client(const AbstractFactory& factory) {
    auto productA = factory.createProductA();
    auto productB = factory.createProductB();

    productA->display();
    productB->display();
}

int main() {
    ConcreteFactory1 factory1;
    ConcreteFactory2 factory2;

    std::cout << "Factory 1:" << std::endl;
    client(factory1);

    std::cout << "Factory 2:" << std::endl;
    client(factory2);

    return 0;
}
