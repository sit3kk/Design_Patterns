#include <iostream>
#include <string>

// Model
class User {
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

// View
class UserView {
public:
    void printUserDetails(const std::string &userName) {
        std::cout << "User: " << userName << std::endl;
    }
};

// Controller
class UserController {
private:
    User model;
    UserView view;

public:
    UserController(const User &model, const UserView &view) : model(model), view(view) {}

    void setUserName(const std::string &name) {
        model.setName(name);
    }

    std::string getUserName() const {
        return model.getName();
    }

    void updateView() {
        view.printUserDetails(model.getName());
    }
};

int main() {

    User user;
    user.setName("Konrad");
    UserView view;

 
    UserController controller(user, view);

    
    controller.updateView();

    controller.setUserName("New Konrad");
    controller.updateView();

    return 0;
}
