#include <iostream>
#include <string>

using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class InsertCommand : public Command {
    string textToInsert;
public:
    InsertCommand(const string& text) : textToInsert(text) {}

    void execute() override {
        cout << "Inserting text: " << textToInsert << endl;
    }

    void undo() override {
        cout << "Undoing insert operation" << endl;
    }    
};

class DeleteCommand : public Command {
    string textToDelete;
public:
    DeleteCommand(const string& text) : textToDelete(text) {}

    void execute() override {
        cout << "Deleting text: " << textToDelete << endl;
    }

    void undo() override {
        cout << "Undoing delete operation" << endl;
    }    
};

class Button {
    Command* command;
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void press() {
        if (command) {
            command->execute();
        }
    }

    void release() {
        if (command) {
            command->undo();
        }
    }
};

int main() {
    Button button;
    Command* insertCommand = new InsertCommand("Hello, ");
    Command* deleteCommand = new DeleteCommand("World!");

    button.setCommand(insertCommand);

    button.press();

    button.release();

    button.setCommand(deleteCommand);

    button.press();

    button.release();

    delete insertCommand;
    delete deleteCommand;

    return 0;
}
