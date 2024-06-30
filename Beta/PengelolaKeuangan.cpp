#include "PengelolaKeuangan.h"
#include "transaksi.h"
#include "user.h"

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

PengelolaKeuangan::PengelolaKeuangan() : totalPemasukan(0.0), totalPengeluaran(0.0) {}

void PengelolaKeuangan::tambahTransaksi(string username) {
    clearScreen();
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
    Transaksi1 transaksi1(transaksi.tanggal, transaksi.kategori, transaksi.jumlah);
    LogTransaksi::log(username, transaksi1);
    cout << "Transaksi berhasil ditambahkan.\n";
}

void PengelolaKeuangan::tampilkanRingkasan() const {
    clearScreen();
    cout << "\nRingkasan Keuangan:\n";
    cout << "Total Pemasukan: " << fixed << setprecision(2) << totalPemasukan << "\n";
    cout << "Total Pengeluaran: " << fixed << setprecision(2) << totalPengeluaran << "\n";
    cout << "Saldo Bersih: " << fixed << setprecision(2) << (totalPemasukan + totalPengeluaran) << "\n";
    system("pause");
}

void PengelolaKeuangan::tampilkanTransaksi(bool urutkan) {
    clearScreen();
    if (urutkan) {
        vector<Transaksi> transaksiVector = daftarTransaksi.toVector();
        sort(transaksiVector.begin(), transaksiVector.end(), [](const Transaksi& a, const Transaksi& b) {
            return a.tanggal < b.tanggal;
            });

        cout << "+" << setfill('-') << setw(63) << "+" << setfill(' ') << endl;
        cout << "|" << left << setw(15) << "Tanggal" << "|" << setw(25) << "Kategori" << "|" << setw(20) << "Jumlah" << "|" << endl;
        cout << "+" << setfill('-') << right << setw(63) << "+" << setfill(' ') << endl; // Separator line
        for (const auto& transaksi : transaksiVector) {
            cout << "|" << left << setw(15) << transaksi.tanggal << "|"
                << setw(25) << transaksi.kategori << "|"
                << left << setw(20) << fixed << setprecision(2) << transaksi.jumlah << "|" << endl;
        }
        cout << "+" << setfill('-') << right << setw(63) << "+" << setfill(' ') << endl;
        system("pause");
    }
    else {
        cout << "\nDaftar Transaksi:\n";
        daftarTransaksi.displayTransactions();
    }
}

void PengelolaKeuangan::cariTransaksiKategori(const string& kategori) const {
    clearScreen();
    cout << "\nTransaksi dengan kategori \"" << kategori << "\":\n";
    daftarTransaksi.searchByCategory(kategori);
}

void PengelolaKeuangan::clearScreen() const {
    system(CLEAR_COMMAND);
}
