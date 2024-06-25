#include "PengelolaKeuangan.h"

int main() {
    PengelolaKeuangan pengelola;
    int pilihan;

    do {
        pengelola.clearScreen();
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
        case 3: {
            int pilihanUrut;
            cout << "Urutkan berdasarkan tanggal? (1 = Ya, 0 = Tidak): ";
            cin >> pilihanUrut;
            pengelola.tampilkanTransaksi(pilihanUrut == 1);
            break;
        }
        case 4: {
            string kategori;
            cout << "Masukkan kategori yang ingin dicari: ";
            cin >> kategori;
            pengelola.cariTransaksiKategori(kategori);
            break;
        }
        case 5:
            pengelola.clearScreen();
            cout << "Keluar...\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
