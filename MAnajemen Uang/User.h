#pragma once
using namespace std;

class User
{
    public:
    int userID;
    string name;
    string email;
    string password;

    User(int id, string n, string e, string p) : userID(id), name(n), email(e), password(p) {}
};

void addUser(int id, string name, string email, string password)
{
    users.push_back(User(id, name, email, password));
}

void displayUsers()
{
    for (const auto& user : users) {
        cout << "UserID: " << user.userID << ", Name: " << user.name << ", Email: " << user.email << endl;
    }
}

