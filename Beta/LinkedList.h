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
    void displayTransactions() const;
    vector<Transaksi> toVector() const;
    void searchByCategory(const string& kategori) const;
};

#endif
