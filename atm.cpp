#include <iostream>
#include <string>
using namespace std;

// ===================
// Global Data
// ===================
int saldo = 100000;
string riwayat[20];
int indexRiwayat = 0;


// ===================
// Fungsi Riwayat
// ===================
void tambahRiwayat(string msg) {
    if (indexRiwayat < 20) {
        riwayat[indexRiwayat] = msg;
        indexRiwayat++;
    }
}

void tampilRiwayat() {
    cout << "\n===== RIWAYAT TRANSAKSI =====\n";

    if (indexRiwayat == 0) {
        cout << "Belum ada transaksi.\n";
        return;
    }

    for (int i = 0; i < indexRiwayat; i++) {
        cout << i + 1 << ". " << riwayat[i] << endl;
    }
}