#include <iostream>
using namespace std;

// Function to authenticate the user
bool authenticate(int pin) {
    // Default pin is 0000
    int default_pin = 0000;
    // If the entered pin matches the default pin
    if (pin == default_pin) {
        return true;
    }
    else {
        return false;
    }
}

// Function to reset/change the pin
void reset_pin(int& pin) {
    // Ask the user to enter a new pin
    int new_pin;
    cout << "**************************\n";
    cout << "***Enter new pin:.....";
    cin >> new_pin;
    // Set the new pin
    cout << "***                    ***\n";
    pin = new_pin;
    cout << "***Pin has been reset. ***\n";
    cout << "**************************\n";
}

// Function to check balance
void check_balance(int balance) {
    cout << "Your balance is: " << balance << endl;
}

// Function to send money
void send_money(int& balance) {
    // Ask the user to enter the amount to send
    int amount;
    cout << "Enter amount to send: ";
    cin >> amount;
    // Check if the balance is enough for the transaction
    if (balance >= amount) {
        // Deduct the amount from the balance
        balance -= amount;
        cout << "Transaction successful. Amount sent: " << amount << endl;
        cout << "New balance: " << balance << endl;
    }
    else {
        cout << "Transaction failed. Insufficient balance.\n";
    }
}

int main() {
    // Default balance is 1,000
    int balance = 1000;
    int pin, wrong_entries = 0;

    // Loop until the user chooses to exit
    while (true) {
        // Ask the user to enter the pin
        cout << "Enter pin: ";
        cin >> pin;
        // If the pin is correct
        if (authenticate(pin)) {
            // Reset the number of wrong entries
            wrong_entries = 0;
            // Display the menu
            cout << "********WELCOME TO CONSTANCE MOMO PROJECT*********\n";
            cout << "***                                            ***\n";
            cout << "***      1. Reset/change pin                   ***\n";
            cout << "***      2. Check balance                      ***\n";
            cout << "***      3. Send money                         ***\n";
            cout << "***      4. Exit                               ***\n";
            cout << "***                                            ***\n";
            cout << "**************************************************\n\n";
            // Ask the user to choose an option
            int option;
            cout << "Enter option: ";
            cin >> option;
            // Process the chosen option
            switch (option) {
                case 1:
                    reset_pin(pin);
                    break;
                case 2:
                    check_balance(balance);
                    break;
                case 3:
                    send_money(balance);
                    break;
                case 4:
                    // Exit the program
                    return 0;
                default:
                    cout << "Invalid option.\n";
            }
        }
        else {
            // Increment the number of wrong entries
            wrong_entries++;
            // If the number of wrong entries is 3, exit the program
            if (wrong_entries == 3) {
                cout << "Too many wrong entries. Exiting...\n";
                return 0;
            }
            cout << "Wrong pin. Try again.\n";
        }
    }
}
