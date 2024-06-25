#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Transaksi {
    string tanggal;
    string kategori;
    double jumlah;
};

struct Node {
    Transaksi data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addTransaction(const Transaksi& transaksi) {
        Node* newNode = new Node{ transaksi, nullptr };
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayTransactions() const {
        Node* temp = head;
        cout << left << setw(15) << "Tanggal" << setw(25) << "Kategori" << setw(15) << "Jumlah" << endl;
        cout << setfill('=') << setw(55) << "" << setfill(' ') << endl; // Separator line
        while (temp) {
            cout << left << setw(15) << temp->data.tanggal
                << setw(25) << temp->data.kategori
                << left << setw(15) << fixed << setprecision(2) << temp->data.jumlah << endl;
            temp = temp->next;
        }
    }

    vector<Transaksi> toVector() const {
        vector<Transaksi> transaksiVector;
        Node* temp = head;
        while (temp) {
            transaksiVector.push_back(temp->data);
            temp = temp->next;
        }
        return transaksiVector;
    }

    void searchByCategory(const string& kategori) const {
        Node* temp = head;
        bool found = false;
        cout << left << setw(15) << "Tanggal" << setw(25) << "Kategori" << setw(15) << "Jumlah" << endl;
        cout << setfill('=') << setw(55) << "" << setfill(' ') << endl; // Separator line
        while (temp) {
            if (temp->data.kategori == kategori) {
                cout << left << setw(15) << temp->data.tanggal
                    << setw(25) << temp->data.kategori
                    << left << setw(15) << fixed << setprecision(2) << temp->data.jumlah << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "Tidak ada transaksi dengan kategori \"" << kategori << "\".\n";
        }
    }
};


class PengelolaKeuangan {
private:
    LinkedList daftarTransaksi;
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

        daftarTransaksi.addTransaction(transaksi);

        if (transaksi.jumlah > 0) {
            totalPemasukan += transaksi.jumlah;
        }
        else {
            totalPengeluaran += transaksi.jumlah;
        }

        cout << "Transaksi berhasil ditambahkan.\n";
    }

    void tampilkanRingkasan() const {
        cout << "\nRingkasan Keuangan:\n";
        cout << "Total Pemasukan: " << fixed << setprecision(2) << totalPemasukan << "\n";
        cout << "Total Pengeluaran: " << fixed << setprecision(2) << totalPengeluaran << "\n";
        cout << "Saldo Bersih: " << fixed << setprecision(2) << (totalPemasukan + totalPengeluaran) << "\n";
    }

    void tampilkanTransaksi(bool urutkan = false) {
        if (urutkan) {
            vector<Transaksi> transaksiVector = daftarTransaksi.toVector();
            sort(transaksiVector.begin(), transaksiVector.end(), [](const Transaksi& a, const Transaksi& b) {
                return a.tanggal < b.tanggal;
                });

            cout << "\nDaftar Transaksi (Diurutkan berdasarkan tanggal):\n";
            cout << left << setw(15) << "Tanggal" << setw(25) << "Kategori" << setw(15) << "Jumlah\n";
            cout << setfill('=') << setw(55) << "" << setfill(' ') << "\n";
            for (const auto& transaksi : transaksiVector) {
                cout << left << setw(15) << transaksi.tanggal
                    << setw(25) << transaksi.kategori
                    << right << setw(15) << fixed << setprecision(2) << transaksi.jumlah << "\n";
            }
        }
        else {
            cout << "\nDaftar Transaksi:\n";
            daftarTransaksi.displayTransactions();
        }
    }

    void cariTransaksiKategori(const string& kategori) const {
        cout << "\nTransaksi dengan kategori \"" << kategori << "\":\n";
        daftarTransaksi.searchByCategory(kategori);
    }
};


int main() {
    PengelolaKeuangan pengelola;
    int pilihan;

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
            cout << "Keluar...\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
