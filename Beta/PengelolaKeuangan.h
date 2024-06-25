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
    void tambahTransaksi();
    void tampilkanRingkasan() const;
    void tampilkanTransaksi(bool urutkan = false);
    void cariTransaksiKategori(const string& kategori) const;
};

#endif
