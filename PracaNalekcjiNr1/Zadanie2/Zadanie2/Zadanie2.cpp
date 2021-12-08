#include <iostream>
#include <string>
#include <utility>
using namespace std;
class Cypher {
public:
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

	string dwa(string t) {
		string c = cezar(t);
		c = przestawieniowy(c);
		return c;
	}
};

class Decypher {
public:
	void odszyfrowanie(string t) {
		string odszyfrowane;
		for (int i = 1; i < 27; i++) {
			odszyfrowane = t;
			for (int k = 0; k < t.length(); k++) {
				if (t[k] == 32) {
					continue;
				}
				else if (t[k] - i < 97) {
					odszyfrowane[k] = 122 - (96 - (odszyfrowane[k] - i));
				}
				else {
					odszyfrowane[k] = odszyfrowane[k] - i;
				}
			}
			cout << odszyfrowane << endl;
		}
	}
};

pair <int, int> publicKey;
pair <int, int> privateKey;

void generatorRSA() {
	int p = 3;
	int q = 5;
	int n = p * q;
	int eul = (p - 1) * (q - 1);
	int e = 7;
	int d = 0;
	for(;;)
	{
		if ((d * e) % eul == 1) {
			if (!(d == e)) {
				break;
			}
		}
		d++;
	}
	publicKey = make_pair(n, e);
	privateKey = make_pair(n, d);
}

int main()
{
	string tekst;
	Cypher obiekt1;
	Decypher obiekt2;

	cout << "Podaj tekst na ktorym bedziesz pracowac: [Z malych liter!] \n";
	getline(cin, tekst);

	cout << "WYBIERZ CO CHCESZ ZROBIC: \n";
	cout << "1. Szyfr cezara\n";
	cout << "2. Szyfr przestawieniowy\n";
	cout << "3. Oba szyfry\n";
	cout << "4. Odszyfruj tekst\n";
	cout << "5. Utworz klucze RSA\n";

	int x;
	cin >> x;
	switch (x) {
	case 1:
		cout << obiekt1.cezar(tekst);
		break;
	case 2:
		cout << obiekt1.przestawieniowy(tekst);
		break;
	case 3:
		cout << obiekt1.dwa(tekst);
		break;
	case 4:
		obiekt2.odszyfrowanie(tekst);
		break;
	case 5:
		generatorRSA();
		cout << "Publiczny: n-> " << publicKey.first << " e-> " << publicKey.second << endl;
		cout << "Prywatny: n-> " << privateKey.first << " d-> " << privateKey.second << endl;
		break;
	}
}
