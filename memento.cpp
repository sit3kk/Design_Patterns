#include <iostream>
#include <string>
#include <vector>

// Memento - stores the state of the Originator
class Memento {
private:
    std::string state;

public:
    Memento(const std::string &state) : state(state) {}

    std::string getState() const {
        return state;
    }
};

// Originator - class whose state is saved
class Editor {
private:
    std::string content;

public:
    void type(const std::string &words) {
        content += words;
    }

    Memento save() {
        return Memento(content);
    }

    void restore(const Memento &memento) {
        content = memento.getState();
    }

    std::string getContent() const {
        return content;
    }
};

// Caretaker - manages saved states
class Caretaker {
private:
    std::vector<Memento> mementos;

public:
    void saveState(Editor &editor) {
        mementos.push_back(editor.save());
    }

    void restoreState(Editor &editor, int index) {
        if (index < mementos.size()) {
            editor.restore(mementos[index]);
        }
    }
};

int main() {
    Editor editor;
    Caretaker caretaker;

    editor.type("First line of text.");
    caretaker.saveState(editor);

    editor.type(" Second line of text.");
    caretaker.saveState(editor);

    editor.type(" Third line of text.");

    // Restore to the first saved state
    caretaker.restoreState(editor, 0);
    std::cout << "Current state of editor: " << editor.getContent() << std::endl;

    return 0;
}
