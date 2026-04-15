#include <stdio.h>
#include <iostream>
#include <stdlib.h> //untuk library fungsi malloc
#include <string.h>
using namespace std;

void BUAT_SIMPUL(int X);
void AWAL();
void CETAK();
void INSERTKANAN();

//Deklarasi struktur simpul
struct Node{
	int INFO;
	struct Node *LINK;
};

typedef struct Node Simpul;

Simpul *P, *FIRST, *LAST, *Q; //Menyiapkan pointer pointer yang dapat menunjuk ke simpul
int X;

int main(){
	int A[7] = {22,28,7,11,66,63,10}; //Data yang disimpan ke dalam info
	int I;
	
	FIRST = NULL; //Inisialisasi linked list
	I = 0;
	X = A[I];
	
	BUAT_SIMPUL(X);
	AWAL(); //Menyiapkan simpul awal
	
	//Menambahkan 8 simpul baru dan insert kanan agar terbentuk List
	for(I = 1; I <= 6; I++){
		X = A[I];
		BUAT_SIMPUL(X);
		INSERTKANAN();
	}
	
	cout << "Nilai Sebelum Dilakukan Insert Kanan : "; CETAK();
	
	X = 100;
	BUAT_SIMPUL(X);
	INSERTKANAN();	//Menginsert simpul baru disebelah kanan dengan INFO=999
	cout << endl;
	
	cout << "Nilai Setelah Dilakukan Insert Kanan : "; CETAK();
	cout << endl;
	cin.get();
}

//Fungsi membuat sebuah simpul baru
void BUAT_SIMPUL(int X){
	P = (Simpul*) malloc(sizeof(Simpul));
	
	if(P != NULL){
		P -> INFO = X;
	}
	else{
		cout << "Pembuatan Simpul Tidak Berhasil" << endl;
		cin.get();
		exit(1);
	}
}

//Fungsi membuat simpul awal
void AWAL(){
	FIRST = P;
	LAST = P;
	P -> LINK = NULL;
}

//Fungsi menginsert simpul disebelah kanan
void INSERTKANAN(){
	LAST -> LINK = P;
	LAST = P;
	P -> LINK = NULL;
}

//Fungsi mencetak isi seluruh simpul
void CETAK(){
	int X;
	Q = FIRST;
	
	while(Q != NULL){
		X = Q -> INFO;
		cout << " " << X;
		Q = Q -> LINK;
	}
}