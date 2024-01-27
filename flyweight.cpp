#include <iostream>
#include <map>
#include <string>
#include <memory>

/*
The Flyweight design pattern is used to reduce the memory and resource usage for large numbers 
of similar objects. It achieves this by sharing as much data as possible with related objects; 
it is a way to use objects in large numbers when a simple repeated representation would use 
an unacceptable amount of memory.

Key Elements of the Flyweight Pattern:
- Flyweight: The interface through which flyweights can receive and act on extrinsic state.
- ConcreteFlyweight: Implements the Flyweight interface and stores intrinsic state. Intrinsic 
  state is state that is shared and does not change.
- FlyweightFactory: Creates and manages flyweight objects. It ensures that flyweights are shared 
  properly. When the client requests a flyweight, the factory either returns an existing instance 
  or creates a new one, if it doesn't exist.
- Client: Maintains a reference to flyweights and computes or stores the extrinsic state of the 
  flyweights.
*/

// 'Flyweight' Interface
class Flyweight {
public:
    virtual ~Flyweight() {}
    virtual void operation(const std::string& extrinsicState) const = 0;
};

// 'ConcreteFlyweight' Class
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState;

public:
    explicit ConcreteFlyweight(const std::string& intrinsicState)
        : intrinsicState(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "ConcreteFlyweight: IntrinsicState - " << intrinsicState
                  << ", ExtrinsicState - " << extrinsicState << std::endl;
    }
};

// 'FlyweightFactory' Class
class FlyweightFactory {
private:
    std::map<std::string, std::shared_ptr<Flyweight>> flyweights;

public:
    FlyweightFactory(std::initializer_list<std::string> intrinsicStates) {
        for (const std::string& state : intrinsicStates) {
            flyweights[state] = std::make_shared<ConcreteFlyweight>(state);
        }
    }

    std::shared_ptr<Flyweight> getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            std::cout << "FlyweightFactory: Can't find a flyweight, creating new one." << std::endl;
            flyweights[key] = std::make_shared<ConcreteFlyweight>(key);
        }
        return flyweights[key];
    }
};

// Client code
int main() {
    FlyweightFactory factory({"one", "two", "three"});

    factory.getFlyweight("one")->operation("Operation1");
    factory.getFlyweight("two")->operation("Operation2");

    // Unshared flyweight
    factory.getFlyweight("four")->operation("Operation4");

    return 0;
}
