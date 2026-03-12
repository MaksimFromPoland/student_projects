#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class karta
{
public:
    string kolor;
    string wartosc;
    int pointy;
    int id;

    void setKard(string k, string w, int p, int i)
    {
        kolor = k;
        wartosc = w;
        pointy = p;
        id = i;
    }

    void getKard()
    {
        cout << kolor << " " << wartosc << " : " << pointy << endl;
    }
};

class inny : public karta
{
public:
    int pointyD;

    void setKardI(string k, string w, int p, int pD, int i)
    {
        kolor = k;
        wartosc = w;
        pointy = p;
        pointyD = pD;
        id = i;
    }

    void getKardI()
    {
        cout << kolor << " " << wartosc << " : " << pointy << " albo " << pointyD << endl;
    }
};

int s(vector<int>& reka)
{
    int sum = 0;
    for (int p : reka)
    {
        sum += p;
    }
    return sum;
}

int main()
{
    vector<karta> taliaK;
    vector<inny> taliaI;
    vector<int> reka;
    vector<int> rekaDilera;
    int wybor, wyborG, wyborM, card, m = 1, suma = 0, sumaDilera = 0;
    bool znal = false;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 52);
    uniform_int_distribution<> distD(1, 2);

    karta k2;
    k2.setKard("Karo", "2", 2, 1);
    karta k3;
    k3.setKard("Karo", "3", 3, 2);
    karta k4;
    k4.setKard("Karo", "4", 4, 3);
    karta k5;
    k5.setKard("Karo", "5", 5, 4);
    karta k6;
    k6.setKard("Karo", "6", 6, 5);
    karta k7;
    k7.setKard("Karo", "7", 7, 6);
    karta k8;
    k8.setKard("Karo", "8", 8, 7);
    karta k9;
    k9.setKard("Karo", "9", 9, 8);
    karta k10;
    k10.setKard("Karo", "10", 10, 9);

    karta k11;
    k11.setKard("Pik", "2", 2, 10);
    karta k12;
    k12.setKard("Pik", "3", 3, 11);
    karta k13;
    k13.setKard("Pik", "4", 4, 12);
    karta k14;
    k14.setKard("Pik", "5", 5, 13);
    karta k15;
    k15.setKard("Pik", "6", 6, 14);
    karta k16;
    k16.setKard("Pik", "7", 7, 15);
    karta k17;
    k17.setKard("Pik", "8", 8, 16);
    karta k18;
    k18.setKard("Pik", "9", 9, 17);
    karta k19;
    k19.setKard("Pik", "10", 10, 18);

    karta k20;
    k20.setKard("Kier", "2", 2, 36);
    karta k21;
    k21.setKard("Kier", "3", 3, 19);
    karta k22;
    k22.setKard("Kier", "4", 4, 20);
    karta k23;
    k23.setKard("Kier", "5", 5, 21);
    karta k24;
    k24.setKard("Kier", "6", 6, 22);
    karta k25;
    k25.setKard("Kier", "7", 7, 23);
    karta k26;
    k26.setKard("Kier", "8", 8, 24);
    karta k27;
    k27.setKard("Kier", "9", 9, 25);
    karta k28;
    k28.setKard("Kier", "10", 10, 26);

    karta k29;
    k29.setKard("Trefl", "2", 2, 27);
    karta k30;
    k30.setKard("Trefl", "3", 3, 28);
    karta k31;
    k31.setKard("Trefl", "4", 4, 29);
    karta k32;
    k32.setKard("Trefl", "5", 5, 30);
    karta k33;
    k33.setKard("Trefl", "6", 6, 31);
    karta k34;
    k34.setKard("Trefl", "7", 7, 32);
    karta k35;
    k35.setKard("Trefl", "8", 8, 33);
    karta k36;
    k36.setKard("Trefl", "9", 9, 34);
    karta k37;
    k37.setKard("Trefl", "10", 10, 35);

    inny i1;
    i1.setKardI("Trefl", "J", 10, 1, 37);
    inny i2;
    i2.setKardI("Trefl", "Q", 10, 1, 38);
    inny i3;
    i3.setKardI("Trefl", "K", 10, 1, 39);
    inny i4;
    i4.setKardI("Trefl", "A", 11, 1, 40);

    inny i5;
    i5.setKardI("Kier", "J", 10, 1, 41);
    inny i6;
    i6.setKardI("Kier", "Q", 10, 1, 42);
    inny i7;
    i7.setKardI("Kier", "K", 10, 1, 43);
    inny i8;
    i8.setKardI("Kier", "A", 11, 1, 44);

    inny i9;
    i9.setKardI("Pik", "J", 10, 1, 45);
    inny i10;
    i10.setKardI("Pik", "Q", 10, 1, 46);
    inny i11;
    i11.setKardI("Pik", "K", 10, 1, 47);
    inny i12;
    i12.setKardI("Pik", "A", 11, 1, 48);

    inny i13;
    i13.setKardI("Karo", "J", 10, 1, 49);
    inny i14;
    i14.setKardI("Karo", "Q", 10, 1, 50);
    inny i15;
    i15.setKardI("Karo", "K", 10, 1, 51);
    inny i16;
    i16.setKardI("Karo", "A", 11, 1, 52);


    taliaK.push_back(k2);
    taliaK.push_back(k3);
    taliaK.push_back(k4);
    taliaK.push_back(k5);
    taliaK.push_back(k6);
    taliaK.push_back(k7);
    taliaK.push_back(k8);
    taliaK.push_back(k9);
    taliaK.push_back(k10);
    taliaK.push_back(k11);
    taliaK.push_back(k12);
    taliaK.push_back(k13);
    taliaK.push_back(k14);
    taliaK.push_back(k15);
    taliaK.push_back(k16);
    taliaK.push_back(k17);
    taliaK.push_back(k18);
    taliaK.push_back(k19);
    taliaK.push_back(k20);
    taliaK.push_back(k21);
    taliaK.push_back(k22);
    taliaK.push_back(k23);
    taliaK.push_back(k24);
    taliaK.push_back(k25);
    taliaK.push_back(k26);
    taliaK.push_back(k27);
    taliaK.push_back(k28);
    taliaK.push_back(k29);
    taliaK.push_back(k30);
    taliaK.push_back(k31);
    taliaK.push_back(k32);
    taliaK.push_back(k33);
    taliaK.push_back(k34);
    taliaK.push_back(k35);
    taliaK.push_back(k36);
    taliaK.push_back(k37);

    taliaI.push_back(i1);
    taliaI.push_back(i2);
    taliaI.push_back(i3);
    taliaI.push_back(i4);
    taliaI.push_back(i5);
    taliaI.push_back(i6);
    taliaI.push_back(i7);
    taliaI.push_back(i8);
    taliaI.push_back(i9);
    taliaI.push_back(i10);
    taliaI.push_back(i11);
    taliaI.push_back(i12);
    taliaI.push_back(i13);
    taliaI.push_back(i14);
    taliaI.push_back(i15);
    taliaI.push_back(i16);

    cout << "=====BLACKJACK=====\n";

    do
    {
        cout << "1. Zagrac.\n";
        cout << "2. Wyjsc z gry.\n";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            if (taliaK.empty() && taliaI.empty())
            {
                break;
            }

            cout << "Twoje karty: \n";
            m = 1;

            do
            {
                card = dist(gen);
                znal = false;
                int x = 0;
                for (auto& p : taliaK)
                {
                    if (p.id == card)
                    {
                        p.getKard();
                        reka.push_back(p.pointy);
                        znal = true;
                        taliaK.erase(taliaK.begin() + x);
                    }
                    x++;
                }

                if (znal == false)
                {
                    x = 0;
                    for (auto& p : taliaI)
                    {
                        if (p.id == card)
                        {
                            p.getKardI();
                            cout << "Ile pointow chcesz dostac: \n";
                            cout << "1. 10 albo 11\n";
                            cout << "2. 1\n";
                            cin >> wyborG;

                            if (wyborG == 1)
                            {
                                reka.push_back(p.pointy);
                            }
                            else reka.push_back(p.pointyD);

                            znal = true;
                            taliaI.erase(taliaI.begin() + x);
                        }
                        x++;
                    }
                }

                if (znal == true)
                {
                    m++;
                }

            } while (m <= 2);
            cout << endl;

            suma = s(reka);
            cout << "Masz " << suma << " pointow\n";
            cout << endl;

            do
            {
                cout << "Czy chcesz dobierac?\n";
                cout << "1. Tak\n";
                cout << "2. Nie\n";
                cin >> wyborM;
                cout << endl;

                if (wyborM == 1)
                {
                    cout << "Twoja karta jest: \n";

                    do
                    {
                        if (taliaK.empty() && taliaI.empty())
                        {
                            break;
                        }

                        card = dist(gen);
                        znal = false;
                        int x = 0;

                        for (auto& p : taliaK)
                        {
                            if (p.id == card)
                            {
                                p.getKard();
                                reka.push_back(p.pointy);
                                znal = true;
                                taliaK.erase(taliaK.begin() + x);
                            }
                            x++;
                        }

                        if (znal == false)
                        {
                            x = 0;
                            for (auto& p : taliaI)
                            {
                                if (p.id == card)
                                {
                                    p.getKardI();
                                    cout << "Ile pointow chcesz dostac: \n";
                                    cout << "1. 10 albo 11\n";
                                    cout << "2. 1\n";
                                    cin >> wyborG;

                                    if (wyborG == 1)
                                    {
                                        reka.push_back(p.pointy);
                                    }
                                    else reka.push_back(p.pointyD);

                                    znal = true;
                                    taliaI.erase(taliaI.begin() + x);
                                }
                                x++;
                            }
                        }
                    } while (znal == false);
                    cout << endl;

                    suma = s(reka);
                    cout << "Masz " << suma << " pointow\n";
                    cout << endl;
                }

            } while (wyborM != 2);

            if (suma == 21)
            {
                cout << "WYGRALESZ!\n";
                cout << endl;
            }
            else if (suma > 21)
            {
                cout << "W nastepny raz...\n";
                cout << endl;
            }
            else
            {
                m = 1;
                do
                {
                    do
                    {
                        if (taliaK.empty() && taliaI.empty())
                        {
                            break;
                        }

                        card = dist(gen);
                        znal = false;
                        int x = 0;

                        for (auto& p : taliaK)
                        {
                            if (p.id == card)
                            {
                                rekaDilera.push_back(p.pointy);
                                znal = true;
                                taliaK.erase(taliaK.begin() + x);
                            }
                            x++;
                        }

                        if (znal == false)
                        {
                            x = 0;
                            for (auto& p : taliaI)
                            {
                                if (p.id == card)
                                {
                                    int op = distD(gen);
                                    if (op == 1)
                                    {
                                        rekaDilera.push_back(p.pointy);
                                    }
                                    else rekaDilera.push_back(p.pointyD);

                                    znal = true;
                                    taliaI.erase(taliaI.begin() + x);
                                }
                                x++;
                            }
                        }
                    } while (znal == false);
                    m++;

                } while (m <= 3);

                sumaDilera = s(rekaDilera);
                cout << "Pointy dilera: " << sumaDilera << endl;

                if (sumaDilera == 21 || sumaDilera > suma || sumaDilera == suma)
                {
                    cout << "W nastepny raz...\n";
                    cout << endl;
                }
                else
                {
                    cout << "WYGRALESZ!\n";
                    cout << endl;
                }
            }
            break;

        case 2:
            cout << "Dowidzenia!\n";
            break;

        default: cout << "Niepoprawna opcja\n";
            break;
        }

        reka.clear();
        rekaDilera.clear();

    } while (wybor != 2);

    return 0;
}
