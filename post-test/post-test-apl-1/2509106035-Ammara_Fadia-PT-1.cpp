#include <iostream>
using namespace std;

int main() {
    string namaUser;
    string password;
    string namaBenar = "ammara";
    string passwordBenar = "035";
    int kesempatanLogin = 0;
    bool loginBerhasil = false;

    while (kesempatanLogin < 3) {
        cout << "=== LOGIN ===" << endl;
        cout << "Masukkan Nama     : ";
        cin >> namaUser;
        cout << "Masukkan Password : ";
        cin >> password;

        if (namaUser == namaBenar && password == passwordBenar) {
            loginBerhasil = true;
            break;
        } else {
            kesempatanLogin++;
            cout << "Kesempatan login tersisa: "
                 << 3 - kesempatanLogin << endl << endl;
        }
    }

    if (!loginBerhasil) {
        cout << "Gagal login." << endl;
        return 0;
    }

    cout << "\nLogin berhasil!\n" << endl;

    int pilihanMenu;
    double nilaiPanjang;
    double hasilMeter, hasilKilometer, hasilCentimeter;

    do {
        cout << "=== MENU KONVERSI PANJANG ===" << endl;
        cout << "1. Meter ke Kilometer dan Centimeter" << endl;
        cout << "2. Kilometer ke Meter dan Centimeter" << endl;
        cout << "3. Centimeter ke Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                cout << "Masukkan nilai dalam Meter: ";
                cin >> nilaiPanjang;

                hasilKilometer = nilaiPanjang / 1000;
                hasilCentimeter = nilaiPanjang * 100;

                cout << "Hasil konversi:" << endl;
                cout << "Kilometer  : " << hasilKilometer << " km" << endl;
                cout << "Centimeter : " << hasilCentimeter << " cm" << endl;
                break;

            case 2:
                cout << "Masukkan nilai dalam Kilometer: ";
                cin >> nilaiPanjang;

                hasilMeter = nilaiPanjang * 1000;
                hasilCentimeter = nilaiPanjang * 100000;

                cout << "Hasil konversi:" << endl;
                cout << "Meter      : " << hasilMeter << " m" << endl;
                cout << "Centimeter : " << hasilCentimeter << " cm" << endl;
                break;

            case 3:
                cout << "Masukkan nilai dalam Centimeter: ";
                cin >> nilaiPanjang;

                hasilMeter = nilaiPanjang / 100;
                hasilKilometer = nilaiPanjang / 100000;

                cout << "Hasil konversi:" << endl;
                cout << "Meter     : " << hasilMeter << " m" << endl;
                cout << "Kilometer : " << hasilKilometer << " km" << endl;
                break;

            case 4:
                cout << "Terima kasih. Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

        cout << endl;

    } while (pilihanMenu != 4);

    return 0;
}