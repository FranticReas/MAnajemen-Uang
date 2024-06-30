#ifndef TRANSAKSI_H
#define TRANSAKSI_H

#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
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
    static void log(const string& username, const Transaksi& transaksi) {
        ofstream outfile("transaksi_log.txt", ios::app);
        if (outfile.is_open()) {
            outfile << "User: " << username << ", Tanggal: " << transaksi.tanggal
                << ", Kategori: " << transaksi.kategori << ", Jumlah: " << transaksi.jumlah << endl;
            outfile.close();
        }
    }
};

#endif // TRANSAKSI_H
