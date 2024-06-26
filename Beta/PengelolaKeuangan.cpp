#include "PengelolaKeuangan.h"

PengelolaKeuangan::PengelolaKeuangan() : totalPemasukan(0.0), totalPengeluaran(0.0) {}

void PengelolaKeuangan::tambahTransaksi() {
    Transaksi transaksi;
    cout << "Masukkan tanggal (YYYY-MM-DD): ";
    cin >> transaksi.tanggal;
    cout << "Masukkan kategori: ";
    cin >> transaksi.kategori;
    cout << "Masukkan jumlah: ";
    cin >> transaksi.jumlah;

    daftarTransaksi.addTransaction(transaksi);

    if (transaksi.jumlah > 0) {
        totalPemasukan += transaksi.jumlah;
    }
    else {
        totalPengeluaran += transaksi.jumlah;
    }

    cout << "Transaksi berhasil ditambahkan.\n";
}

void PengelolaKeuangan::tampilkanRingkasan() const {
    cout << "\nRingkasan Keuangan:\n";
    cout << "Total Pemasukan: " << fixed << setprecision(2) << totalPemasukan << "\n";
    cout << "Total Pengeluaran: " << fixed << setprecision(2) << totalPengeluaran << "\n";
    cout << "Saldo Bersih: " << fixed << setprecision(2) << (totalPemasukan + totalPengeluaran) << "\n";
}

void PengelolaKeuangan::tampilkanTransaksi(bool urutkan) {
    if (urutkan) {
        vector<Transaksi> transaksiVector = daftarTransaksi.toVector();
        sort(transaksiVector.begin(), transaksiVector.end(), [](const Transaksi& a, const Transaksi& b) {
            return a.tanggal < b.tanggal;
            });

        cout << "\nDaftar Transaksi (Diurutkan berdasarkan tanggal):\n";
        cout << left << setw(15) << "Tanggal" << setw(25) << "Kategori" << setw(15) << "Jumlah" << endl;
        cout << setfill('=') << setw(55) << "" << setfill(' ') << "\n";
        for (const auto& transaksi : transaksiVector) {
            cout << left << setw(15) << transaksi.tanggal
                << setw(25) << transaksi.kategori
                << left << setw(15) << fixed << setprecision(2) << transaksi.jumlah << "\n";
        }
    }
    else {
        cout << "\nDaftar Transaksi:\n";
        daftarTransaksi.displayTransactions();
    }
}

void PengelolaKeuangan::cariTransaksiKategori(const string& kategori) const {
    cout << "\nTransaksi dengan kategori \"" << kategori << "\":\n";
    daftarTransaksi.searchByCategory(kategori);
}
