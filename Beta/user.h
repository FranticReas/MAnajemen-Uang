#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
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
            string line;
            while (getline(infile, line)) {
                stringstream ss(line);
                string username, password;
                ss >> username >> password;
                users[username] = User(username, password);
            }
            infile.close();
        }
        else {
            cerr << "Gagal membuka file users.txt" << endl;
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
        else {
            cerr << "Gagal membuka file users.txt" << endl;
        }
    }
};

#endif // USER_H
