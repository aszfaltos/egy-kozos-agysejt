/// Név:
/// Neptun-kód:
/// e-mail:
///
/// Feladat:
///   A keret program segítségével a tanult 6 egyszerű belső rendezés hatékonyságát
///   vizsgáljuk. Végrehajtási idő, tömbelemre vonatkozó hasonlítás- és mozgatás-szám
///   elemszámtól függésére vagyunk kiváncsiak.
///   A program rendező eljárásainak lényegi része hiányzanak, ezt kell pótolni.
///   Ügyeljen arra, hogy a hSzam és az mSzam változókat megfelelően növelje, amikor
///   a rendezés során egy hasonlítást, ill. egy mozgatást hajt végre.

#include <iostream>
#include <windows.h>  //a srand függvényhez, a HANDLE típushoz, a system-hez (pause és a cls DOS-parancsokhoz)
#include <time.h>     //a time és clock függvényekhez
#include <iomanip>    ///a setw-hez
using namespace std;

const int maxN=8001;//a sorozat maximális hossza
const int kiN=120;//a megjelenítendő (rész)sorozat hossza
int s[maxN],r[maxN];//segéd és rendezendő elemek tömbje
int elemSzam;//tényleges elemszám
int kezdet,veg,elteltIdo;//futási idő kezdete, vége, hossza
int hSzam, mSzam;//hasonlítások száma, mozgatások szám

//beolvassa a min..max közötti egész számot (max<min => max=végtelen)
void be_int(string kerdes, int &n, int min, int max, string uzenet);
//feltöltésmód beolvasása:
int feltoltesMod();
//feltöltő eljárások:
void feltoltVeletlennel();
void feltoltNovekedve();
void feltoltCsokkenve();
void feltoltMajdnemRendezve();
//hatékonyságméréshez:
void oraIndul();
void oraAll();
//r-et rendező eljárások:
void egyszeruCseres();
void minimumKivalsztasos();
void buborek();
void javitottBuborek();
void beilleszteses();
void javitottBeilleszteses();
//cout<=r[1..min(kiN,elemSzam)]
void tombKiiras(string cim);
void kiertekeles(string cim);
//r<=s:
void masol();
//billentyű-lenyomásra várakozik:
void billreVar();
//kurzor-pozícionálás a konzol-ablakban:
void curPos(int s, int o);
//képernyőtörlés:
void ujLap();

int main()
{
    srand(time(NULL));//véletlenszám-generátor inicializálása

    //a rendezendő tömb feltöltése:
    be_int("Elemszam:",elemSzam,11,maxN,"Nem jo elemszam!");
    switch (feltoltesMod())
    {
      case 0:
        feltoltNovekedve(); break;
      case 1:
        feltoltCsokkenve(); break;
      case 2:
        feltoltMajdnemRendezve(); break;
      case 3:
        feltoltVeletlennel(); break;
    }
    //a rendezések:
    egyszeruCseres();
    minimumKivalsztasos();
    buborek();
    javitottBuborek();
    beilleszteses();
    javitottBeilleszteses();

    return 0;
}

//beolvassa a min..max közötti egész számot (max<min => max=végtelen)
void be_int(string kerdes, int &n, int min, int max, string uzenet)
{
    bool hiba;
    string tmp;

    do
    {
      if (max>=min)
      {
        curPos(0,0); cout<<setfill(' ')<<setw(80)<<' '; curPos(0,0);
        cout << kerdes << " (" << min << ".." << max << "):"; cin >> n;
        hiba=cin.fail() || cin.peek()!='\n' || n<min || n>max;
      }
        else
      {
        curPos(0,0); cout<<setfill(' ')<<setw(80)<<' '; curPos(0,0);
        cout << kerdes << " (" << min << "..):"; cin >> n;
        hiba=cin.fail() || cin.peek()!='\n' || n<min;
      }
      if (hiba)
      {

        cout<<uzenet+" Mehetunk?\n";
        cin.clear(); getline(cin,tmp,'\n'); //pufferürítés
        getline(cin,tmp,'\n'); //az utzenetre válasz beolvasása
        curPos(1,0); cout<<setfill(' ')<<setw(80)<<' ';
        curPos(2,0); cout<<setfill(' ')<<setw(80)<<' ';
      }
    }
    while(hiba);
}

