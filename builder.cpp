#include <iostream>
#include <string>
#include <memory>

/*
The Builder design pattern is a creational pattern used to construct a complex object step by step. 
The construction process can create different representations of the object depending on the specific 
needs of the program. The pattern encapsulates the construction logic of complex objects in its own 
class, separate from the object's class, enabling fine control over the construction process.

Key Elements of the Builder Pattern:

1. Builder (Builder): This is an interface that defines all the steps needed to build a complex object.
   Builders provide specific methods for each part of the object being constructed, allowing for 
   customization at each step of the building process.

2. Concrete Builder (Concrete Builder): Implements the Builder interface and provides an implementation 
   for the steps defined by the Builder. Each Concrete Builder corresponds to a different representation 
   of the complex object and provides specific logic to handle each construction step.

3. Director (Director): This class is responsible for managing the correct sequence of construction steps. 
   The Director receives a Builder instance that the client wishes to use and executes the necessary steps 
   to produce an object with the Builder.

4. Product (Product): This is the complex object that is being constructed. The Product is independent of 
   the building process, and multiple representations can be created using different Concrete Builders.

5. Client (Client): The Client creates a Concrete Builder object and passes it to the Director to construct 
   the Product. The client retrieves the Product from the builder once the Director has finished executing 
   the building steps.

The Builder pattern is beneficial when an object must be created in multiple steps, or when the construction 
process must be separated from the representation of the complex object for reasons of modularity or 
single-responsibility principle.
*/


// The 'Product' class
class Car {
public:
    std::string seats;
    std::string engine;
    std::string tripComputer;
    std::string gps;

    void specifications() const {
        std::cout << "Car built with: " << seats << " seats, " << engine
                  << " engine, Trip Computer: " << tripComputer
                  << ", GPS: " << gps << std::endl;
    }
};

// The 'Builder' abstract class
class CarBuilder {
public:
    virtual ~CarBuilder() {}
    virtual void buildSeats() = 0;
    virtual void buildEngine() = 0;
    virtual void buildTripComputer() = 0;
    virtual void buildGPS() = 0;
    virtual Car getCar() = 0;
};

// The 'ConcreteBuilder' class
class ConcreteCarBuilder : public CarBuilder {
private:
    Car car;

public:
    void buildSeats() override {
        car.seats = "Leather";
    }

    void buildEngine() override {
        car.engine = "V8";
    }

    void buildTripComputer() override {
        car.tripComputer = "High-end";
    }

    void buildGPS() override {
        car.gps = "Built-in";
    }

    Car getCar() override {
        return car;
    }
};

// The 'Director' class
class Director {
public:
    void constructSportsCar(CarBuilder& builder) {
        builder.buildSeats();
        builder.buildEngine();
        builder.buildTripComputer();
        builder.buildGPS();
    }
};

// Client code
int main() {
    Director director;
    ConcreteCarBuilder builder;
    director.constructSportsCar(builder);
    
    Car car = builder.getCar();
    car.specifications();
    
    return 0;
}
