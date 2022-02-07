# Objektum orientált programozás<br>

Kecskés Bence<br>
Kezdés: 2/7/2022

---

# Források

## Objektum orientált

* https://web.microsoftstream.com/video/3dd1a0f8-41e2-4e4c-853c-928dcce891e3
  * előadások
* Canvas
  * kvízek, zh-k
* https://tms.inf.elte.hu
  * beadandók, géptermi zh-k
* https://people.inf.elte.hu/gt/oep
  * előadások prezentációja
  * háttéranyagok
  * nagy beadandók leírása
  * korábbi zh-k

---

# Tartalomjegyzék

1. Típus és osztály


---

_2/7/2022_
# Típus és osztály
## Procedurális vs Objektumelvű programozás

### Procedurális
- Egy probléma részfeladatait megoldó tevékenységeket önálló egységekbe, procedúrákba szervezzük

### Objektumelvű
- Egy probléma megoldáshoz szükséges adatok egy-egy részét a hozzájuk kapcsolódó tevékenységekkel együtt egységekbe, objektumokba zárjuk

**Feladat: melyik egy számsorozat leggyakoribb eleme?**

| Procedurális megoldás | Objektumelvű megoldás|
| :--- | :--- |
| Maximum kiválasztás és számlálás| Tároló objektum |
| Megszámoljuk az elemek számát és kiválasztjuk a legnagyobbat| Elhelyezzük a tároló objektumban a számsorozat elemeit, majd lekérdezzük a benne található leggyakoribb elemet. Legyen az elhelyezés és a lekérdezés is gyors. |

## Megoldás menete
1. Elemzés
![](oep1.jpg)
2. Tervezés
![](oep2.jpg)
3. Megvalósítás
![](oep3.jpg)
4. Tesztelés

## Sorozat beolvasása txt-ből
```cpp
ifstream f("input.txt");
if(f.fail())
{
  cout << "File open error!\n";
}else{
  vector<int> x;
  int e;
  while( f >> e){
    x.push_back(e);
  }
}
```

## Adattípus fogalma

- A típus-specifikáció megadja:
  - az adat által felvehető értékek halmaazát
  - a típusértékekkel végezhető műveleteket
- a típus-megvalósítás megmutatja:
  - hogyan ábrázoljuk (reprezentáljuk) a típus értékeit
  - milyen programok helyettesítsék (implementálják) a műveleteket

## Zsák típus műveletei

- Zsák kiürítése
- Betesz egy elemet a zsákba
- Zsák leggyakoribb eleme

## Zsák típus reprezentációja
![](oep4.jpg)

## Zsák típus implementációja
![](oep5.jpg)

**Objektum fogalma**
: Olyan önálló egyedként azonosított része a feladat megoldásának, amely a megoldás egy részéért felelős adatokat, és az ezekkel kapcsolatos műveleteket foglalja magába.

**Osztály fogalma**
: Az osztály egy objektum szerkezetének és viselkedésének a mintáját adja meg, lényegében az objektum típusa. Az objektumot az osztálya alapján példányosítjjuk. Egy osztályhoz több objektum is példányosítható.Osztályként adjuk meg az egyedi, vagy ún. felhasználói típusokat.

## Zsák C++ nyelven

```cpp
class Bag
{
private:
  vector<int> _vec;
  int _max;

public:
  void erase();
  void putIn(int e);
  int mostFrequent() const;
}

void Bag::erase()
{
  for(unsigned int i=0; i <_vec.size(); ++i)_vec[i] = 0;
  _max=0;
}

void Bag::putIn(int e)
{
    if (e<0 || e>=int(_vec.size())) return;
    if (++_vec[e] > _vec[_max]) _max = e;
}

int Bag::mostFrequent() const
{
  if(0 == _vec[_max]) return -1; //hibakezelés még hiányzik
  return _max;
}
```

## Konstruktor

```cpp
Bag::Bag(int m) {_vec.resize(m+1); erase();}
```

*Az objektum orientált nyelvek fontos ismérve az elrejtés (private/public)*

## Program

**bag.h**

```cpp
#pragma once
#include <vector>
class Bag
{
class NegativeSizeException : std::exception {};
class IllegalElementException : std::exception {};
class EmptyBagException : std::exception {};

private:
  std::vector<int> _vec;
  int _max;
public:
  Bag(int m);
  void erase();
  void putIn(int e);
  int mostFrequent() const;
  };
```

**bag.cpp**

```cpp
#include "bag.h"
Bag::Bag(int m) : _vec(m+1, 0), _max(0)
{
if( m<0 ) throw new NegativeSizeException;
}
void Bag::erase()
{
for(unsigned int i=0; i<_vec.size(); ++i) _vec[i] = 0;
_max = 0;
}
void Bag::putIn(int e)
{
if( e<0 || e>=int(_vec.size()) ) throw new IllegalElementException;
if( ++_vec[e] > _vec[_max] ) _max = e;
}
int Bag::mostFrequent() const
{
if( 0 ==_vec[_max] ) throw new EmptyBagException;
return _max;
}
```

**main.cpp**
```cpp
#include <iostream>
#include <fstream>
#include "bag.h"
using namespace std;
int main()
{
ifstream f( "input.txt" );
if( f.fail() ){ cout << "File open error!\n"; return 1; }
int m; f >> m;
if( m<0 ){ cout << "Upper limit of natural numbers cannot be negative!\n"; return 1; }
try {
Bag b(m);
int e;
while( f >> e ) { b.putIn(e); }
cout << "The most frequent element: "<< b.mostFrequent() << endl;
} catch(Bag::NegativeSizeException) {
cout << "Upper limit of the natural numbers is negative.\n";
} catch(Bag::IllegalElementException) {
cout << "One of the given elements is not in the interval 0 .. m.\n";
} catch(Bag::EmptyBagException) {
cout << "There is no most frequented number if there are no numbers.\n";
}
return 0;
}
```

## Automatikus tesztelés
*https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md*

**main.cpp**
```cpp
#include <iostream>
#include <fstream>
#include "bag.h"
using namespace std;
int main()
{
ifstream f( "input.txt" );
if( f.fail() ){
cout << "File open error!\n";
return 1;
}
int m; f >> m;
if( m<0 ){
cout << "Upper limit of natural numbers cannot be negative!\n";
return 1;
}
Bag b(m);
int e;
while( f >> e ) {
b.putIn(e);
}
cout << "The most frequent element: "<< b.mostFrequent() << endl;
return 0;
}
TEST_CASE("empty sequence", "[main]"){
ifstream f( "input1.txt" ); REQUIRE(!f.fail());
int m; f >> m; CHECK(m==35); REQUIRE(m>=0);
Bag b(m);
int e;
while( f >> e) { b.putIn(e); }
CHECK _THROWS(b.mostFrequent());
}
TEST_CASE("one-length sequence", "[main]"){
ifstream f( "input2.txt" ); REQUIRE(!f.fail());
int m; f >> m; CHECK(m==35); REQUIRE(m>=0);
Bag b(m);
int e;
while( f >> e ){ b.putIn(e); }
CHECK(b.mostFrequent()==2);
}
```
