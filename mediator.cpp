#include <iostream>
#include <string>

/*
The Mediator design pattern is used to reduce the complexity of communication between multiple objects.
It achieves this by introducing a mediator object that takes care of how objects interact with each other.
Instead of objects referring to each other directly, they use the mediator interface.

Key Elements:
- Mediator: An interface that defines how Mediator and Colleagues will communicate.
- ConcreteMediator: Implements the Mediator interface and coordinates communication between Colleague objects.
- Colleague: Objects that communicate with each other through the Mediator interface.
*/

// Forward declaration
class Colleague;

// 'Mediator' Interface
class Mediator {
public:
    virtual void notify(const Colleague* sender, const std::string& event) const = 0;
};

// 'Colleague' Class
class Colleague {
protected:
    Mediator* mediator;

public:
    explicit Colleague(Mediator* mediator) : mediator(mediator) {}
    virtual void doAction() = 0;
};

// 'ConcreteColleagueA' Class
class ConcreteColleagueA : public Colleague {
public:
    using Colleague::Colleague;

    void doAction() override {
        std::cout << "ConcreteColleagueA does action." << std::endl;
        mediator->notify(this, "ActionA");
    }
};

// 'ConcreteColleagueB' Class
class ConcreteColleagueB : public Colleague {
public:
    using Colleague::Colleague;

    void doAction() override {
        std::cout << "ConcreteColleagueB does action." << std::endl;
        mediator->notify(this, "ActionB");
    }
};

// 'ConcreteMediator' Class
class ConcreteMediator : public Mediator {
private:
    ConcreteColleagueA* colleagueA;
    ConcreteColleagueB* colleagueB;

public:
    void setColleagueA(ConcreteColleagueA* a) {
        colleagueA = a;
    }

    void setColleagueB(ConcreteColleagueB* b) {
        colleagueB = b;
    }

    void notify(const Colleague* sender, const std::string& event) const override {
        if (event == "ActionA") {
            std::cout << "Mediator reacts to ActionA and triggers:" << std::endl;
            colleagueB->doAction();
        }
        if (event == "ActionB") {
            std::cout << "Mediator reacts to ActionB and triggers:" << std::endl;
            colleagueA->doAction();
        }
    }
};

// Client code
int main() {
    ConcreteMediator mediator;
    ConcreteColleagueA colleagueA(&mediator);
    ConcreteColleagueB colleagueB(&mediator);

    mediator.setColleagueA(&colleagueA);
    mediator.setColleagueB(&colleagueB);

    std::cout << "Client triggers operation A." << std::endl;
    colleagueA.doAction();

    std::cout << "\nClient triggers operation B." << std::endl;
    colleagueB.doAction();

    return 0;
}
