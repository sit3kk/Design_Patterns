#include <iostream>
#include <list>
#include <string>

// Observer interface
class Observer {
public:
    virtual void update(const std::string &message) = 0;
    virtual ~Observer() {}
};

// Subject
class Subject {
private:
    std::list<Observer*> observers;
    std::string message;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.remove(observer);
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }

    void createMessage(const std::string &message) {
        this->message = message;
        notify();
    }
};

// Concrete Observer
class ConcreteObserver : public Observer {
private:
    std::string name;
    Subject &subject;

public:
    ConcreteObserver(std::string name, Subject &subject) : name(std::move(name)), subject(subject) {
        this->subject.attach(this);
    }

    void update(const std::string &message) override {
        std::cout << name << " received message: " << message << std::endl;
    }

    ~ConcreteObserver() {
        subject.detach(this);
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer1("Observer1", subject);
    ConcreteObserver observer2("Observer2", subject);

    subject.createMessage("Hello World!");  // Notify all observers

    return 0;
}
