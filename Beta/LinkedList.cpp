#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::addTransaction(const Transaksi& transaksi) {
    Node* newNode = new Node{ transaksi, nullptr };
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::displayTransactions() const {
    Node* temp = head;
    cout << left << setw(15) << "Tanggal" << setw(25) << "Kategori" << setw(15) << "Jumlah" << endl;
    cout << setfill('=') << setw(55) << "" << setfill(' ') << endl; 
    while (temp) {
        cout << left << setw(15) << temp->data.tanggal
            << setw(25) << temp->data.kategori
            << left << setw(15) << fixed << setprecision(2) << temp->data.jumlah << endl;
        temp = temp->next;
    }
}

vector<Transaksi> LinkedList::toVector() const {
    vector<Transaksi> transaksiVector;
    Node* temp = head;
    while (temp) {
        transaksiVector.push_back(temp->data);
        temp = temp->next;
    }
    return transaksiVector;
}

void LinkedList::searchByCategory(const string& kategori) const {
    Node* temp = head;
    bool found = false;
    cout << left << setw(15) << "Tanggal" << setw(25) << "Kategori" << setw(15) << "Jumlah" << endl;
    cout << setfill('=') << setw(55) << "" << setfill(' ') << endl; 
    while (temp) {
        if (temp->data.kategori == kategori) {
            cout << left << setw(15) << temp->data.tanggal
                << setw(25) << temp->data.kategori
                << left << setw(15) << fixed << setprecision(2) << temp->data.jumlah << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Tidak ada transaksi dengan kategori \"" << kategori << "\".\n";
    }
}
