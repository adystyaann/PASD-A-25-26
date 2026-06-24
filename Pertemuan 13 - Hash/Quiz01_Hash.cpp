#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int HASHSIZE = 200;

struct HashData {
    char kode[50];
    char nama[100];
};

HashData* hashTable[HASHSIZE];

// ==========================================
// Inisialisasi tabel hash
// ==========================================
void Clear() {
    for(int i = 0; i < HASHSIZE; i++) {
        hashTable[i] = NULL;
    }
}

// ==========================================
// Fungsi Hash
// ==========================================
int hashFunction(const char kode[]) {
    int value = 0;

    for(int i = 0; kode[i] != '\0'; i++) {
        value += kode[i];
    }

    return value % HASHSIZE;
}

// ==========================================
// Insert dengan Linear Probing
// ==========================================
void insert(HashData *data) {

    int rec = hashFunction(data->kode);
    int start = rec;

    while(hashTable[rec] != NULL) {

        if(strcmp(hashTable[rec]->kode, data->kode) == 0) {
            cout << "KodeMK sudah ada!" << endl;
            return;
        }

        rec = (rec + 1) % HASHSIZE;

        if(rec == start) {
            cout << "Hash Table penuh!" << endl;
            return;
        }
    }

    hashTable[rec] = data;

    cout << "\nData berhasil disimpan." << endl;
    cout << "Indeks penyimpanan : " << rec << endl;
}

// ==========================================
// Cari indeks data
// ==========================================
int searchIndex(const char kode[]) {

    int rec = hashFunction(kode);
    int start = rec;

    while(hashTable[rec] != NULL) {

        if(strcmp(hashTable[rec]->kode, kode) == 0) {
            return rec;
        }

        rec = (rec + 1) % HASHSIZE;

        if(rec == start)
            break;
    }

    return -1;
}

// ==========================================
// Searching
// ==========================================
void searching() {

    char kode[50];

    cout << "Masukkan KodeMK : ";
    cin >> kode;

    int rec = searchIndex(kode);

    if(rec != -1) {

        cout << "\nData ditemukan!" << endl;
        cout << "KodeMK     : "
             << hashTable[rec]->kode << endl;

        cout << "Matakuliah : "
             << hashTable[rec]->nama << endl;
    }
    else {
        cout << "\nData tidak ditemukan!" << endl;
    }
}

// ==========================================
// Delete
// ==========================================
void deleting() {

    char kode[50];

    cout << "Masukkan KodeMK yang akan dihapus : ";
    cin >> kode;

    int rec = searchIndex(kode);

    if(rec != -1) {

        cout << "\nData ditemukan :" << endl;
        cout << "KodeMK     : "
             << hashTable[rec]->kode << endl;

        cout << "Matakuliah : "
             << hashTable[rec]->nama << endl;

        delete hashTable[rec];
        hashTable[rec] = NULL;

        cout << "\nData berhasil dihapus." << endl;
    }
    else {
        cout << "\nData tidak ditemukan!" << endl;
    }
}

// ==========================================
// Display seluruh data
// ==========================================
void DisplayTable() {

    cout << "\n";
    cout << "============================================================" << endl;
    cout << "Indeks\tKodeMK\t\tNama Mata Kuliah" << endl;
    cout << "============================================================" << endl;

    int jumlah = 0;

    for(int i = 0; i < HASHSIZE; i++) {

        if(hashTable[i] != NULL) {

            cout << i
                 << "\t"
                 << hashTable[i]->kode
                 << "\t\t"
                 << hashTable[i]->nama
                 << endl;

            jumlah++;
        }
    }

    cout << "============================================================" << endl;
    cout << "Jumlah data : " << jumlah << endl;
}

// ==========================================
// Main Program
// ==========================================
int main() {

    Clear();

    char menu;

    do {

        system("cls");

        cout << "==================================" << endl;
        cout << "         HASH TABLE MK            " << endl;
        cout << "==================================" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Delete Data" << endl;
        cout << "3. Cari Data" << endl;
        cout << "4. Display Data" << endl;
        cout << "5. Clear Table" << endl;
        cout << "X. Keluar" << endl;
        cout << "==================================" << endl;
        cout << "Pilihan : ";
        cin >> menu;

        switch(menu) {

        case '1':
        {
            HashData *data = new HashData;

            cout << "\nKodeMK     : ";
            cin >> data->kode;

            cin.ignore();

            cout << "Matakuliah : ";
            cin.getline(data->nama, 100);

            insert(data);

            system("pause");
            break;
        }

        case '2':
            deleting();
            system("pause");
            break;

        case '3':
            searching();
            system("pause");
            break;

        case '4':
            DisplayTable();
            system("pause");
            break;

        case '5':
            Clear();
            cout << "\nHash Table berhasil dikosongkan." << endl;
            system("pause");
            break;

        case 'X':
        case 'x':
            cout << "\nProgram selesai." << endl;
            break;

        default:
            cout << "\nMenu tidak tersedia!" << endl;
            system("pause");
        }

    } while(menu != 'x' && menu != 'X');

    return 0;
}