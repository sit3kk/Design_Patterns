#include <iostream>
#include <string>

// Data Access Layer
// This layer is responsible for communicating with data storage systems (e.g., databases, file systems).
class DataAccess {
public:
    // Simulates fetching data from a data source.
    std::string fetchData() {
        return "Data from database";
    }
};

// Business Logic Layer
// This layer handles the core business logic of the application. It processes data fetched from the Data Access Layer.
class BusinessLogic {
    DataAccess dataAccess;

public:
    // Processes data obtained from the Data Access Layer.
    std::string processData() {
        std::string data = dataAccess.fetchData();
        return "Processed " + data;  // Simulate data processing
    }
};

// Presentation Layer
// This layer is responsible for presenting information to the user and interpreting user commands.
class Presentation {
    BusinessLogic businessLogic;

public:
    // Displays data to the user. In a real-world application, this could be a GUI.
    void display() {
        std::string result = businessLogic.processData();
        std::cout << "Result: " << result << std::endl;
    }
};

// Client code
int main() {
    // The client interacts with the Presentation Layer.
    Presentation presentation;
    presentation.display();
    return 0;
}
