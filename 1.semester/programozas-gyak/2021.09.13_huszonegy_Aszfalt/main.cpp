#include <iostream>

using namespace std;

int main()
{
    cerr << "21-es kartyajatek ertek" << endl;

    /// Deklaracio
    string kartya;
    const string kartyak[8] = {"7", "8", "9", "t", "a", "f", "k", "A"};
    const int ertekek[8] = {7, 8, 9, 10, 2, 3, 4, 11};

    int ertek;

    /// Beolvasas
    cerr << "Milyen kartyad van? : ";
    cin >> kartya;
    int i = 0;
    while (i < 8 && kartya != kartyak[i])
    {
        i++;
    }
    if (i >= 8)
    {
        cerr << "HIBA! Nem jo a kartya azonositoja." << endl;
        exit(1);
    }

    /// Algoritmus inmplementalasa
    i = 0;
    while (kartya != kartyak[i])
    {
        i++;
    }
    ertek = ertekek[i];

    /// Kiiras
    cerr << "A kartyad erteke: ";
    cout << ertek << endl;

    return 0;
}
