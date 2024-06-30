#include "PengelolaKeuangan.h"
#include "user.h"
#include "transaksi.h"
#include <iostream>

using namespace std;
string username, password;
void mainmenu();
int main() {
    PengelolaKeuangan pengelola;
    int pilihan;
    Auth auth;

    do
    {
        pengelola.clearScreen();
        cout << "Sistem Login" << endl;
        cout << "1. Login" << endl;
        cout << "2. Tambah Pengguna Baru" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            pengelola.clearScreen();
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;

            if (auth.login(username, password)) {
                cout << "Login berhasil!" << endl;
                mainmenu();
            }
            else {
                cout << "Username atau password salah." << endl;
                break;
            }
        }
        case 2:
        {
            pengelola.clearScreen();
            cout << "Masukkan username baru: ";
            cin >> username;
            cout << "Masukkan password baru: ";
            cin >> password;
            auth.addUser(username, password);
            cout << "Pengguna baru berhasil ditambahkan. Silahkan Login" << endl;
            system("pause");
            break;
        }
        default:
        {
            pengelola.clearScreen();
            cout << "Pilihan tidak valid." << endl;
            break;
        }
        }
    } while (pilihan != 3);
    return 0;
}

void mainmenu()
{
    PengelolaKeuangan pengelola;
    int pilihan;
    
    do {

        pengelola.clearScreen();
        cout << "Pengelola Keuangan\n";
        cout << "1. Tambah Transaksi\n";
        cout << "2. Lihat Ringkasan\n";
        cout << "3. Lihat Transaksi\n";
        cout << "4. Cari Transaksi berdasarkan Kategori\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            pengelola.tambahTransaksi(username);
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
}