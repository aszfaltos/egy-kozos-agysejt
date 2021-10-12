#include <iostream>

using namespace std;

int const MaxN = 1000;
struct KonyvT{
  string author;
  string title;
  int page;
};

typedef KonyvT KonyvekT[MaxN];

void beolvas(int&  n, KonyvekT books){
  cout << "N=? :";
  cin >> n;
  string line;
  size_t pos;
  getline(cin,line);
  for (size_t i = 0; i < n; i++) {
    cout << (i+1) << ". konyv adatai:" << endl;
    getline(cin,line);
    pos=line.find(";");
    books[i].author = line.substr(0,pos);
    line = line.substr(pos+1);
    pos=line.find(";");
    books[i].title=line.substr(0,pos);
    line=line.substr(pos+1);
    books[i].page=atoi(line.c_str());
  }
}

int osszegez (int n,KonyvekT konyvek){
  int sum =0;
  for (size_t i = 0; i < n; i++) {
    sum+=konyvek[i].page;
  }
  return sum;
}

int megszamol(int n, KonyvekT konyvek, string author){
  int count =0;
  for (size_t i = 0; i < n; i++) {
    if (konyvek[i].author==author) {
      count++;
    }
  }
  return count;
}

string leghosszabb(int n, KonyvekT konyvek){
  int max = konyvek[0].page;
  int index = 0;
  for (size_t i = 1; i < n; i++) {
    if (max < konyvek[i].page) {
      max=konyvek[i].page;
      index = i;
    }
  }
  return konyvek[index].title;
}

void kiir(int a, int b, string c){
  cout << a << endl << b << endl << c << endl;
}
int main(int argc, char const *argv[]) {
  cout <<"Konyvek"<< endl;
  int N;
  KonyvekT konyvek;

  int ossz;
  int jokai;
  string lc;

  beolvas(N,konyvek);
  ossz=osszegez(N,konyvek);
  jokai=megszamol(N,konyvek,"Jokai Mor");
  lc=leghosszabb(N,konyvek);
  kiir(ossz,jokai,lc);
  return 0;
}
