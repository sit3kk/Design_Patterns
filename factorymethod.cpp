#include <iostream>
#include <memory>

/*
The Factory Method design pattern defines an interface for creating an object, but lets subclasses 
alter the type of objects that will be created. This pattern is used to delegate the responsibility 
of object instantiation to subclasses.

Key Elements of the Factory Method Pattern:
- Product: Defines the interface of objects the factory method creates.
- ConcreteProduct: Implements the Product interface.
- Creator: Declares the factory method, which returns an object of type Product.
- ConcreteCreator: Overrides the factory method to return an instance of a ConcreteProduct.
*/

// 'Product' Interface
class Product {
public:
    virtual ~Product() {}
    virtual std::string operation() const = 0;
};

// 'ConcreteProduct' Class
class ConcreteProduct : public Product {
public:
    std::string operation() const override {
        return "ConcreteProduct";
    }
};

// 'Creator' Abstract Class
class Creator {
public:
    virtual ~Creator() {}
    virtual std::shared_ptr<Product> factoryMethod() const = 0;

    std::string someOperation() const {
        // Call the factory method to create a Product object.
        std::shared_ptr<Product> product = factoryMethod();
        // Now, use the product.
        return "Creator: The same creator's code has just worked with " + product->operation();
    }
};

// 'ConcreteCreator' Class
class ConcreteCreator : public Creator {
public:
    std::shared_ptr<Product> factoryMethod() const override {
        return std::make_shared<ConcreteProduct>();
    }
};

// Client code
void clientCode(const Creator& creator) {
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n" 
              << creator.someOperation() << std::endl;
}

int main() {
    std::cout << "App: Launched with the ConcreteCreator.\n";
    ConcreteCreator creator;
    clientCode(creator);
    return 0;
}
