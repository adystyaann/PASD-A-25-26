#include <iostream>
using namespace std;

//Deklarasi struktur data nilai MK
typedef struct{
	string nip;
	string nama_karyawan;
	double gaji;
} DataKaryawan;

//Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm{
	DataKaryawan Kontainer;
	alamatelm next;
} elemen;

//Deklarasi struktur queue
typedef struct{
	elemen *first;
	elemen *last;
}queue;

//Deklarasi fungsi membuat queue kosong
void buatQUKosong(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;
}

//Deklarasi fungsi membuat queue
int isKosong(queue Q){
	bool hasil = false;
	
	if(Q.first == NULL){
		hasil = true;
	}
	return hasil;
}

//Deklarasi fungsi menghitung jumlah elemen queue
int jmlElemen(queue Q){
	int hasil = 0;
	
	if(Q.first != NULL){
		//Kondisi Queue tidak kosong
		elemen *bantu;
		
		//Inisialisasi
		bantu = Q.first;
		
		while(bantu != NULL){
			hasil = hasil + 1;
			
			//Interasi
			bantu = bantu -> next;
		}
	}
	return hasil;
}

//Deklarasi fungsi memasukkan elemen ke dalam queue
void add(string nip, string nama_karyawan, double gaji, queue *Q){
	elemen *info;
	info = new elemen;
	info -> Kontainer.nip = nip;
	info -> Kontainer.nama_karyawan = nama_karyawan;
	info -> Kontainer.gaji = gaji;
	info -> next = NULL;
	
	if((*Q).first == NULL){
		(*Q).first = info;
	}else{
		(*Q).last -> next = info;
	}
	(*Q).last = info;
	info = NULL;
}

//Deklarasi fungsi mengeluarkan elemen keluar queue
void del(queue *Q){
	if((*Q).first != NULL){
		//Jika queue bukan queue kosong
		elemen *hapus = (*Q).first;
		
		if(jmlElemen(*Q) == 1){
			(*Q).first = NULL;
			(*Q).last = NULL;
		}else{
			(*Q).first = (*Q).first -> next;
			hapus -> next = NULL;
		}
		delete hapus;
	}
}

//Deklarasi fungsi menampilkan isi queue
void CetakQueue(queue Q){
	if(Q.first != NULL){
		cout << "MENAMPILKAN DATA KARYAWAN" << endl;
		elemen *bantu = Q.first;
		int i = 1;
		while(bantu != NULL){
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Elemen ke		: " << i << endl;
			cout << "NIP			: " << bantu -> Kontainer.nip << endl;
			cout << "Nama Karyawan		: " << bantu -> Kontainer.nama_karyawan << endl;
			cout << "Gaji Karyawan		: " << bantu -> Kontainer.gaji << endl;
			//Iterasi
			bantu = bantu -> next;
			i = i + 1;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}else{
		cout << "Queue Kosong" << endl;
	}
}

int main(){
	queue Q;
	buatQUKosong(&Q);
	CetakQueue(Q);
	cout << endl;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	add("100", "Budi", 240000, &Q);
	add("200", "Susi", 240000, &Q);
	add("300", "Nuri", 240000, &Q);
	add("400", "Bimo", 240000, &Q);
	add("500", "Arif", 240000, &Q);
	add("600", "Rido", 240000, &Q);
	add("700", "Ella", 240000, &Q);
	CetakQueue(Q);
	cout << "===========================" << endl;
	cout << endl;
	cout << endl;
	del(&Q);
	del(&Q);
	CetakQueue(Q);
	cout << "===========================" << endl;
	return 0;
}