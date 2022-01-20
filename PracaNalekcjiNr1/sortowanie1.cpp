// Julia Podolak 3a

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class sort {
public:

	vector<int>liczby;
	vector<int>::iterator it;

	void losowe() {
		cout << "Wprowadzanie losowych liczb" << endl;
		srand(time(NULL));
		for (int i = 0; i < 101; i++)
		{
			liczby.push_back(rand() % 1000);
		}
	}

	void bubble() {
		bool swapp = true;
		while (swapp)
		{
			swapp = false;
			for (int i = 0; i < liczby.size() - 1; i++)
			{
				if (liczby[i] > liczby[i + 1])
				{
					liczby[i] += liczby[i + 1];
					liczby[i + 1] = liczby[i] - liczby[i + 1];
					liczby[i] -= liczby[i + 1];
					swapp = true;
				}
			}
		}
	}
	void stawianie() {
		int i, key, j;
		for (i = 1; i < liczby.size() - 1; i++)
		{
			key = liczby[i];
			j = i - 1;

			
			while (j >= 0 && liczby[j] > key)
			{
				liczby[j + 1] = liczby[j];
				j = j - 1;
			}
			liczby[j + 1] = key;
		}
	}

	void wypisywanie() {
		for (int i = 0; i < liczby.size() - 1; i++)
		{
			cout << i <<". = " << liczby[i] << endl;
		}
	}
	
};

int main()
{
	sort s1;



	cout << "1 = sortowanie babelkowe" << endl;
	cout << "2 = wstawianie" << endl;
	int wybor;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << "przed" << endl;
			s1.losowe();
			s1.wypisywanie();
			cout << "po" << endl;
			s1.bubble();
			s1.wypisywanie();
			break;
		case 2:
			cout << "przed" << endl;
			s1.losowe();
			s1.wypisywanie();
			cout << "po" << endl;
			s1.stawianie();
			s1.wypisywanie();
			break;
		default:
			cout << "niepoprawna opcja" << endl;
			break;
		};
}
