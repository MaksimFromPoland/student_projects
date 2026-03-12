#include <iostream>
#include <vector>  
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
using namespace std;
using namespace chrono;

class hero
{
public:
    string imie;
    int hp;
    int ataka;
};

class warior : public hero 
{
public:
    void setWarior(string i, int h, int a)
    {
        imie = i;
        hp = h;
        ataka = a;
    }
};

class mage : public hero
{
private:
    int fireBallAtak;
public:
    void setMage(string i, int h, int a, int f)
    {
        imie = i;
        hp = h;
        ataka = a;
        fireBallAtak = f;
    }
};

class paladin : public hero
{
private:
    int shilde;
public:
    void setPaladin(string i, int h, int a, int s)
    {
        imie = i;
        hp = h;
        ataka = a;
        shilde = s;
    }
};

int main() 
{
    int wybor, wyborFight1, wyborFight2, wyborGra;
    vector <warior> gracz1W;
    vector <warior> gracz2W;
    vector <mage> gracz1M;
    vector <mage> gracz2M;
    vector <paladin> gracz1P;
    vector <paladin> gracz2P;

    warior w;
    w.setWarior("Warior", 5000, 800);
    mage m;
    m.setMage("Mage", 3000, 1100, 500);
    paladin p;
    p.setPaladin("Paladin", 6000, 500, 600);

    cout << "===== WITAMY W GRIE 'HEROSE' =====\n";
    cout << "Wybierz opcje:\n";
    cout << "1. Rozpoczac gru.\n";
    cout << "2. Wyjszc z programmu.\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        do
        {
            cout << "Wybierz bochatera za ktorego bedzie grac pierwszy zawodnik:\n";
            cout << "1. Warrior\n";
            cout << "2. Mage\n";
            cout << "3. Paladin\n";
            cin >> wyborFight1;

            switch (wyborFight1)
            {
            case 1:
                gracz1W.push_back(w);
                break;

            case 2:
                gracz1M.push_back(m);
                break;

            case 3:
                gracz1P.push_back(p);
                break;

            default:
                cout << "Niepoprawna opcja!\n";
                break;
            }
        } while (wyborFight1 != 1 && wyborFight1 != 2 && wyborFight1 != 3);

        do
        {
            cout << "Wybierz bochatera za ktorego bedzie grac drugi zawodnik:\n";
            cout << "1. Warrior\n";
            cout << "2. Mage\n";
            cout << "3. Paladin\n";
            cin >> wyborFight2;

            switch (wyborFight2)
            {
            case 1:
                gracz2W.push_back(w);
                break;

            case 2:
                gracz2M.push_back(m);
                break;

            case 3:
                gracz2P.push_back(p);
                break;

            default:
                cout << "Niepoprawna opcja!\n";
                break;
            }
        } while (wyborFight2 != 1 || wyborFight2 != 2 || wyborFight2 != 3);

        cout << "Chodzi pierwszy zawodnik.\n";
        cout << "Co chcesz zrobic:\n";
        cout << "1. Atakowac poprostu\n";
        cout << "2. Atakowac z uzywaniem specjalnej ataki\n";
        cin >> wyborGra;
        cout << endl;

        if (wyborGra == 1)
        {
            if (!gracz1W.empty())
            {
                if (!gracz2W.empty())
                {
                    gracz2W[0].hp -= gracz1W[0].ataka;
                    cout << "HP przeciwnika: " << gracz2W[0].hp << endl;
                    cout << endl;
                }
                else if (!gracz2M.empty())
                {
                    gracz2M[0].hp -= gracz1W[0].ataka;
                    cout << "HP przeciwnika: " << gracz2M[0].hp << endl;
                    cout << endl;
                }
                else if (!gracz2P.empty())
                {

                }
            }
            else if (!gracz1M.empty())
            {

            }
            else if (!gracz2P.empty())
            {

            }

        }





        break;

    case 2:
        break;

    default:
        cout << "Niepoprawna opcja\n";
        break;
    }

    return 0;
}
