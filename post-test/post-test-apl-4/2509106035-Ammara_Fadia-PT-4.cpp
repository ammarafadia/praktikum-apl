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

void tampilKursusPointer(Kursus *k) {
    cout << k->id << " - " << k->nama << " - " << k->instruktur << endl;
}

void tampilDaftarKursusRekursif(Kursus kursus[], int jumlahKursus, int index) {
    if (index >= jumlahKursus) return;

    cout << index + 1 << ". ";
    tampilKursusPointer(&kursus[index]);

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
            cout << i + 1 << ". ";
            tampilKursusPointer(&kursusDiambil[i]);
        }
    }
}

void tambahKursus(Kursus *kursus, int *jumlahKursus) {
    Kursus k;
    bool sudahAda = false;

    tampilHeader("Tambah Kursus");
    cout << "ID Kursus   : ";
    cin >> k.id;

    for (int i = 0; i < *jumlahKursus; i++) {
        if ((kursus + i)->id == k.id) {
            sudahAda = true;
            break;
        }
    }

    if (sudahAda) {
        cout << "ID sudah ada!" << endl;
        return;
    }

    cin.ignore();
    cout << "Nama Kursus : ";
    getline(cin, k.nama);

    cout << "Instruktur  : ";
    getline(cin, k.instruktur);

    *(kursus + *jumlahKursus) = k;
    (*jumlahKursus)++;

    cout << "Berhasil ditambahkan" << endl;
}

void ubahKursus(Kursus kursus[], int jumlahKursus) {
    string idCari;

    tampilHeader("Ubah Kursus");
    cout << "Masukkan ID : ";
    cin >> idCari;
    cin.ignore();

    int index = cariIndexKursus(kursus, jumlahKursus, idCari);

    if (index != -1) {
        cout << "Data lama: ";
        tampilKursusPointer(&kursus[index]);

        cout << "Nama baru : ";
        getline(cin, kursus[index].nama);

        cout << "Instruktur baru : ";
        getline(cin, kursus[index].instruktur);

        cout << "Berhasil diubah" << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }
}

void hapusKursus(Kursus *kursus, int *jumlahKursus) {
    string id;

    tampilHeader("Hapus Kursus");
    cout << "Masukkan ID : ";
    cin >> id;

    int index = cariIndexKursus(kursus, *jumlahKursus, id);

    if (index != -1) {
        for (int j = index; j < *jumlahKursus - 1; j++) {
            *(kursus + j) = *(kursus + j + 1);
        }
        (*jumlahKursus)--;

        cout << "Berhasil dihapus" << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }
}

void daftarKursusUser(Kursus kursus[], int jumlahKursus, Kursus kursusDiambil[], int &jumlahDiambil) {
    int pilih;

    tampilDaftarKursus(kursus, jumlahKursus);

    cout << "Pilih nomor : ";
    cin >> pilih;

    if (pilih < 1 || pilih > jumlahKursus) {
        cout << "Tidak valid" << endl;
        return;
    }

    if (cekKursusSudahDiambil(kursusDiambil, jumlahDiambil, kursus[pilih - 1].id)) {
        cout << "Sudah diambil" << endl;
    } else {
        kursusDiambil[jumlahDiambil] = kursus[pilih - 1];
        jumlahDiambil++;
        cout << "Berhasil daftar" << endl;
    }
}

void menuAdmin(Kursus kursus[], int &jumlahKursus) {
    int menu;
    do {
        tampilHeader("MENU ADMIN");
        cout << "1. Lihat" << endl;
        cout << "2. Tambah" << endl;
        cout << "3. Ubah" << endl;
        cout << "4. Hapus" << endl;
        cout << "5. Logout" << endl;
        cout << "Pilih: ";
        cin >> menu;

        switch (menu) {
            case 1: tampilDaftarKursus(kursus, jumlahKursus); break;
            case 2: tambahKursus(kursus, &jumlahKursus); break;
            case 3: ubahKursus(kursus, jumlahKursus); break;
            case 4: hapusKursus(kursus, &jumlahKursus); break;
        }
    } while (menu != 5);
}

void menuUser(Kursus kursus[], int jumlahKursus, Kursus kursusDiambil[], int &jumlahDiambil) {
    int menu;
    do {
        tampilHeader("MENU USER");
        cout << "1. Lihat" << endl;
        cout << "2. Daftar" << endl;
        cout << "3. Kursus Diambil" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilih: ";
        cin >> menu;

        switch (menu) {
            case 1: tampilDaftarKursus(kursus, jumlahKursus); break;
            case 2: daftarKursusUser(kursus, jumlahKursus, kursusDiambil, jumlahDiambil); break;
            case 3: tampilKursusDiambil(kursusDiambil, jumlahDiambil); break;
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

    string username, password, role;

    while (true) {
        tampilHeader("LOGIN");
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;

        if (login(users, 2, username, password, role)) {
            if (role == "admin") {
                menuAdmin(kursus, jumlahKursus);
            } else {
                menuUser(kursus, jumlahKursus, kursusDiambil, jumlahDiambil);
            }
        } else {
            cout << "Login gagal" << endl;
        }
    }
}