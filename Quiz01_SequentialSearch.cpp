#include <iostream>
using namespace std;

int main() {

    int pilihan = 0;
    int jumlah;
    int i;
    int ketemu;

    string kendaraan[100];
    string cari;

    while(pilihan != 3) {

        cout << "\n======================================" << endl;
        cout << "      PROGRAM SEQUENTIAL SEARCH      " << endl;
        cout << "======================================" << endl;
		cout << "	 Pencarian Nomor Kendaraan	" << endl;
		cout << "-------------------------------------" << endl;
        cout << "1. Input Data Kendaraan" << endl;
        cout << "2. Cari Kendaraan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        // 
        if(pilihan == 1) {

            cout << "\nInput jumlah kendaraan : ";
            cin >> jumlah;

            for(i = 0; i < jumlah; i++) {
                cout << "Input nomor kendaraan ke-" << i + 1 << " : ";
                cin >> kendaraan[i];
            }

            cout << "Data berhasil disimpan!" << endl;
        }

        // MENU CARI
        if(pilihan == 2) {

            cout << "\nInput nomor kendaraan yang dicari : ";
            cin >> cari;

            ketemu = 0;

			//Sequential Search
            for(i = 0; i < jumlah; i++) {

                if(kendaraan[i] == cari) {

                    cout << "Kendaraan ditemukan pada index ke-" << i << endl;
                    ketemu = 1;
                }

            }

            if(ketemu == 0) {
                cout << "Data kendaraan tidak ditemukan!" << endl;
            }
        }

        // MENU KELUAR
        if(pilihan == 3) {

            cout << "\nProgram selesai..." << endl;

        }

    }

    return 0;
}