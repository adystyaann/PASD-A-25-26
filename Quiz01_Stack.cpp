#include <iostream>
using namespace std;

//Deklarasi struktur data nilai MK
typedef struct {
    int kode_buku;
    string judul_buku;
    string pengarang;
} DataBuku;


//Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
    DataBuku Kontainer;
    alamatelm next;
} elemen;


//Deklarasi struktur stack
typedef struct {
    elemen* top;
} stack;


//Deklarasi fungsi membuat stack kosong
void buatSTkosong(stack *S) {
    (*S).top = NULL;
}


//5. Deklarasi fungsi membuat stack Kosong
int isKosong(stack S) {
    bool hasil = false;

    if(S.top == NULL) {
        hasil = true;
    }
    return hasil;
}


//6. Deklarasi fungsi menghitung jumlah elemen Stack
int jmlElemen(stack S) {
    int hasil = 0;

    if(S.top != NULL) {
        //Kondisi Stack Tidak Kosong
        elemen *bantu;
        //inisialisasi
        bantu = S.top;

        while(bantu != NULL) {
            hasil = hasil + 1;
            //iterasi
            bantu = bantu->next;
        }
    }
    return hasil;
}


//7. Deklarasi fungsi memasukkan elemen ke dalam stack
void push(int kode_buku, string judul_buku, string pengarang, stack *S) {
    elemen *info;
    info = new elemen;
    info->Kontainer.kode_buku = kode_buku;
    info->Kontainer.judul_buku = judul_buku;
    info->Kontainer.pengarang = pengarang;

    if((*S).top == NULL) {
        
        //jika stack kosong
        info->next = NULL;
    }
    else {
        //jika stack tidak kosong
        info->next = (*S).top;
    }
    (*S).top = info;
    info = NULL;
}


//8. Deklarasi fungsi mengeluarkan elemen keluar stack
void Pop(stack *S) {
    if((*S).top != NULL) {
        //jika list bukan stack kosong
        elemen *hapus = (*S).top;

        if(jmlElemen(*S) == 1) {
            //jika stack tidak kosong
            (*S).top = NULL;
        }
        else {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        delete hapus;
    }
    else {
        
    }
}


//9. Deklarasi fungsi menampilkan isi stack
void CetakStack(stack S) {
    if(S.top != NULL) {
        cout << "TUMPUKKAN BUKU SAAT INI" << endl;
        elemen *bantu = S.top;
        int i = 1;

        while(bantu != NULL) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Kode buku 	: " << bantu->Kontainer.kode_buku << endl;
            cout << "Judul Buku      : " << bantu->Kontainer.judul_buku<< endl;
            cout << "pengarang      	: " << bantu->Kontainer.pengarang<< endl;

            //iterasi
            bantu = bantu->next;
            i = i + 1;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    else {
        cout << "Stack Kosong " << endl;
    }
}


//Menu Utama
int main() {
    stack S;

    buatSTkosong(&S);
    CetakStack(S);
    cout << endl;
    cout << endl;

    cout << "============================================" << endl;
    push(01, "Bumi", "tere liye", &S);
    push(01, "Hujan", "tere liye", &S);
	push(01, "Matahari", "tere liye", &S);

    CetakStack(S);
    cout << "============================================" << endl;
    cout << endl;
    cout << endl;

    Pop(&S);
    CetakStack(S);
    cout << endl;
    cout << endl;

    Pop(&S);
    CetakStack(S);
    cout << "============================================" << endl;

    return 0;
}