#include <iostream>
#include <limits> // Diperlukan untuk cin.ignore

using namespace std;

int main() {
    char pilihan;

    do {
        // --- 1. PROGRAM UTAMA ANDA DI SINI ---
        int angka;
        cout << "Masukkan sebuah angka: ";
        cin >> angka;
        cout << "Hasil kuadratnya adalah: " << angka * angka << endl;
        // -------------------------------------

        // Membersihkan buffer input agar cin.get() bekerja dengan benar
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // --- 2. KONFIRMASI KEMBALI ---
        cout << "\nTekan ENTER untuk kembali ke program utama, atau ketik 'n' lalu ENTER untuk keluar: ";
        pilihan = cin.get(); // Membaca satu karakter (termasuk Enter)

    } while (pilihan == '\n'); // Jika yang ditekan adalah Enter (\n), program akan mengulang

    cout << "Program selesai. Terima kasih!" << endl;
    return 0;
}
