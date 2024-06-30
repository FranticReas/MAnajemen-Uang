#include "PengelolaKeuangan.h"
#include "user.h"
#include "transaksi.h"
#include <iostream>
#include "spinner.h"
#include <thread>
#include <chrono>

using namespace std;
string username, password;

void mainmenu();
void ucapan_selamat_datang();
void color(int nomor);
void gotoxy(int x, int y);

int main() {
    PengelolaKeuangan pengelola;
    int pilihan;
    Auth auth;
    ucapan_selamat_datang();

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
                system("pause");
                mainmenu();
            }
            else {
                cout << "Username atau password salah." << endl;
                system("pause");
            }
            break;
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
    Auth auth;
    
    do {

        pengelola.clearScreen();
        cout << "Pengelola Keuangan\n";
        cout << "1. Tambah Transaksi\n";
        cout << "2. Lihat Ringkasan\n";
        cout << "3. Lihat Transaksi\n";
        cout << "4. Cari Transaksi berdasarkan Kategori\n";
        
        //Cari dari tanggal
        //Menghapus transaksi
        cout << "5. Keluar\n";
        if (auth.isAdmin(username))
        {
            cout << "6. Lihat log file" << endl;
        }
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
        {
            pengelola.clearScreen();
            cout << "Keluar...\n";
            system("pause");
            break;
        }
        case 6:
        {
            pengelola.clearScreen();
            cout << "Selamat datang, Admin! Berikut adalah log transaksi:" << endl;
            LogTransaksi::displayLog();
            system("pause");
            break;
        }
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);
}

void ucapan_selamat_datang()
{
    Spinner spinner;
    const char selamat_datang[] = "FINANCIAL MANAGEMENT APP";
    const char selamat_datang2[] = "DELTA ENTERPRISE";

    const int kalimat_selamat_datang = sizeof(selamat_datang) / sizeof(selamat_datang[0]);
    const int kalimat_selamat_datang2 = sizeof(selamat_datang2) / sizeof(selamat_datang2[0]);

    color(11);
    for (int x = 0; x < kalimat_selamat_datang; ++x)
    {
        gotoxy((x + 50), 4);
        //system("Color 0A");

        std::cout << selamat_datang[x];
        Sleep(50);
    }
    std::cout << '\n';

    for (int x = 0; x < kalimat_selamat_datang2; ++x)
    {
        gotoxy((x + 54), 5);
        //system("Color 0A");
        std::cout << selamat_datang2[x];
        Sleep(50);
    }
    spinner.start();
    std::cout << "\n\n";
    color(7);
    Sleep(3000);
    spinner.stop();
}

void color(int nomor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nomor);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
