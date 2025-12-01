#include <iostream>
using namespace std;

int main() {
// PIN yang tersimpan
    int pinBenar = 2131;
    int pinInput;
    int kesempatan = 3;
 cout << "=== SELAMAT DATANG DI ATM BANK ===" << endl;
// Proses login PIN
    while (kesempatan > 0) {
        cout << "Masukkan PIN Anda: ";
        cin >> pinInput;

        if (pinInput == pinBenar) {
            cout << "Login berhasil! Selamat datang." << endl;
// Jika PIN benar, keluar dari loop
    break;
        } else {
            kesempatan--;
            cout << "PIN salah!" << endl;

        if (kesempatan > 0) {
            cout << "Sisa kesempatan: " << kesempatan << endl;
        } else {
            cout << "Akun diblokir! Anda telah salah memasukkan PIN 3 kali." << endl;
            return 0; 
// Program berhenti
            }
        }
    }
// Jika login berhasil
    cout << " Menu ATM akan ditampilkan di sini..." << endl;
    return 0;
}