//feltöltésmód beolvasása:
int feltoltesMod()
{
    int melyik;
    bool hiba; char c;
    string tmp;

    ujLap();
    cout << "Valasszon az alabbi feltoltesmodok kozul:" << endl;
    cout << "0: novekedoen" << endl;
    cout << "1: csokkenve" << endl;
    cout << "2: majdnem (novekedoen) rendezve" << endl;
    cout << "3: veletlenszeruen" << endl;
    cout << "Melyik (0..3): ";
    do
    {
        curPos(5,15); cout << "                             "; curPos(5,15);
        cin >> melyik;
        hiba = cin.fail() || (0>melyik || melyik>3);
        if(hiba)
        {
            cout<<" Hibas adat! Mehetunk?\n";
            cin.clear(); getline(cin,tmp,'\n'); //pufferürítés
            getline(cin,tmp,'\n'); //a "Mehetünkre?" válasz beolvasása
            curPos(6,0); cout<<setfill(' ')<<setw(80)<<' ';
            curPos(7,0); cout<<setfill(' ')<<setw(80)<<' ';
        }
    }
    while (hiba);
    return melyik;
}

void feltoltNovekedve()
{
    s[1]=rand()%elemSzam+1;
    r[1]=s[1];
    for(int i=2;i<=elemSzam;++i)
    {
        s[i]=s[i-1]+rand()%3;
        r[i]=s[i];
    }
    tombKiiras("Feltolt novekedve");
}

void feltoltCsokkenve()
{
    s[1]=rand()%elemSzam+1;
    r[1]=s[1];
    for(int i=2;i<=elemSzam;++i)
    {
        s[i]=s[i-1]-rand()%3;
        r[i]=s[i];
    }
    tombKiiras("Feltolt csokkenve");
}

void feltoltMajdnemRendezve()
{
    int j,k,sv;

    s[1]=rand()%elemSzam+1;
    r[1]=s[1];
    for(int i=2;i<=elemSzam;++i)
    {
        s[i]=s[i-1]+rand()%3;
        r[i]=s[i];
    }
    for(int i=1;i<=elemSzam/10;++i)
    {
        j=rand()%elemSzam+1;
        do
        {
            k=rand()%elemSzam+1;
        }
        while (j==k);
        sv=s[j]; s[j]=s[k]; s[k]=sv;
        r[j]=r[k]; r[k]=sv;
    }
    tombKiiras("Feltolt majdnem rendezve");
}

void feltoltVeletlennel()
{
    for(int i=1;i<=elemSzam;++i)
    {
        s[i]=rand()%elemSzam+1;
        r[i]=s[i];
    }
    tombKiiras("Feltolt veletlennel");
}

void oraIndul()
{
    kezdet=clock();
    hSzam=0; mSzam=0;
}

void oraAll()
{
    veg=clock();
    elteltIdo=veg-kezdet;
}

void tombKiiras(string cim)
{
    ujLap();
    cout << cim << endl << endl;
    int meddig; //ameddig listázza az elemeket... az ellenőrzés kedvéért
    if (elemSzam<kiN)
    {
        meddig=elemSzam;
    }
    else
    {
        meddig=kiN;
    }
    for(int i=1;i<=meddig;++i)
    {
        cout << setw(4) << i << ':' << setw(5) << r[i];
    }
    cout << endl;
    billreVar();
}

void kiertekeles(string cim)
{
    tombKiiras(cim);
    cout << "\nEltelt ido:" << elteltIdo;
    cout << " | Hasonlitasok szama:" << hSzam << " | Mozgatasok szama:" << mSzam << endl;
    billreVar();
}

