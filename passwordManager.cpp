#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Define a structure for password entries
struct PasswordEntry {
    string website;
    string username;
    string password;
};

// Function to save password entries to a file
void saveEntries(const vector<PasswordEntry>& entries, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const PasswordEntry& entry : entries) {
            file << entry.website << "," << entry.username << "," << entry.password << endl;
        }
        file.close();
        cout << "Entries saved successfully." << endl;
    } else {
        cerr << "Error: Unable to save entries to file." << endl;
    }
}

// Function to load password entries from a file
void loadEntries(vector<PasswordEntry>& entries, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        entries.clear(); // Clear the existing entries
        string line;
        while (getline(file, line)) {
            PasswordEntry entry;
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);
            entry.website = line.substr(0, pos1);
            entry.username = line.substr(pos1 + 1, pos2 - pos1 - 1);
            entry.password = line.substr(pos2 + 1);
            entries.push_back(entry);
        }
        file.close();
        cout << "Entries loaded successfully." << endl;
    } else {
        cerr << "Error: Unable to load entries from file." << endl;
    }
}

int main() {
    vector<PasswordEntry> passwordEntries;
    string filename = "passwords.txt"; // Change the filename as needed

    loadEntries(passwordEntries, filename);

    while (true) {
        cout << "Password Manager" << endl;
        cout << "1. Add Entry" << endl;
        cout << "2. View Entries" << endl;
        cout << "3. Save and Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            PasswordEntry entry;
            cout << "Website: ";
            cin >> entry.website;
            cout << "Username: ";
            cin >> entry.username;
            cout << "Password: ";
            cin >> entry.password;
            passwordEntries.push_back(entry);
        } else if (choice == 2) {
            cout << "Password Entries:" << endl;
            for (const PasswordEntry& entry : passwordEntries) {
                cout << "Website: " << entry.website << " | Username: " << entry.username << " | Password: " << entry.password << endl;
            }
        } else if (choice == 3) {
            saveEntries(passwordEntries, filename);
            cout << "Password entries saved. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}