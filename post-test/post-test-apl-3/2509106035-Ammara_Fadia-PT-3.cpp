#include <iostream>
#include <string>
using namespace std;

struct Kursus {
    string id;
    string nama;
    string instruktur;
};

struct User {
    string username;
    string password;
    string role;
};

void tampilHeader(string judul) {
    cout << "\n=== " << judul << " ===" << endl;
}

bool login(User users[], int jumlahUser, string username, string password, string &role) {
    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].username == username && users[i].password == password) {
            role = users[i].role;
            return true;
        }
    }
    return false;
}

int cariIndexKursus(Kursus kursus[], int jumlahKursus, string idCari) {
    for (int i = 0; i < jumlahKursus; i++) {
        if (kursus[i].id == idCari) {
            return i;
        }
    }
    return -1;
}

bool cekKursusSudahDiambil(Kursus kursusDiambil[], int jumlahDiambil, string idKursus) {
    for (int i = 0; i < jumlahDiambil; i++) {
        if (kursusDiambil[i].id == idKursus) {
            return true;
        }
    }
    return false;
}

void tampilDaftarKursusRekursif(Kursus kursus[], int jumlahKursus, int index) {
    if (index >= jumlahKursus) {
        return;
    }

    cout << index + 1 << ". "
         << kursus[index].id << " - "
         << kursus[index].nama << " - "
         << kursus[index].instruktur << endl;

    tampilDaftarKursusRekursif(kursus, jumlahKursus, index + 1);
}

void tampilDaftarKursus(Kursus kursus[], int jumlahKursus) {
    tampilHeader("Daftar Kursus");
    if (jumlahKursus == 0) {
        cout << "Belum ada kursus" << endl;
    } else {
        tampilDaftarKursusRekursif(kursus, jumlahKursus, 0);
    }
}

void tampilKursusDiambil(Kursus kursusDiambil[], int jumlahDiambil) {
    tampilHeader("Kursus yang Diambil");
    if (jumlahDiambil == 0) {
        cout << "Belum mengambil kursus" << endl;
    } else {
        for (int i = 0; i < jumlahDiambil; i++) {
            cout << i + 1 << ". "
                 << kursusDiambil[i].id << " - "
                 << kursusDiambil[i].nama << " - "
                 << kursusDiambil[i].instruktur << endl;
        }
    }
}

void tambahKursus(Kursus kursus[], int &jumlahKursus) {
    Kursus k;
    bool sudahAda = false;

    tampilHeader("Tambah Kursus");
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
        return;
    }

    cin.ignore();
    cout << "Nama Kursus : ";
    getline(cin, k.nama);

    cout << "Instruktur  : ";
    getline(cin, k.instruktur);

    kursus[jumlahKursus] = k;
    jumlahKursus++;
    cout << "Kursus berhasil ditambahkan" << endl;
}

void ubahKursus(Kursus kursus[], int jumlahKursus) {
    string idCari, namaBaru, instrukturBaru;

    tampilHeader("Ubah Kursus");
    cout << "Masukkan ID Kursus yang ingin diubah : ";
    cin >> idCari;
    cin.ignore();

    int index = cariIndexKursus(kursus, jumlahKursus, idCari);

    if (index != -1) {
        cout << "Data lama : "
             << kursus[index].id << " - "
             << kursus[index].nama << " - "
             << kursus[index].instruktur << endl;

        cout << "Masukkan nama kursus baru : ";
        getline(cin, namaBaru);

        cout << "Masukkan instruktur baru  : ";
        getline(cin, instrukturBaru);

        kursus[index].nama = namaBaru;
        kursus[index].instruktur = instrukturBaru;

        cout << "Data kursus berhasil diubah" << endl;
    } else {
        cout << "Kursus tidak ditemukan" << endl;
    }
}

void hapusKursus(Kursus kursus[], int &jumlahKursus) {
    string id;

    tampilHeader("Hapus Kursus");
    cout << "Masukkan ID Kursus : ";
    cin >> id;

    int index = cariIndexKursus(kursus, jumlahKursus, id);

    if (index != -1) {
        for (int j = index; j < jumlahKursus - 1; j++) {
            kursus[j] = kursus[j + 1];
        }
        jumlahKursus--;
        cout << "Kursus berhasil dihapus" << endl;
    } else {
        cout << "Kursus tidak ditemukan" << endl;
    }
}

