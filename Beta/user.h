#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>
#include <fstream>
using namespace std;

class User {
public:
    string username;
    string password;

    // Konstruktor default
    User() = default;

    // Konstruktor parameter
    User(const string& user, const string& pass) : username(user), password(pass) {}
};

class Auth {
private:
    unordered_map<string, User> users;

public:
    Auth() {
        // Membaca daftar pengguna dari file (jika ada)
        ifstream infile("users.txt");
        if (infile.is_open()) {
            string username, password;
            while (infile >> username >> password) {
                users[username] = User(username, password);
            }
            infile.close();
        }
    }

    bool login(const string& username, const string& password) {
        if (users.find(username) != users.end() && users[username].password == password) {
            return true;
        }
        return false;
    }

    void addUser(const string& username, const string& password) {
        users[username] = User(username, password);
        ofstream outfile("users.txt", ios::app);
        if (outfile.is_open()) {
            outfile << username << " " << password << endl;
            outfile.close();
        }
    }
};

#endif // USER_H
