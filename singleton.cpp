#include <iostream>

/*
The Singleton design pattern ensures that a class has only one instance and provides a global point of access to it.
It is used when exactly one instance of a class is needed to coordinate actions across the system.

Key Aspects:
- Singleton class: The class that has only one instance.
- Global Access: The Singleton class provides a static method to access its unique instance.
- Controlled initialization: The creation of the instance is controlled within the class.
*/

// Singleton Class
class Singleton {
private:
    // The unique instance of Singleton
    static Singleton* instance;

    // Private Constructor to prevent instancing
    Singleton() {}

public:
    // Method to get the unique instance of Singleton
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Example method
    void doSomething() {
        std::cout << "Singleton: Doing something." << std::endl;
    }

    // Prevent copying and assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

// Client code
int main() {
    Singleton* singleton = Singleton::getInstance();
    singleton->doSomething();
    return 0;
}
