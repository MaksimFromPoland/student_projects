#include <iostream>
#include <vector>  
#include <string>
#include<chrono>
#include<thread>
#include <fstream>

using namespace std;
using namespace chrono;

class produkt                                                     //Klassa bazowa "Produkt"
{
public:
	int id;
	double cena, mass;
	string nazw;

	void getProd()                                                //funkcja wyprowadzająca produkt na konsolę
	{
		cout << "Produkt: " << nazw << ", cena: " << cena << ", id: " << id << endl;
	}
};

class prodMlecz : public produkt                                  //Produkty mlaczne
{
public:
	void setprodMlecz(int i, double c, string naz)
	{
		id = i;
		cena = c;
		nazw = naz;
	}
};

class prodOW : public produkt                                     //Produkty dla ktorych potrzebno dodac wage(warzywa i owoce)
{
public:
	void setprodOW(int i, double c, string naz, double m)
	{
		id = i;
		cena = c;
		nazw = naz;
		mass = m;
	}
};

class prodMiesne : public produkt                                //Produkty miesne
{
public:
	void setprodMiesne(int i, double c, string naz)
	{
		id = i;
		cena = c;
		nazw = naz;
	}
};

double getSum(const vector<produkt>& koszyk, const vector<prodOW>& koszykOW)       //Podsumowanie rachunku
{
	double sum = 0, sumOW = 0;
	for (auto& p : koszyk)
	{
		sum += p.cena;
	}
	for (auto& p : koszykOW)
	{
		sumOW = sumOW + (p.cena * p.mass);
	}
	return sum + sumOW;
}

