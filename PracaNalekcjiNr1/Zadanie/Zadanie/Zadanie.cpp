#include <iostream>
#include <string>

using namespace std;

string cezar(string t) {
	cout << "Podaj wartosc przesuniecia: \n";
	int w;
	for (;;) {
		cin >> w;
		if (!(w > 0 && w < 27)) {
			cout << "Podales zla wartosc\n";
		}
		else {
			break;
		}
	}

	for (int i = 0; i < t.length(); i++) {
		if (t[i] == 32) {
			continue;
		}
		else if (t[i] + w > 122) {
			t[i] = 96 + ((t[i] + w) - 122);
		}
		else {
			t[i] = t[i] + w;
		}
	}

	return t;
}

string przestawieniowy(string t) {
	for (int i = 0; i < t.length(); i = i + 2) {
		if (i + 2 > t.length()) {
			break;
		}
		else {
			swap(t[i], t[i + 1]);
		}
	}
	return t;
}

int main()
{
	string tekst;

	cout << "Podaj tekst na ktorym bedziesz pracowac: [Z malych liter!] \n";
	getline(cin, tekst);

	cout << "WYBIERZ CO CHCESZ ZROBIC: \n";
	cout << "1. Szyfr cezara\n";
	cout << "2. Szyfr przestawieniowy\n";
	cout << "3. Oba szyfry\n";
	cout << "4. Odszyfruj tekst\n";

	int x;
	cin >> x;
	switch (x) {
	case 1:
		cout << cezar(tekst);
		break;
	case 2:
		cout << przestawieniowy(tekst);
		break;
	}

}