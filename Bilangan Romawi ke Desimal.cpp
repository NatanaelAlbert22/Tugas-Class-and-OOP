#include <iostream>
using namespace std;

class romanType {
	private:
		int hasil = 0;
		int cek = 1;
	
	public:
		void checker(string);
		void converter(string);
		void print();	
};

void romanType::checker(string romawi) {
	for (int i = 0; i < romawi.size(); i++) {
		if (romawi[i] != 'M' && romawi[i] != 'D' && romawi[i] != 'C' && romawi[i] != 'L' && romawi[i] != 'X' && romawi[i] != 'V' && romawi[i] != 'I') {
			cout << "Input bukan bilangan romawi yang benar";
			cek = 0;
			break;
		}
		if (romawi[i] != 'M' && romawi[i] == romawi[i+1] && romawi[i] == romawi[i+2] && romawi[i] == romawi[i+3]) {
		    cout << "Input bukan bilangan romawi yang benar";
			cek = 0;
			break;
		}
	}
	
} 

void romanType::converter(string romawi) {
	for (int i = 0; i < romawi.size(); i++) {
	   	if (romawi[i] == 'M') {
			hasil += 1000;
		} else if (romawi[i] == 'D') {
			hasil += 500;
		} else if (romawi[i] == 'C') {
			if (romawi[i+1] == 'M') {
				hasil += 900;
				i++;
			} else if (romawi[i+1] == 'D') {
				hasil += 400;
				i++;
			} else {
				hasil += 100;
			}
		} else if (romawi[i] == 'L') {
			hasil += 50;
		} else if (romawi[i] == 'X') {
			if (romawi[i+1] == 'C') {
				hasil += 90;
				i++;
			} else if (romawi[i+1] == 'L') {
				hasil += 40;
				i++;
			} else {
				hasil += 10;
			}
		} else if (romawi[i] == 'V') {
			hasil += 5;
		} else if (romawi[i] == 'I') {
			if (romawi[i+1] == 'X') {
				hasil += 9;
				i++;
			} else if (romawi[i+1] == 'V') {
				hasil += 4;
				i++;
			} else {
				hasil += 1;
			}
		}
	}
}

void romanType::print() {
	if (cek == 1)
	    cout << "Keluaran bilangan desimal\t: " << hasil;
}

int main () {
	string input;
	cout << "Masukkan bilangan romawi\t: ";
	cin >> input;
	
	romanType hasil;
	hasil.checker(input);
    hasil.converter(input);
	hasil.print();
	
	return 0;
}
