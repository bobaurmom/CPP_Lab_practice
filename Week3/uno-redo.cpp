#include <iostream>
#include <string>
using namespace std;

class Command {
public:
    string action;
    Command* next;
    Command* prev;
    
    Command(string a) {
        action = a;
        next = nullptr;
        prev = nullptr;
    }
};

class UndoRedoSystem {
private:
    Command* current;
    
public:
    UndoRedoSystem() {
        current = nullptr;
    }
    
    void execute(string action) {
        Command* newCommand = new Command(action);
        if (current != nullptr) {
            current->next = newCommand;
            newCommand->prev = current;
        }
        current = newCommand;
        cout << "Execute " << action << endl;
    }
    
    void undo() {
        if (current == nullptr) {
            return;
        }
        cout << "Undo " << current->action << endl;
        current = current->prev;
    }
    
    void redo() {
        if (current == nullptr || current->next == nullptr) {
            return;
        }
        current = current->next;
        cout << current->action << endl;
    }
    
    void show() {
        if (current == nullptr) {
            return;
        } else {
            cout << current->action << endl;
        }
    }
};

int main() {
    UndoRedoSystem system;
    
    system.execute("Hello");
    system.execute("hi");
    system.execute("Delete hi");
    system.undo();
    system.undo();
    system.show();
    system.redo();
    system.show();
    
    return 0;
}
