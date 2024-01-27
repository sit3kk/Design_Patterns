#include <iostream>
#include <memory>

/*
The Strategy design pattern defines a family of algorithms, encapsulates each one, and makes them 
interchangeable. Strategy lets the algorithm vary independently from clients that use it.

Key Components:
- Context: The class that uses a Strategy. It maintains a reference to a Strategy object and 
  delegates it to execute an algorithm.
- Strategy: An interface that defines how the algorithm will be executed.
- ConcreteStrategies: Classes implementing the Strategy interface. Each represents a different 
  algorithm or way of doing something.
*/

// 'Strategy' Interface
class Strategy {
public:
    virtual ~Strategy() {}
    virtual void execute() const = 0;
};

// 'ConcreteStrategyA' Class
class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy A." << std::endl;
    }
};

// 'ConcreteStrategyB' Class
class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy B." << std::endl;
    }
};

// 'Context' Class
class Context {
private:
    std::unique_ptr<Strategy> strategy;

public:
    explicit Context(std::unique_ptr<Strategy> strategy) : strategy(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<Strategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    void executeStrategy() const {
        strategy->execute();
    }
};

// Client code
int main() {
    auto context = std::make_unique<Context>(std::make_unique<ConcreteStrategyA>());
    context->executeStrategy(); // Using Strategy A

    context->setStrategy(std::make_unique<ConcreteStrategyB>());
    context->executeStrategy(); // Switched to Strategy B

    return 0;
}
