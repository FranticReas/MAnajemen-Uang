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

class PengelolaKeuangan {
private:
    vector<Transaksi> daftarTransaksi;
    double totalPemasukan = 0.0;
    double totalPengeluaran = 0.0;

public:
    void tambahTransaksi() {
        Transaksi transaksi;
        cout << "Masukkan tanggal (YYYY-MM-DD): ";
        cin >> transaksi.tanggal;
        cout << "Masukkan kategori: ";
        cin >> transaksi.kategori;
        cout << "Masukkan jumlah: ";
        cin >> transaksi.jumlah;

        daftarTransaksi.push_back(transaksi);

        if (transaksi.jumlah > 0) {
            totalPemasukan += transaksi.jumlah;
        }
        else {
            totalPengeluaran += transaksi.jumlah;
        }

        cout << "Transaksi berhasil ditambahkan.\n";
    }

    void tampilkanRingkasan() {
        cout << "\nRingkasan Keuangan:\n";
        cout << "Total Pemasukan: " << fixed << setprecision(2) << totalPemasukan << "\n";
        cout << "Total Pengeluaran: " << fixed << setprecision(2) << totalPengeluaran << "\n";
        cout << "Saldo Bersih: " << fixed << setprecision(2) << (totalPemasukan + totalPengeluaran) << "\n";
    }

    void tampilkanTransaksi(bool urutkan = false) {
        if (urutkan) {
            sort(daftarTransaksi.begin(), daftarTransaksi.end(), [](const Transaksi& a, const Transaksi& b) {
                return a.tanggal < b.tanggal;
                });
        }

        cout << "\nDaftar Transaksi:\n";
        cout << left << setw(15) << "Tanggal" << setw(25) << "Kategori" << setw(15) << "Jumlah\n";
        for (const auto& transaksi : daftarTransaksi) {
            cout << left << setw(15) << transaksi.tanggal
                << setw(25) << transaksi.kategori
                << right << setw(15) << fixed << setprecision(2) << transaksi.jumlah << "\n";
        }
    }

    void cariTransaksiKategori(const string& kategori) {
        cout << "\nTransaksi dengan kategori \"" << kategori << "\":\n";
        cout << left << setw(15) << "Tanggal" << setw(25) << "Kategori" << setw(15) << "Jumlah\n";
        for (const auto& transaksi : daftarTransaksi) {
            if (transaksi.kategori == kategori) {
                cout << left << setw(15) << transaksi.tanggal
                    << setw(25) << transaksi.kategori
                    << right << setw(15) << fixed << setprecision(2) << transaksi.jumlah << "\n";
            }
        }
    }
};

int main() {
    PengelolaKeuangan pengelola;
    int pilihan; string kategori;

    do {
        cout << "\nPengelola Keuangan\n";
        cout << "1. Tambah Transaksi\n";
        cout << "2. Lihat Ringkasan\n";
        cout << "3. Lihat Transaksi\n";
        cout << "4. Cari Transaksi berdasarkan Kategori\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            pengelola.tambahTransaksi();
            break;
        case 2:
            pengelola.tampilkanRingkasan();
            break;
        case 3:
            int pilihanUrut;
            cout << "Urutkan berdasarkan tanggal? (1 = Ya, 0 = Tidak): ";
            cin >> pilihanUrut;
            pengelola.tampilkanTransaksi(pilihanUrut == 1);
            break;
        case 4:   
            cout << "Masukkan kategori yang ingin dicari: ";
            cin >> kategori;
            pengelola.cariTransaksiKategori(kategori);
            break;
        case 5:
            cout << "Keluar...\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
