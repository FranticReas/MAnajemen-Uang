#ifndef TRANSAKSI_H
#define TRANSAKSI_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip> // Untuk format tabel
#include <windows.h> // Untuk fungsi gotoxy
using namespace std;

class Transaksi1 {
public:
    string tanggal;
    string kategori;
    double jumlah;

    Transaksi1(const string& tgl, const string& kat, double jml) : tanggal(tgl), kategori(kat), jumlah(jml) {}
};

class LogTransaksi {
public:
    static void log(const string& username, const Transaksi1& transaksi1) {
        ofstream outfile("transaksi_log.txt", ios::app);
        if (outfile.is_open()) {
            outfile << username << " " << transaksi1.tanggal
                << " " << transaksi1.kategori << " " << transaksi1.jumlah << endl;
            outfile.close();
        }
    }

    static void displayLog() {
        ifstream infile("transaksi_log.txt");
        if (infile.is_open()) {
            string username, tanggal, kategori;
            double jumlah;
            cout << "+" << setfill('-') << setw(63) << right << "+" << setfill(' ') << endl;
            cout << "|" << left << setw(16) << "Username"
                 << "|" << left << setw(16) << "Tanggal"
                 << "|" << left << setw(16) << "Kategori"
                 << "|" << left << setw(11) << "Jumlah" << "|" << endl;
            cout << "+" << setfill('-') << setw(63) << right << "+" << setfill(' ') << endl;

            while (infile >> username >> tanggal >> kategori >> jumlah) {
                cout << "|" << left << setw(16) << username << "|"
                    << left << setw(16) << tanggal << "|"
                    << left << setw(16) << kategori << "|"
                    << left << setw(11) << jumlah << "|" << endl;
            }
            cout << "+" << setfill('-') << setw(63) << right << "+" << setfill(' ') << endl;
            infile.close();
        }
        else {
            cerr << "Gagal membuka file transaksi_log.txt" << endl;
        }
    }
};

#endif // TRANSAKSI_H
