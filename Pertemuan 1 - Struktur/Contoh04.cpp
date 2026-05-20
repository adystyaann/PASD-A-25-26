#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
	int dita_i;
	char *dita_namaku, dita[4] = {'D','I','T','A'};
	cout << " Namaku " << endl;
	cout << "~~~~~~~~" << endl;
	for(dita_i=0; dita_i<4; dita_i++){
		dita_namaku = &dita[dita_i];
		cout << " " << *dita_namaku << endl;
	}
	cin.get();
}