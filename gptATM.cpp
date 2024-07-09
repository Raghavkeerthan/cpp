#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class ATM {
private:
    unordered_map<string, string> users; // Stores user credentials
    unordered_map<string, double> balances; // Stores user balances
    string currentUser;

    bool authenticateUser(const string& username, const string& password) {
        if (users.find(username) != users.end() && users[username] == password) {
            currentUser = username;
            return true;
        }
        return false;
    }

public:
    ATM() {
        // Adding some users for testing purposes
        users["user1"] = "password1";
        users["user2"] = "password2";
        balances["user1"] = 1000.0;
        balances["user2"] = 2000.0;
    }

    void displayMenu() {
        cout << "\nATM Menu\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
    }

    void checkBalance() {
        cout << "Current Balance: $" << balances[currentUser] << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            balances[currentUser] += amount;
            cout << "Deposit successful. New Balance: $" << balances[currentUser] << endl;
        } else {
            cout << "Invalid amount." << endl;
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && amount <= balances[currentUser]) {
            balances[currentUser] -= amount;
            cout << "Withdrawal successful. New Balance: $" << balances[currentUser] << endl;
        } else {
            cout << "Invalid amount or insufficient funds." << endl;
        }
    }

    void run() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (authenticateUser(username, password)) {
            int choice;
            do {
                displayMenu();
                cin >> choice;
                switch (choice) {
                    case 1:
                        checkBalance();
                        break;
                    case 2:
                        deposit();
                        break;
                    case 3:
                        withdraw();
                        break;
                    case 4:
                        cout << "Exiting...\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                }
            } while (choice != 4);
        } else {
            cout << "Authentication failed. Please try again.\n";
        }
    }
};

int main() {
    ATM atm;
    atm.run();
    return 0;
}
