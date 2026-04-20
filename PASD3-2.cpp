#include <studio.h>
#include <iostream>
#include <stdlib.h> //untuk library fungsi malloc
using namespace std;

//Deklarasi fungsi
void dita_BuatSimpul(int dita_X);
void dita_push();
void dita_pop();
void dita_cetak();
void dita_kosong();

//Deklarasi struktur simoul
struct dita_node{
	int dita_info;
	struct dita_node *dita_link;
};

typedef struct dita_node dita_simpul;

//Pointer yang akan menunjuk ke simpul
dita_simpul *dita_top = NULL, *dita_p, *dita_q;
int dita_X;

//Fungsi utama
int main(){
	int dita_pilihan;
	
	do{
		cout << "\n=== MENU STACK ===" << endl;
		cout << "1. PUSH (Tambah Data)" << endl;
		cout << "1. POP (Tambah Data)" << endl;
		cout << "1. CETAK (Tambah Data)" << endl;
		cout << "1. KELUAR (Tambah Data)" << endl;
		cout << "Pilih: " << cin >> dita_pilihan;
		
		switch(dita_pilihan){
			case 1:
			cout << "Masukkan Nilai: "; cin >> dita_X;
			dita_BuatSimpul(dita_X);
			dita_push;
			break;
			
			case 2:
			dita_pop;
			break;
			
			case 3:
			cout << "Isi Stack: "; dita_cetak();
			break;
		}
	}while(dita_pilihan != 4);
	
	cin.get();
}

//Membuat Simpul Baru
void dita_BuatSimpul(dita_X){
	dita_p = (dita_simpul*) malloc(sizeof(dita_simpul));
	
	if(dita_p != NULL){
		dita_p -> dita_info = dita_X;
	}else{
		cout << "Gagal membuat simpul!" << endl;
		exit(1);
	}
}

//Cek stack kosong
int dita_kosong(){
	return (dita_top == NULL);
}

//PUSH (memasukkan stack)
void dita_push(){
	if(dita_kosong()){
		dita_top = dita_p;
		dita_p -> dita_link = NULL;
	}else{
		dita_p -> dita_link = dita_top;
		dita_top = dita_p;
	}
}

//POP (menghapus stack)
void dita_pop(){
	if(dita_kosong()){
		cout << "Stack kosong!" << endl;
	}else{
		dita_q = dita_top;
		dita_top = dita_top -> dita_link;
		cout << "Data dihapus: " << dita_q -> dita_info << endl;
		free(dita_q);
	}
}

//Mencetak isi stack
void dita_cetak(){
	dita_q = dita_top;
	
	if(dita_kosong()){
		cout << "Kosong";
	}
	
	while(dita_q != NULL){
		cout << dita_q -> dita_info << " ";
		dita_q = dita_q -> dita_link;
	}
}