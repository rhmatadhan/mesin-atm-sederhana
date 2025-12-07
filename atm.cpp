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
    cout << "\n===== CEK SALDO =====\n";
    cout << "Saldo anda: Rp " << saldo << endl;
}


// ===================
// TARIK TUNAI
// ===================
void tarikTunai() {
    int jumlah;
    cout << "\n===== TARIK TUNAI =====\n";
    cout << "Masukkan jumlah tarik: ";
    cin >> jumlah;

    if (jumlah <= 0) {
        cout << "Jumlah tidak valid!\n";
        return;
    }

    if (jumlah > saldo) {
        cout << "Saldo tidak cukup!\n";
        return;
    }

    if (jumlah < 20000) {
        cout << "Minimal tarik 20.000!\n";
        return;
    }

    saldo -= jumlah;
    tambahRiwayat("Tarik Rp " + to_string(jumlah));

    cout << "Berhasil tarik!\n";
    cout << "Saldo baru: Rp " << saldo << endl;
}


// ===================
// SETOR TUNAI
// ===================
void setorTunai() {
    int jumlah;
    cout << "\n===== SETOR TUNAI =====\n";
    cout << "Masukkan jumlah setor: ";
    cin >> jumlah;

    if (jumlah <= 0) {
        cout << "Jumlah tidak valid!\n";
        return;
    }

    if (jumlah % 10000 != 0) {
        cout << "Harus kelipatan 10.000!\n";
        return;
    }

    saldo += jumlah;
    tambahRiwayat("Setor Rp " + to_string(jumlah));

    cout << "Berhasil setor!\n";
    cout << "Saldo baru: Rp " << saldo << endl;
}


// ===================
// TRANSFER
// ===================
void transfer() {
    int rekeningTujuan[3] = {111, 222, 333};
    int rekInput, jumlah;

    cout << "\n===== TRANSFER =====\n";
    cout << "Masukkan nomor rekening: ";
    cin >> rekInput;

    bool ditemukan = false;
    for (int i = 0; i < 3; i++) {
        if (rekInput == rekeningTujuan[i]) ditemukan = true;
    }

    if (!ditemukan) {
        cout << "Rekening tidak ditemukan!\n";
        return;
    }

    cout << "Masukkan jumlah transfer: ";
    cin >> jumlah;

    if (jumlah <= 0 || jumlah > saldo) {
        cout << "Jumlah tidak valid atau saldo kurang!\n";
        return;
    }

    saldo -= jumlah;
    tambahRiwayat("Transfer Rp " + to_string(jumlah) + " ke " + to_string(rekInput));

    cout << "Transfer berhasil!\n";
    cout << "Saldo baru: Rp " << saldo << endl;
}

// ===================
// Login
// ===================
bool login() {
    int pinBenar = 1234;
    int pinInput;
    int kesempatan = 3;

    while (kesempatan > 0) {
        cout << "\n===== LOGIN ATM =====\n";
        cout << "Masukkan PIN: ";
        cin >> pinInput;

        if (pinInput == pinBenar) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            kesempatan--;
            cout << "PIN salah! Sisa kesempatan: " << kesempatan << endl;
        }
    }

    cout << "Akun terblokir!\n";
    return false;
}


// ===================
// Menu Utama
// ===================
void menuUtama() {
    int pilihan;

    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Setor Tunai\n";
        cout << "3. Tarik Tunai\n";
        cout << "4. Transfer\n";
        cout << "5. Riwayat Transaksi\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: cekSaldo(); break;
            case 2: setorTunai(); break;
            case 3: tarikTunai(); break;
            case 4: transfer(); break;
            case 5: tampilRiwayat(); break;
            case 6: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);
}


// ===================
// MAIN PROGRAM
// ===================
int main() {
    if (login()) menuUtama();
    return 0;
}
