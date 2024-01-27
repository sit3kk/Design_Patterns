#include <iostream>
#include <string>
#include <memory>

/*
The State design pattern allows an object to alter its behavior when its internal state changes.
The object will appear to change its class. It is particularly useful in scenarios where the behavior 
of an object depends on its state, and the number of states and transitions is significant.

Key Components:
- Context: The class that has a state and delegates state-specific behavior to the current State object.
- State: An interface or abstract class defining methods that concrete states must implement.
- Concrete States: Classes that implement specific behaviors associated with different states of the Context.
*/

// Forward declaration
class State;

// 'Context' class
class Context {
    std::unique_ptr<State> state;

public:
    Context(std::unique_ptr<State> state) : state(std::move(state)) {}

    void setState(std::unique_ptr<State> newState) {
        state = std::move(newState);
    }

    void request();
};

// 'State' interface
class State {
public:
    virtual ~State() {}
    virtual void handle(Context& context) = 0;
};

// 'ConcreteStateA' class
class ConcreteStateA : public State {
public:
    void handle(Context& context) override;
};

// 'ConcreteStateB' class
class ConcreteStateB : public State {
public:
    void handle(Context& context) override {
        std::cout << "State B handling context." << std::endl;
        context.setState(std::make_unique<ConcreteStateA>());
    }
};

void ConcreteStateA::handle(Context& context) {
    std::cout << "State A handling context." << std::endl;
    context.setState(std::make_unique<ConcreteStateB>());
}

// Context's request method that delegates to the state
void Context::request() {
    state->handle(*this);
}

// Client code
int main() {
    auto context = std::make_unique<Context>(std::make_unique<ConcreteStateA>());
    context->request(); // Transitions to State B
    context->request(); // Transitions back to State A

    return 0;
}
