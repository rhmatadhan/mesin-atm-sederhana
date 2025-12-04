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
void transfer() {
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
