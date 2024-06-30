#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Transaksi {
    string tanggal;
    string kategori;
    double jumlah;
    string username;

    Transaksi() : jumlah(0.0) {}
};

struct Node {
    Transaksi data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void addTransaction(const Transaksi& transaksi);
    void deleteTransaction(const string& tanggal, const string& kategori);
    void displayTransactions() const;
    vector<Transaksi> toVector() const;
    void searchByCategory(const string& kategori) const;
    void searchByDate(const string& tanggal) const;
};

#endif
