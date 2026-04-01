#include <iostream>
#include <string>
using namespace std;

int main(){
	//Deklarasi STRUKTUR
	struct BUKU{
		string dita_judul;
		int dita_tahun;
		string dita_pengarang;
		float dita_harga;
	};
	
	//Pendefinisian STRUKTUR
	BUKU Data_BK;
	
	//Pengaksesan anggota struktur
	Data_BK.dita_judul = "Hujan";
	Data_BK.dita_tahun = 2015;
	Data_BK.dita_pengarang = "Tere Liye";
	Data_BK.dita_harga = 99000;
	cout << endl;
	cout << endl;
	cout << "Judul Buku	= " << Data_BK.dita_judul << endl;
	cout << "Pengarang	= " << Data_BK.dita_pengarang << endl;
	cout << "Tahun		= " << Data_BK.dita_tahun << endl;
	cout << "Harga		= " << Data_BK.dita_harga << endl;
	cin.get();
}