void daftarKursusUser(Kursus kursus[], int jumlahKursus, Kursus kursusDiambil[], int &jumlahDiambil) {
    int pilih;

    tampilHeader("Daftar Kursus");
    if (jumlahKursus == 0) {
        cout << "Belum ada kursus." << endl;
        return;
    }

    tampilDaftarKursus(kursus, jumlahKursus);

    cout << "Pilih nomor kursus : ";
    cin >> pilih;

    if (pilih < 1 || pilih > jumlahKursus) {
        cout << "Pilihan tidak valid" << endl;
        return;
    }

    if (cekKursusSudahDiambil(kursusDiambil, jumlahDiambil, kursus[pilih - 1].id)) {
        cout << "Kursus sudah diambil" << endl;
    } else {
        kursusDiambil[jumlahDiambil] = kursus[pilih - 1];
        jumlahDiambil++;
        cout << "Berhasil mendaftar kursus" << endl;
    }
}

void menuAdmin(Kursus kursus[], int &jumlahKursus) {
    int menu;
    do {
        tampilHeader("MENU ADMIN");
        cout << "1. Lihat Kursus" << endl;
        cout << "2. Tambah Kursus" << endl;
        cout << "3. Ubah Kursus" << endl;
        cout << "4. Hapus Kursus" << endl;
        cout << "5. Logout" << endl;
        cout << "Pilih : ";
        cin >> menu;

        switch (menu) {
            case 1:
                tampilDaftarKursus(kursus, jumlahKursus);
                break;
            case 2:
                tambahKursus(kursus, jumlahKursus);
                break;
            case 3:
                ubahKursus(kursus, jumlahKursus);
                break;
            case 4:
                hapusKursus(kursus, jumlahKursus);
                break;
            case 5:
                cout << "Logout..." << endl;
                break;
            default:
                cout << "Menu tidak valid" << endl;
        }
    } while (menu != 5);
}

void menuUser(Kursus kursus[], int jumlahKursus, Kursus kursusDiambil[], int &jumlahDiambil) {
    int menu;
    do {
        tampilHeader("MENU USER");
        cout << "1. Lihat Kursus" << endl;
        cout << "2. Daftar Kursus" << endl;
        cout << "3. Lihat Kursus yang Diambil" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilih : ";
        cin >> menu;

        switch (menu) {
            case 1:
                tampilDaftarKursus(kursus, jumlahKursus);
                break;
            case 2:
                daftarKursusUser(kursus, jumlahKursus, kursusDiambil, jumlahDiambil);
                break;
            case 3:
                tampilKursusDiambil(kursusDiambil, jumlahDiambil);
                break;
            case 4:
                cout << "Logout..." << endl;
                break;
            default:
                cout << "Menu tidak valid" << endl;
        }
    } while (menu != 4);
}

int main() {
    Kursus kursus[100] = {
        {"K001", "Dasar C++", "Pak Budi"},
        {"K002", "Dasar Python", "Bu Sari"},
        {"K003", "Web Programming", "Pak Andi"}
    };
    int jumlahKursus = 3;

    Kursus kursusDiambil[100];
    int jumlahDiambil = 0;

    User users[100] = {
        {"ameng", "035", "admin"},
        {"user", "123", "user"}
    };
    int jumlahUser = 2;

    string username, password, role;
    int percobaanLogin;

    while (true) {
        percobaanLogin = 0;
        bool loginBerhasil = false;

        while (percobaanLogin < 3) {
            tampilHeader("LOGIN");
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;

            if (username == "0" && password == "0") {
                cout << "Program selesai." << endl;
                return 0;
            }

            loginBerhasil = login(users, jumlahUser, username, password, role);

            if (loginBerhasil) {
                break;
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

        if (role == "admin") {
            menuAdmin(kursus, jumlahKursus);
        } else if (role == "user") {
            menuUser(kursus, jumlahKursus, kursusDiambil, jumlahDiambil);
        }
    }

    return 0;
}