int main()
{
	int wybor, wyborP, wyborPR, blik;
	double got, sum = 0, reszta = 0, kilo = 0;
	vector <produkt> lista;      //Lista produktow
	vector <produkt> koszyk;     //Koszyk
	vector <prodOW> koszykOW;    //Koszyk dla produktow potrzebujacych

	prodMlecz p1;                                      //wypełnianie klasy produktami
	p1.setprodMlecz(1, 6.10, "Mleko 3,2%");
	prodMlecz p2;
	p2.setprodMlecz(2, 4.50, "Smietana 18%");
	prodMlecz p3;
	p3.setprodMlecz(3, 4.36, "Twarog (poltlysty)");

	prodOW pOW4;
	pOW4.setprodOW(4, 6.12, "Banany", kilo);
	prodOW pOW5;
	pOW5.setprodOW(5, 4.25, "Jablka", kilo);
	prodOW pOW6;
	pOW6.setprodOW(6, 9.25, "Granat", kilo);
	prodOW pOW7;
	pOW7.setprodOW(7, 2.05, "Ziemnieki", kilo);
	prodOW pOW8;
	pOW8.setprodOW(8, 4.50, "Papryka", kilo);
	prodOW pOW9;
	pOW9.setprodOW(9, 3.40, "Cebula", kilo);

	prodMiesne p10;
	p10.setprodMiesne(10, 5.69, "Parufki");
	prodMiesne p11;
	p11.setprodMiesne(11, 9.76, "Szunka");
	prodMiesne p12;
	p12.setprodMiesne(12, 11.96, "Kilbasa");

	lista.push_back(p1);      //wypełnianie vektora produktami
	lista.push_back(p2);
	lista.push_back(p3);
	lista.push_back(pOW4);
	lista.push_back(pOW5);
	lista.push_back(pOW6);
	lista.push_back(pOW7);
	lista.push_back(pOW8);
	lista.push_back(pOW9);
	lista.push_back(p10);
	lista.push_back(p11);
	lista.push_back(p12);

	cout << "=====WITAMY W SKLEPU PRODUKTOWYM=====\n";
	cout << "      ===NASZ LIST PRODUKTOW===\n";
	cout << "Produkty mleczne:\n";
	p1.getProd();                                      //Wywod listy produktow wykorzystajac funkcje
	p2.getProd();
	p3.getProd();
	cout << endl;
	cout << "Produkty owocowe i warzywowe (cena za kilogramm):\n";
	pOW4.getProd();
	pOW5.getProd();
	pOW6.getProd();
	pOW7.getProd();
	pOW8.getProd();
	pOW9.getProd();
	cout << endl;
	cout << "Produkty miesne:\n";
	p10.getProd();
	p11.getProd();
	p12.getProd();
	cout << endl;

	do
	{
		bool znal = false;
		cout << "Wybierz co chcesz zrobic: \n";
		cout << "1. Dodac produkt do koszyka.\n";
		cout << "2. Usunac produkt z koszyka.\n";
		cout << "3. Obejrzyc koszyk.\n";
		cout << "4. Zobaczyc list produktow.\n";
		cout << "5. Przejdz do kassy, aby zaplacic.\n";
		cout << "Twoja opcja: \n";
		cin >> wybor;

		switch (wybor)
		{
		case 1:                                 //Dodanie produktu do koszyka
			cout << "Wprowadz jaki produkt chcesz dodac (id):";
			cin >> wyborPR;
			for (auto& p : lista)
			{
				if (p.id == wyborPR)
				{
					if (p.id <= 9 && p.id >= 4)
					{
						cout << "Ile kilogramow checesz wziac: ";
						cin >> kilo;
						prodOW prod = (prodOW&)p;
						prod.mass = kilo;
						koszykOW.push_back(prod);
						znal = true;
						cout << "Dodalesz produkt do koszyka.\n";
					}
					else
					{
						koszyk.push_back(p);
						znal = true;
						cout << "Dodalesz produkt do koszyka.\n";
					}
					cout << endl;
					break;
				}
			}
			if (!znal)
			{
				cout << "Nie znalieziono takiego produktu.\n";
			}
			cout << endl;
			break;

		case 2:                    //Usuninie produktu z koszyka
			cout << "Wprowadz jaki produkt chcesz usunac (id):";
			cin >> wyborPR;
			for (auto p = koszyk.begin(); p != koszyk.end(); ++p)
			{
				if (p->id == wyborPR)
				{
					koszyk.erase(p);
					znal = true;
					break;
				}
			}
			for (auto p = koszykOW.begin(); p != koszykOW.end(); ++p)
			{
				if (p->id == wyborPR)
				{
					koszykOW.erase(p);
					znal = true;
					cout << endl;
					break;
				}
			}
			if (!znal)
			{
				cout << "Nie znalieziono takiego produktu.\n";
			}
			cout << endl;
			break;

		case 3:                      //Ogladnie koszyka
			cout << "Twoj koszyk jest: \n";
			for (auto& p : koszyk)
			{
				p.getProd();
			}
			for (auto& p : koszykOW)
			{
				p.getProd();
			}
			cout << endl;
			sum = getSum(koszyk, koszykOW);
			cout << "Summa rachunku jest: " << sum << endl;
			cout << endl;
			break;

		case 4:                     //Ogladanie listy produktow
			cout << "Produkty mleczne:\n";
			p1.getProd();
			p2.getProd();
			p3.getProd();
			cout << endl;
			cout << "Produkty owocowe i warzywowe (cena za kilogramm):\n";
			pOW4.getProd();
			pOW5.getProd();
			pOW6.getProd();
			pOW7.getProd();
			pOW8.getProd();
			pOW9.getProd();
			cout << endl;
			cout << "Produkty miesne:\n";
			p10.getProd();
			p11.getProd();
			p12.getProd();
			cout << endl;
			break;

		case 5:                     //Przejszcie do kasy
			break;

		default:
			cout << "Niepoprawny wybor!\n";
		}
	} while (wybor != 5);

	cout << "Poczekaj na swoja kolej...\n";
	this_thread::sleep_for(seconds(7));      //Symulacja czekania w kolejce
	cout << endl;

	sum = getSum(koszyk, koszykOW);      //Podsumowanie rachunku

	do
	{
		cout << "Suma rachunku jest: " << sum << endl;
		cout << endl;
		cout << "W jaki sposob bedziesz oplacac: \n";
		cout << "1. Karta.\n";
		cout << "2. Gotowka.\n";
		cin >> wybor;

		switch (wybor)
		{
		case 1:                          //Opcja oplaty karta
			do
			{
				cout << "Czym bedzisz oplacac: \n";
				cout << "1. Karta fizyczna.\n";
				cout << "2. Blikiem\n";
				cin >> wyborP;

				if (wyborP == 1)         //Opcja oplaty karta fizyczna
				{
					cout << "Poczekaj na tranzakcje...\n";
					this_thread::sleep_for(seconds(3));    //Symulacja tranzakcji
					cout << "Koszyk zostal oplacony!\n";
				}
				else if (wyborP == 2)   //Opcja oplaty blikiem
				{
					do
					{
						cout << "Wprowadz blik: ";
						cin >> blik;
						if (blik < 100000 || blik > 999999)
						{
							cout << "Blik jest nie poprawny! Sprobuj ponownie.\n";
						}
						else cout << "Koszyk zostal oplacony!\n";
					} while (blik < 100000 || blik > 999999);
				}
				else cout << "Niepoprawna opcja!\n";
			} while (wyborP != 1 && wyborP != 2);
			break;

		case 2:              //Opcja oplaty gotowka
			do
			{
				cout << "Wprowadz sume gotowki:";
				cin >> got;
				if (got == sum)
				{
					cout << "Dzienki za oplate bez reszty :)\n";
				}
				else if (got < sum)
				{
					cout << "Nie wstarczy gotowki!\n";
				}
				else
				{
					reszta = got - sum;
					cout << "Reszta jest: " << reszta << endl;
				}
			} while (got < sum);
			break;

		default:
			cout << "Niepoprawna opcja!\n";
		}
	} while (wybor != 1 && wybor != 2);

	ofstream rachunek("rachunek.txt", ios::app);
	rachunek << "===Rachunek===\n";
	rachunek << "Suma rachunku jest: ";
	rachunek << sum;
	rachunek << "\n";
	if (wybor == 1)
	{
		rachunek << "Rachunek zostal oplacony karta albo blikiem.\n";
		rachunek << "\n";
	}
	else
	{
		rachunek << "Suma podanej gotuwki: ";
		rachunek << got;
		rachunek << "\n";
		rachunek << "Reszta: ";
		rachunek << reszta;
		rachunek << "\n";
		rachunek << "\n";
	}

	cout << "Dzienki za zakupy! Przychodzcie do nas ponowie.\n";
	return 0;
}


