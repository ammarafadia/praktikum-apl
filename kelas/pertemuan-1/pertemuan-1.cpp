// #include <iostream>
// using namespace std;
// int main() {
//     string nama;
//     cout << "Hello, World! " << endl;
//     cout << "Belajar C + sangat seru" << endl;
//     cout << "Masukkan nama kamu: ";
//     getline(cin, nama);
//     cout << "Halo, " << nama;
//     return 0;
// }

#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    for (int x : arr) {
        cout << x << endl;
}
    return 0;
}