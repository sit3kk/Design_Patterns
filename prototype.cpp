#include <iostream>
#include <string>
#include <memory>

// Prototype
class Car {
public:
    virtual std::unique_ptr<Car> clone() = 0;
    virtual void printDetails() const = 0;
    virtual ~Car() {}
};

// Concrete Prototype
class Ford : public Car {
private:
    std::string model;

public:
    Ford(std::string model) : model(std::move(model)) {}

    std::unique_ptr<Car> clone() override {
        return std::make_unique<Ford>(*this);
    }

    void printDetails() const override {
        std::cout << "Ford, model: " << model << std::endl;
    }
};

int main() {
    std::unique_ptr<Car> ford = std::make_unique<Ford>("Mustang");
    ford->printDetails();

    // Clone Ford
    std::unique_ptr<Car> clonedFord = ford->clone();
    clonedFord->printDetails();

    return 0;
}
