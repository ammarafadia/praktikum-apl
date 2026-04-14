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

void tampilDaftarKursus(Kursus kursus[], int jumlahKursus) {
    tampilHeader("Daftar Kursus");
    for (int i = 0; i < jumlahKursus; i++) {
        cout << i + 1 << ". ";
        tampilKursusPointer(&kursus[i]);
    }
}

void tambahKursus(Kursus *kursus, int *jumlahKursus) {
    Kursus k;
    tampilHeader("Tambah Kursus");

    cout << "ID Kursus   : ";
    cin >> k.id;
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

void bubbleSortNama(Kursus kursus[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (kursus[j].nama > kursus[j + 1].nama) {
                Kursus temp = kursus[j];
                kursus[j] = kursus[j + 1];
                kursus[j + 1] = temp;
            }
        }
    }
    cout << "Sorting Nama (A-Z) selesai\n";
}

void selectionSortIDDesc(Kursus kursus[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (kursus[j].id > kursus[maxIndex].id) {
                maxIndex = j;
            }
        }
        Kursus temp = kursus[i];
        kursus[i] = kursus[maxIndex];
        kursus[maxIndex] = temp;
    }
    cout << "Sorting ID (Descending) selesai\n";
}

void insertionSortInstruktur(Kursus kursus[], int n) {
    for (int i = 1; i < n; i++) {
        Kursus key = kursus[i];
        int j = i - 1;

        while (j >= 0 && kursus[j].instruktur > key.instruktur) {
            kursus[j + 1] = kursus[j];
            j--;
        }
        kursus[j + 1] = key;
    }
    cout << "Sorting Instruktur (A-Z) selesai\n";
}

void menuAdmin(Kursus kursus[], int &jumlahKursus) {
    int menu;
    do {
        tampilHeader("MENU ADMIN");
        cout << "1. Lihat\n2. Tambah\n3. Ubah\n4. Hapus\n";
        cout << "5. Sort Nama (A-Z)\n";
        cout << "6. Sort ID (Desc)\n";
        cout << "7. Sort Instruktur\n";
        cout << "8. Logout\n";
        cout << "Pilih: ";
        cin >> menu;

        switch (menu) {
            case 1: tampilDaftarKursus(kursus, jumlahKursus); break;
            case 2: tambahKursus(kursus, &jumlahKursus); break;
            case 3: ubahKursus(kursus, jumlahKursus); break;
            case 4: hapusKursus(kursus, &jumlahKursus); break;
            case 5: bubbleSortNama(kursus, jumlahKursus); break;
            case 6: selectionSortIDDesc(kursus, jumlahKursus); break;
            case 7: insertionSortInstruktur(kursus, jumlahKursus); break;
        }
    } while (menu != 8);
}

int main() {
    Kursus kursus[100] = {
        {"K001", "Dasar C++", "Pak Budi"},
        {"K002", "Dasar Python", "Bu Sari"},
        {"K003", "Web Programming", "Pak Andi"}
    };
    int jumlahKursus = 3;

    User users[100] = {
        {"ameng", "035", "admin"},
        {"user", "123", "user"}
    };

    string username, password, role;

    int percobaan = 0;

    while (true) {
        tampilHeader("LOGIN");

        if (percobaan == 3) {
            cout << "Akses ditolak! Terlalu banyak percobaan.\n";
            break;
        }

        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;

        if (login(users, 2, username, password, role)) {
            percobaan = 0;

            if (role == "admin") {
                menuAdmin(kursus, jumlahKursus);
            }
        } else {
            cout << "Login gagal\n";
            percobaan++;
        }
    }
}