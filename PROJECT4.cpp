#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower
using namespace std;
// Structure to represent user data
struct User
{
    string username;
    string password;
};

// Function to convert a string to lowercase
string toLower(string str)
{
    transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return tolower(c); });
    return str;
}

// Function to load user data from a file
vector<User> loadUsers(const string& filename)
{
    vector<User> users;
    ifstream file(filename);
    if (file.is_open())
        {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string segment;
            vector<string> userData;
            while (getline(ss, segment, ','))
            {
                userData.push_back(segment);
            }
            if (userData.size() == 2)
            {
                users.push_back({userData[0], userData[1]});
            }
        }
        file.close();
    }
    return users;
}

// Function to save user data to a file
void saveUsers(const string& filename, const vector<User>& users)
{
    ofstream file(filename);
    if (file.is_open())
        {
        for (const auto& user : users)
        {
            file << user.username << "," << user.password << endl;
        }
        file.close();
    }
    else
        {
        cerr << "Error opening file for saving users!" << endl;
    }
}

// Function for user registration
bool registerUser(vector<User>& users, const string& filename)
{
    string newUsername, newPassword;
    cout << "Enter new username: ";
    cin >> newUsername;
    cout << "Enter new password: ";
    cin >> newPassword;

    // Check if the username already exists (case-insensitive)
    for (const auto& user : users)
        {
        if (toLower(user.username) == toLower(newUsername)) {
            cout << "Username already exists. Please choose another." << endl;
            return false;
        }
    }

    users.push_back({newUsername, newPassword});
    saveUsers(filename, users);
    cout << "Registration successful!" <<endl;
    return true;
}

// Function for user login
bool loginUser(const vector<User>& users)
{
    string enteredUsername, enteredPassword;
    cout << "Enter your username: ";
    cin >> enteredUsername;
    cout << "Enter your password: ";
    cin >> enteredPassword;

    for (const auto& user : users)
        {
        if (user.username == enteredUsername && user.password == enteredPassword)
        {
            cout << "Login successful! Welcome, " << user.username << "!" << endl;
            return true;
        }
    }

    cout << "Login failed. Invalid username or password." << endl;
    return false;
}

int main()
{
    const string usersFile = "users.txt";
    vector<User> users = loadUsers(usersFile);
    int choice;

    while (true)
        {
        cout << "\n--- Login and Registration System ---" <<endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser(users, usersFile);
                break;
            case 2:
                loginUser(users);
                break;
            case 3:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
