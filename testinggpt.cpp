#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

// Forward declaration of classes
class Room;
class Player;

// Object class for items in rooms
class Object {
private:
    string name;
    string description;

public:
    Object(const string& n, const string& desc) : name(n), description(desc) {}

    string getName() const { return name; }
    string getDescription() const { return description; }
};

// Base class for different types of rooms
class Room {
protected:
    string name;
    string description;
    map<string, Object> objects; // Objects present in the room

public:
    Room(const string& n, const string& desc) : name(n), description(desc) {}

    string getName() const { return name; }
    string getDescription() const { return description; }

    void addObject(const string& objName, const string& objDesc) {
        objects[objName] = Object(objName, objDesc); // Using Object constructor with parameters
    }

    bool removeObject(const string& objName) {
        auto it = objects.find(objName);
        if (it != objects.end()) {
            objects.erase(it);
            return true;
        }
        return false;
    }

    Object* getObject(const string& objName) {
        auto it = objects.find(objName);
        if (it != objects.end()) {
            return &(it->second);
        }
        return nullptr;
    }

    virtual void describe() const {
        cout << "You are in " << name << ". " << description << endl;
        cout << "You see: ";
        if (objects.empty()) {
            cout << "nothing of interest." << endl;
        } else {
            for (const auto& obj : objects) {
                cout << obj.first << " ";
            }
            cout << endl;
        }
    }

    virtual void interact(Player& player) = 0; // Pure virtual function
};

// Derived class for a puzzle room
class PuzzleRoom : public Room {
private:
    bool solved;

public:
    PuzzleRoom(const string& n, const string& desc) : Room(n, desc), solved(false) {}

    void describe() const override {
        Room::describe();
        if (!solved) {
            cout << "There is a puzzle here. Solve it to proceed." << endl;
        } else {
            cout << "The puzzle has been solved." << endl;
        }
    }

    void interact(Player& player) override {
        if (!solved) {
            cout << "You attempt to solve the puzzle..." << endl;
            // Simplified logic for puzzle solving (random chance)
            if (rand() % 2 == 0) {
                cout << "You solved the puzzle!" << endl;
                solved = true;
            } else {
                cout << "The puzzle remains unsolved." << endl;
            }
        } else {
            cout << "The puzzle has already been solved." << endl;
        }
    }
};

// Derived class for a combat room
class CombatRoom : public Room {
private:
    bool cleared;

public:
    CombatRoom(const string& n, const string& desc) : Room(n, desc), cleared(false) {}

    void describe() const override {
        Room::describe();
        if (!cleared) {
            cout << "There is a monster here. Defeat it to proceed." << endl;
        } else {
            cout << "The monster has been defeated." << endl;
        }
    }

    void interact(Player& player) override {
        if (!cleared) {
            cout << "A wild monster attacks you!" << endl;
            // Simplified combat logic (random chance)
            if (rand() % 2 == 0) {
                cout << "You defeated the monster!" << endl;
                cleared = true;
            } else {
                cout << "You were defeated by the monster." << endl;
                // Handle player defeat (e.g., reset game)
            }
        } else {
            cout << "The room is already cleared." << endl;
        }
    }
};

// Player class to manage player state and actions
class Player {
private:
    string name;
    Room* currentRoom;
    vector<Object> inventory;

public:
    Player(const string& n) : name(n), currentRoom(nullptr) {}

    string getName() const { return name; }
    Room* getCurrentRoom() const { return currentRoom; }

    void setCurrentRoom(Room* room) { currentRoom = room; }

    void describeCurrentRoom() const {
        if (currentRoom != nullptr) {
            currentRoom->describe();
        } else {
            cout << "You are not in any room." << endl;
        }
    }

    void takeObject(const string& objName) {
        if (currentRoom != nullptr) {
            Object* obj = currentRoom->getObject(objName);
            if (obj != nullptr) {
                inventory.push_back(*obj);
                cout << "You took the " << objName << "." << endl;
                currentRoom->removeObject(objName);
            } else {
                cout << "There is no " << objName << " to take." << endl;
            }
        }
    }

    void useObject(const string& objName) {
        // Simplified implementation: just display a message for now
        cout << "You used the " << objName << "." << endl;
    }

    void showInventory() const {
        cout << "Inventory: ";
        if (inventory.empty()) {
            cout << "empty" << endl;
        } else {
            for (const auto& obj : inventory) {
                cout << obj.getName() << " ";
            }
            cout << endl;
        }
    }
};

// Function to handle game loop
void playGame(Player& player) {
    cout << "Welcome to The Lost Realm!" << endl;
    cout << "Enter commands to navigate and interact with the environment." << endl;

    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generator

    // Example rooms creation
    Room* room1 = new PuzzleRoom("Puzzle Room", "A room filled with mysterious symbols.");
    room1->addObject("Puzzle Box", "A wooden box with strange engravings.");
    Room* room2 = new CombatRoom("Combat Room", "A dark room with a fearsome creature lurking.");
    room2->addObject("Sword", "A sharp sword lying on the ground.");

    // Connect rooms (simplified - direct connections)
    player.setCurrentRoom(room1); // Player starts in the first room

    // Game loop
    bool gameOver = false;
    while (!gameOver) {
        player.describeCurrentRoom();

        // Player input handling
        string input;
        cout << "Enter a command ('help' for list of commands, 'quit' to exit): ";
        getline(cin, input);

        if (input == "quit") {
            gameOver = true;
            cout << "Thanks for playing!" << endl;
        } else if (input == "help") {
            cout << "Available commands: " << endl;
            cout << "  look         - Describe the current room" << endl;
            cout << "  take [item]  - Take an item from the room" << endl;
            cout << "  use [item]   - Use an item from your inventory" << endl;
            cout << "  inventory    - Show your current inventory" << endl;
            cout << "  quit         - Exit the game" << endl;
        } else if (input == "look") {
            player.describeCurrentRoom();
        } else if (input.substr(0, 4) == "take") {
            string objName = input.substr(5);
            player.takeObject(objName);
        } else if (input.substr(0, 3) == "use") {
            string objName = input.substr(4);
            player.useObject(objName);
        } else if (input == "inventory") {
            player.showInventory();
        } else {
            cout << "Invalid command. Type 'help' for list of commands." << endl;
        }
    }

    // Clean up
    delete room1;
    delete room2;
}

int main() {
    // Initialize player
    Player player("Adventurer");

    // Start the game
    playGame(player);

    return 0;
}









