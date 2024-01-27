#include <iostream>
#include <memory>
#include <vector>

/*
The Command design pattern encapsulates a request as an object, thereby allowing for parameterization 
of clients with queues, requests, and operations. It also allows for the support of undoable operations.
The pattern decouples the object that invokes the operation from the object that knows how to perform it.

Key Elements:
- Command: An interface for executing an operation.
- ConcreteCommand: Extends the Command interface, implementing the execute method by invoking the 
  corresponding operation(s) on Receiver.
- Receiver: The object that performs the actual action when the command's execute() method is called.
- Invoker: Sends a command to its receiver to perform an action.
- Client: Creates a ConcreteCommand object and sets its receiver.
*/

// The 'Command' abstract class
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

// The 'ConcreteCommand' class
class ConcreteCommand : public Command {
private:
    std::string payload;

public:
    explicit ConcreteCommand(std::string payload) : payload(payload) {}

    void execute() override {
        std::cout << "ConcreteCommand: Processing command with payload: " << payload << std::endl;
    }
};

// The 'Receiver' class
class Receiver {
public:
    void performAction(const std::string& payload) {
        std::cout << "Receiver: Performing action with " << payload << std::endl;
    }
};

// The 'Invoker' class, which sends a command
class Invoker {
private:
    std::vector<std::shared_ptr<Command>> commands;

public:
    void addCommand(const std::shared_ptr<Command>& command) {
        commands.push_back(command);
    }

    void executeCommands() {
        for (const auto& command : commands) {
            command->execute();
        }
        commands.clear();
    }
};

// Client code
int main() {
    auto receiver = std::make_shared<Receiver>();
    auto command1 = std::make_shared<ConcreteCommand>("First");
    auto command2 = std::make_shared<ConcreteCommand>("Second");

    Invoker invoker;
    invoker.addCommand(command1);
    invoker.addCommand(command2);
    invoker.executeCommands();

    return 0;
}
