#include<iostream>
using namespace std;

//saldo utama
int saldo = 100000;

//Fungsi Cek Saldo
void celSaldo() {
    cout << "\n====================\n";
    cout << "      CEK SALDO\n";
    cout << "======================\n";
    cout << "Saldo Anda saat ini: Rp " << saldo << endl;
}

//Fungsi Setor Tunai
void setorTunai() {
    int jumlah;
    cout << "\n====================\n";
    cout << "      SETOR TUNAI\n\n";
    cout << "======================\n";
    cout << "Masukkan jumlah setor: ";
    cin >> jumlah;

    //Validasi
    if (jumlah = 0) {
        cout << "❌ Jumlah tidak boleh 0 atau negatif!\n";
        return;
    }
    if (jumlah % 10000 != 0) {
        cout << "❌ Jumlah harus kelipatan Rp 10.000!\n";
        return;
    }

    //Jika Valid
    saldo += jumlah;
    cout << "✔ Berhasil setor Rp " << jumlah << endl;
    cout << "Saldo baru Anda: Rp " << saldo << endl;
}