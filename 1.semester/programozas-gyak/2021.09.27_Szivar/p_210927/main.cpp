#include <iostream>

using namespace std;

struct AllatT {
    string nev;
    int lab;
};

int main()
{
    cout << "Allatkert" << endl;


    /// Deklaracio
    const int MaxN = 1000;
    int osszLab = 0;
    int N;
    string s[MaxN];
    const int M = 4;
    const AllatT allatok[M] = {{"m", 4}, {"t", 4}, {"k", 0}, {"p", 2}};

    /// Bemenet
//    N = 2;
//    s[0] = "m";
//    s[1] = "p";

    string tmp;
    bool hiba = false;

    do {
        cout << "Hany allatot lattal? : ";
        cin >> tmp;
        N = atoi(tmp.c_str());
        hiba = (((N == 0) && (tmp != "0")) || (N < 0));
        if (hiba) {
            cerr << "HIBA! Pozitiv egesz szamot adj meg!" << endl;
        }
    } while (hiba);


    //TODO ellenorizni: N>=0, egesz szam.



    for (int i = 0; i < N; ++i) {
        do {
            cout << "Mi volt a(z) " << (i + 1) << ". allat?" << endl;
            cin >> s[i];

            int j = 0;
            while ((j < M) && (s[i] != allatok[j].nev)) {
                j++;
            }
            hiba = (j >= M);
            if (hiba) {
                cerr << "HIBA! Ismeretlen allat!" << endl;
            }
        } while (hiba);
    }


    /// Algoritmus implementalas
    for (int i = 0; i < N; ++i) {
        int j = 0;
        while (s[i] != allatok[j].nev) {
            ++j;
        }
        osszLab += allatok[j].lab;
    }

    /// Kimenet
    cout << "Labak szama osszesen: " << osszLab << endl;


    return 0;
}
