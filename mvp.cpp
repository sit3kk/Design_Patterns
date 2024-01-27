#include <iostream>
#include <string>

// Forward declaration of UserPresenter
class UserPresenter;

// Model
class UserModel {
private:
    std::string name;

public:
    void setName(const std::string &name) {
        this->name = name;
    }

    std::string getName() const {
        return name;
    }
};

// View Interface
class UserView {
public:
    virtual void displayUserName(const std::string &name) = 0;
    virtual void setPresenter(UserPresenter* presenter) = 0;
    virtual ~UserView() {}
};

// Presenter
class UserPresenter {
private:
    UserModel model;
    UserView* view;

public:
    UserPresenter(UserModel model, UserView* view) : model(model), view(view) {
        this->view->setPresenter(this);
    }

    void updateUserName(const std::string &newName) {
        model.setName(newName);
        view->displayUserName(model.getName());
    }

    void onUserNameChanged(const std::string &newName) {
        model.setName(newName);
        view->displayUserName(model.getName());
    }
};

// Concrete View
class ConsoleUserView : public UserView {
private:
    UserPresenter* presenter;

public:
    void displayUserName(const std::string &name) override {
        std::cout << "User's name is: " << name << std::endl;
    }

    void setPresenter(UserPresenter* presenter) override {
        this->presenter = presenter;
    }

    // Simulate user input
    void simulateUserInput() {
        std::string newName;
        std::cout << "Enter new user name: ";
        std::cin >> newName;
        presenter->onUserNameChanged(newName);
    }
};

int main() {
    // Model and view setup
    UserModel model;
    model.setName("Konrad");
    ConsoleUserView view;

    // Create presenter
    UserPresenter presenter(model, &view);

    // Simulate user interaction
    view.simulateUserInput();

    return 0;
}
