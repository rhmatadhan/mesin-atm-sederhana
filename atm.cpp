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

// ===================
// CEK SALDO
// ===================
void cekSaldo() {
    cout << "Saldo anda: Rp " << saldo << endl;
}


// ===================
// TARIK TUNAI
// ===================
void tarikTunai() {
    int jumlah;
    cout << "Jumlah tarik: ";
    cin >> jumlah;

    if (jumlah > 0 && jumlah <= saldo && jumlah >= 20000) {
        saldo -= jumlah;
        tambahRiwayat("Tarik " + to_string(jumlah));
        cout << "Penarikan berhasil.\n";
    } else {
        cout << "Penarikan GAGAL.\n";
    }
}


// ===================
// SETOR TUNAI
// ===================
void setorTunai() {
    int jumlah;
    cout << "Jumlah setor: ";
    cin >> jumlah;

    if (jumlah > 0 && jumlah % 10000 == 0) {
        saldo += jumlah;
        tambahRiwayat("Setor " + to_string(jumlah));
        cout << "Setoran berhasil.\n";
    } else {
        cout << "Setoran GAGAL.\n";
    }
}


// ===================
// TRANSFER
// ===================
void transferUang() {
    int tujuan, jumlah;

    cout << "Transfer ke rekening: ";
    cin >> tujuan;

    cout << "Jumlah transfer: ";
    cin >> jumlah;

    if (jumlah > 0 && jumlah <= saldo) {
        saldo -= jumlah;
        tambahRiwayat(
            "Transfer " + to_string(jumlah) + " ke " + to_string(tujuan)
        );
        cout << "Transfer BERHASIL\n";
    } else {
        cout << "Transfer GAGAL\n";
    }
}