void egyszeruCseres()
{
    oraIndul();

    for (int i = 1; i < elemSzam; i++)
    {
        for (int j = i; j <= elemSzam; j++)
        {
            hSzam++;
            if (r[i] > r[j])
            {
                mSzam++;
                int tmp = r[i];
                mSzam++;
                r[i] = r[j];
                mSzam++;
                r[j] = tmp;
            }
            
        }
        
    }
    

    oraAll();
    kiertekeles("Egyszeru cseres");
    masol(); /* Az eredeti érték visszaállítása */
}

void minimumKivalsztasos()
{
    oraIndul();

    for (int i = 1; i < elemSzam; i++)
    {
        int MinI=i;
        for (int j = i+1; j <= elemSzam; j++)
        {
            hSzam++;
            if (r[MinI] > r[j])
            {
                MinI = j;
            }
            
        }
        mSzam++;
        int tmp = r[i];
        mSzam++;
        r[i] = r[MinI];
        mSzam++;
        r[MinI] = tmp;
        
    }

     oraAll();
     kiertekeles("Minimum-kivalasztasos");
     masol(); /* Az eredeti érték visszaállítása */
}

void buborek()
{
    oraIndul();

    for (int i = elemSzam; i > 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            hSzam++;
            if (r[j] > r[j+1])
            {
                mSzam++;
                int tmp = r[j];
                mSzam++;
                r[j] = r[j+1];
                mSzam++;
                r[j+1] = tmp;
            }
            
        }
        
    }
    

    oraAll();
    kiertekeles("Buborekos");
    masol(); /* Az eredeti érték visszaállítása */
}

void javitottBuborek()
{
    oraIndul();

    int i = elemSzam;
    while (i >=2)
    {
        int cs = 0;    
        for (int j = 1; j < i; j++)
        {
            hSzam++;
            if (r[j] > r[j+1])
            {
                mSzam++;
                int tmp = r[j];
                mSzam++;
                r[j] = r[j+1];
                mSzam++;
                r[j+1] = tmp;
                cs = j;
            }
            
        }
        i=cs;
        
    }
    

    oraAll();
    kiertekeles("Javitott buborekos");
    masol(); /* Az eredeti érték visszaállítása */
}

void beilleszteses()
{
    oraIndul();

    for (int i = 2; i <= elemSzam; i++)
    {
        int j=i-1;
        while (j>0 && r[j]>r[j+1])
        {
            mSzam++;
            int tmp = r[j];
            mSzam++;
            r[j] = r[j+1];
            mSzam++;
            r[j+1] = tmp;
            j--;
            hSzam++;
        }
        hSzam++;
        
    }
    

    oraAll();
    kiertekeles("Beilleszteses");
    masol(); /* Az eredeti érték visszaállítása */
}

void javitottBeilleszteses()
{
    oraIndul();

    for (int i = 2; i <= elemSzam; i++)
    {
        mSzam++;
        int tmp = r[i];
        int j=i-1;   
        while (j>0 && r[j]>tmp)
        {
            mSzam++;
            r[j+1] = r[j];
            j--;
            hSzam++;
        }
        hSzam++;
        mSzam++;
        r[j+1]=tmp;
        
    }

    oraAll();
    kiertekeles("Javitott beilleszteses");
    masol(); /* Az eredeti érték visszaállítása */
}

//r<=s:
void masol()
{
    for (int i=1;i<=elemSzam;++i)
    {
        r[i]=s[i];
    }
}

//billentyű-lenyomásra várakozik
void billreVar()
{
    system("pause");//windows esetében!
}

//kurzor-pozícionálás a konzol-ablakban:
void curPos(int s, int o)
{
    COORD hova;
    hova.X=o; hova.Y=s;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),hova);
}

//képernyőtörlés:
void ujLap()
{
    system("cls"); //képernyőtörlés
}
