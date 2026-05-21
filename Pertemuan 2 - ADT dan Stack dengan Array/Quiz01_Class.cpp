#include <iostream>
using namespace std;

//Pendeklarasian tipe data baru class Barang
class Barang{
	public:
	int dt_kodebarang;
	char dt_namabarang[30];
	float dt_harga;
};

int main(){
	//Buat variabel brg bertipe data Barang
	Barang brg;
	cout << "Kode Barang		= "; cin >> brg.dt_kodebarang;
	cout << "Nama Barang		= "; cin >> brg.dt_namabarang;
	cout << "Harga			= "; cin >> brg.dt_harga;
	cout << endl;
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "	Data Barang Yang Tersimpan" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	cout << "Kode Barang	= " << brg.dt_kodebarang << endl;
	cout << "Nama Barang	= " << brg.dt_namabarang << endl;
	cout << "Harga		= " << brg.dt_harga << endl;
	
	cin.get();
}