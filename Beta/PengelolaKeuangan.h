#ifndef PENGELOLAKEUANGAN_H
#define PENGELOLAKEUANGAN_H

#include "LinkedList.h"

class PengelolaKeuangan {
private:
    LinkedList daftarTransaksi;
    double totalPemasukan;
    double totalPengeluaran;

public:
    PengelolaKeuangan();
    void tambahTransaksi(string username);
    void tampilkanRingkasan() const;
    void tampilkanTransaksi(bool urutkan = false);
    void cariTransaksiKategori(const string& kategori) const;
    void clearScreen() const;
    void hapusTransaksi(const string& tanggal, const string& kategori);
    void cariTransaksiTanggal(const string& tanggal) const;
};

#endif