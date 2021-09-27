#include <iostream>

using namespace std;

struct AllatT
{
    string nev;
    int lab;
};

int main()
{
    cout << "Allatkert" << endl;

    /// Deklaracio
    const int maxN = 100;

    const int M = 4;
    const AllatT allatok[M] = {{"m", 4}, {"t", 4}, {"p", 2}, {"k", 0}};

    int N;
    string s[maxN];

    int osszlab = 0;

    /// Beolvasas
    cout << "Hany allatot lattal? ";
    bool hiba = false;
    do {
        string tmp;
        cin >> tmp;
        N = atoi(tmp.c_str());
        hiba = (N < 0 || (N == 0 && tmp != "0"));
        if (hiba){
            cerr << "HIBA! Pozitiv egesz szamot adj meg!" << endl;
        }
    } while (hiba);

    for (int i = 0; i < N; i++) {
        cout << "Mi volt a(z) " << i + 1 << ". allat? ";
        hiba = false;
        do {
            cin >> s[i];
            int j = 0;
            while (s[i] != allatok[j].nev && j < M){
                j++;
            }
            hiba = j >= M;
            if (hiba){
                cerr << "HIBA! A listaban szereplo allatot adj meg!" << endl;
            }
        } while(hiba);
    }

    /// Implem
    for (int i = 0; i < N; i++){
        int j = 0;
        while(s[i] != allatok[j].nev){
            j++;
        }
        osszlab += allatok[j].lab;
    }

    /// kimenet
    cout << "Labak szama osszesen: " << osszlab << endl;

    return 0;
}
