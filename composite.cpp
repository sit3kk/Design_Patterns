#include <iostream>
#include <vector>
#include <memory>
#include <string>

/*
The Composite design pattern is used to treat individual objects and compositions of objects 
uniformly. It allows clients to treat individual objects and compositions of objects in the same way.

Key Elements of the Composite Pattern:
- Component: An interface for all objects in the composition, both composite and leaf nodes.
- Leaf: Represents leaf objects in the composition. A leaf has no children.
- Composite: Defines behavior for components having children and stores child components.
- Client: Manipulates objects in the composition through the Component interface.
*/

// The 'Component' class
class Component {
protected:
    std::string name;

public:
    explicit Component(std::string name) : name(std::move(name)) {}
    virtual ~Component() {}

    virtual void add(std::shared_ptr<Component> component) {}
    virtual void remove(std::shared_ptr<Component> component) {}
    virtual void display(int depth) const = 0;
};

// The 'Leaf' class 
class Leaf : public Component {
public:
    using Component::Component;

    void display(int depth) const override {
        std::cout << std::string(depth, '-') << name << std::endl;
    }
};

// The 'Composite' class
class Composite : public Component {
private:
    std::vector<std::shared_ptr<Component>> children;

public:
    using Component::Component;

    void add(std::shared_ptr<Component> component) override {
        children.push_back(component);
    }

    void remove(std::shared_ptr<Component> component) override {
        // Code to remove the component from the children
    }

    void display(int depth) const override {
        std::cout << std::string(depth, '+') << name << std::endl;
        for (const auto& child : children) {
            child->display(depth + 2);
        }
    }
};

// Client code
int main() {
    auto root = std::make_shared<Composite>("root");
    auto root2 = std::make_shared<Composite>("root2");
    root2->add(std::make_shared<Leaf>("Leaf root2A"));
    root->add(root2);
    root->add(std::make_shared<Leaf>("Leaf A"));
    root->add(std::make_shared<Leaf>("Leaf B"));

    auto comp = std::make_shared<Composite>("Composite X");
    comp->add(std::make_shared<Leaf>("Leaf XA"));
    comp->add(std::make_shared<Leaf>("Leaf XB"));

    root->add(comp);
    root->add(std::make_shared<Leaf>("Leaf C"));

    auto leaf = std::make_shared<Leaf>("Leaf D");
    root->add(leaf);
    root->remove(leaf);

    root->display(1);

    return 0;
}
