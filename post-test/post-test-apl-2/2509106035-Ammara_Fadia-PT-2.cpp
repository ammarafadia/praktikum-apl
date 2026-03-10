#include <iostream>
#include <string>
using namespace std;

struct Kursus {
    string id;
    string nama;
};

int main() {
    Kursus kursus[100] = {
        {"K001", "Dasar C++"},
        {"K002", "Dasar Python"},
        {"K003", "Web Programming"}
    };
    int jumlahKursus = 3;

    Kursus kursusDiambil[100];
    int jumlahDiambil = 0;

    string username, password;
    int menu = 0;
    int percobaanLogin;

    while (true) {
        percobaanLogin = 0;

        while (percobaanLogin < 3) {
            cout << "\n=== LOGIN ===" << endl;
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;

            if ((username == "admin" && password == "123") ||
                (username == "user" && password == "123")) {
                break;
            } else if (username == "0" && password == "0") {
                cout << "Program selesai." << endl;
                return 0;
            } else {
                percobaanLogin++;
                cout << "Login gagal. Sisa percobaan: " << 3 - percobaanLogin << endl;
                cout << "Ketik 0 untuk username dan password jika ingin keluar." << endl;
            }
        }

        if (percobaanLogin == 3) {
            cout << "Anda sudah 3 kali salah login. Program berhenti." << endl;
            return 0;
        }

        if (username == "admin" && password == "123") {
            do {
                cout << "\n=== MENU ADMIN ===" << endl;
                cout << "1. Lihat Kursus" << endl;
                cout << "2. Tambah Kursus" << endl;
                cout << "3. Ubah Kursus" << endl;
                cout << "4. Hapus Kursus" << endl;
                cout << "5. Logout" << endl;
                cout << "Pilih : ";
                cin >> menu;

                switch (menu) {
                    case 1:
                        cout << "\n=== Daftar Kursus ===" << endl;
                        if (jumlahKursus == 0) {
                            cout << "Belum ada kursus" << endl;
                        } else {
                            for (int i = 0; i < jumlahKursus; i++) {
                                cout << i + 1 << ". "
                                     << kursus[i].id << " - "
                                     << kursus[i].nama << endl;
                            }
                        }
                        break;

                    case 2: {
                        Kursus k;
                        bool sudahAda = false;

                        cout << "ID Kursus   : ";
                        cin >> k.id;

                        for (int i = 0; i < jumlahKursus; i++) {
                            if (kursus[i].id == k.id) {
                                sudahAda = true;
                                break;
                            }
                        }

                        if (sudahAda) {
                            cout << "ID Kursus sudah ada! Gunakan ID lain." << endl;
                            break;
                        }

                        cin.ignore();
                        cout << "Nama Kursus : ";
                        getline(cin, k.nama);

                        kursus[jumlahKursus] = k;
                        jumlahKursus++;
                        cout << "Kursus berhasil ditambahkan" << endl;
                        break;
                    }

                    case 3: {
                        string idCari;
                        string namaBaru;
                        bool ditemukan = false;

                        cout << "Masukkan ID Kursus yang ingin diubah : ";
                        cin >> idCari;
                        cin.ignore();

                        for (int i = 0; i < jumlahKursus; i++) {
                            if (kursus[i].id == idCari) {
                                ditemukan = true;
                                cout << "Data lama : " << kursus[i].id
                                     << " - " << kursus[i].nama << endl;
                                cout << "Masukkan nama kursus baru : ";
                                getline(cin, namaBaru);

                                kursus[i].nama = namaBaru;
                                cout << "Data kursus berhasil diubah" << endl;
                                break;
                            }
                        }

                        if (!ditemukan) {
                            cout << "Kursus tidak ditemukan" << endl;
                        }
                        break;
                    }

                    case 4: {
                        string id;
                        bool ditemukan = false;

                        cout << "Masukkan ID Kursus : ";
                        cin >> id;

                        for (int i = 0; i < jumlahKursus; i++) {
                            if (kursus[i].id == id) {
                                for (int j = i; j < jumlahKursus - 1; j++) {
                                    kursus[j] = kursus[j + 1];
                                }
                                jumlahKursus--;
                                ditemukan = true;
                                cout << "Kursus berhasil dihapus" << endl;
                                break;
                            }
                        }

                        if (!ditemukan) {
                            cout << "Kursus tidak ditemukan" << endl;
                        }
                        break;
                    }

                    case 5:
                        cout << "Logout..." << endl;
                        break;

                    default:
                        cout << "Menu tidak valid" << endl;
                }

            } while (menu != 5);
        }
        else if (username == "user" && password == "123") {
            do {
                cout << "\n=== MENU USER ===" << endl;
                cout << "1. Lihat Kursus" << endl;
                cout << "2. Daftar Kursus" << endl;
                cout << "3. Lihat Kursus yang Diambil" << endl;
                cout << "4. Logout" << endl;
                cout << "Pilih : ";
                cin >> menu;

                switch (menu) {
                    case 1:
                        cout << "\n=== Daftar Kursus ===" << endl;
                        if (jumlahKursus == 0) {
                            cout << "Belum ada kursus" << endl;
                        } else {
                            for (int i = 0; i < jumlahKursus; i++) {
                                cout << i + 1 << ". "
                                     << kursus[i].id << " - "
                                     << kursus[i].nama << endl;
                            }
                        }
                        break;

                    case 2: {
                        int pilih;
                        bool sudahAda = false;

                        cout << "\n=== Daftar Kursus ===" << endl;

                        if (jumlahKursus == 0) {
                            cout << "Belum ada kursus." << endl;
                            break;
                        }

                        for (int i = 0; i < jumlahKursus; i++) {
                            cout << i + 1 << ". "
                                 << kursus[i].id << " - "
                                 << kursus[i].nama << endl;
                        }

                        cout << "Pilih nomor kursus : ";
                        cin >> pilih;

                        if (pilih < 1 || pilih > jumlahKursus) {
                            cout << "Pilihan tidak valid" << endl;
                            break;
                        }

                        for (int i = 0; i < jumlahDiambil; i++) {
                            if (kursusDiambil[i].id == kursus[pilih - 1].id) {
                                sudahAda = true;
                                break;
                            }
                        }

                        if (sudahAda) {
                            cout << "Kursus sudah diambil" << endl;
                        } else {
                            kursusDiambil[jumlahDiambil] = kursus[pilih - 1];
                            jumlahDiambil++;
                            cout << "Berhasil mendaftar kursus" << endl;
                        }
                        break;
                    }

                    case 3:
                        cout << "\n=== Kursus yang Diambil ===" << endl;
                        if (jumlahDiambil == 0) {
                            cout << "Belum mengambil kursus" << endl;
                        } else {
                            for (int i = 0; i < jumlahDiambil; i++) {
                                cout << i + 1 << ". "
                                     << kursusDiambil[i].id << " - "
                                     << kursusDiambil[i].nama << endl;
                            }
                        }
                        break;

                    case 4:
                        cout << "Logout..." << endl;
                        break;

                    default:
                        cout << "Menu tidak valid" << endl;
                }

            } while (menu != 4);
        }
    }

    return 0;
}