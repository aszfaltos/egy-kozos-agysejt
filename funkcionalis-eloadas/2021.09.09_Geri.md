# Funkcionális programozás 1. előadás
- Készítette: Huszár GErgő
- Tárgy: Funkcionális programozás, előadás

---
1. Tudnivalók
   1. Miért jó?
2. Bevezető
   1. Kiértékelés
---
# Tudnivalók
- Az előadás egész és negyed között kezdődik
- A fordító fordítási időben kiszűri a hibákat
  - Nagyon szigorúan ellenőriz
  - Ha hibát talál, akkor nem engedi tovább a fordítást
## Miért jó?
- A feladat leírása nem az algoritmusé
- Feladat megfogalmazása
  - Függvények segítségével
  - *Mit kell csinálni?* kérdésre kell csak válaszólni, a *Hogyan?* kérdést itt nem tárgyaljuk
  - Kiértékelő rendszer
- Kevesebb sort eredményezhet
  - Kevesebb hiba
  - Kevesebb a költség
- Kevesen tudnak ebben jól fejleszteni
- Nagyon gyors, és gyorsítható
  - A fordító és a kiértékelő program kezeli, hogy hány processzoron fusson a program
# Bevezető
- A kommentelés nem divat
- Függvény azonosító: definiálandó függvényhez kell
  - beszédes nevek
- Függvény definíció:
  - Itt adjuk megy a függvény értékeinek típusait
    - Paraméterek értékek típusa
    - Visszatérési értékek típusa
- Formális paraméter: definíciónál adjuk meg
- Aktuális paraméter: függvényhíváskor adjuk meg
- Kifejezés a definiáló egyenlőségtől jobbra helyezkedő rész
  - Ez adja meg a függvény visszatérési értékét
  - Függvény törzs
  - Bármely függény itt meghívható, még az éppen definiált függvényt is
- Definiáló egyenlőség: a paraméter és a kifejezés közötti `=`
- Nincs értékadás!!!
  - A memória gyorsan fogy
- Változókat nem lehet felülírni => konstansok
  - pl.: 1 konstans függvény
- Összeadás függvény
  - Két azonos típusú számot ad össze
- `prod [1..n]`
  - `..` számtani sorozatot ad vissza
  - `1` alsó korlát
  - `n` felső korlát, elhagyható -> végtelenbe megy
  - `prod` összeszorozza a megadott értékeket
- `[1,3..8]`
  - `1` alsó korlát
  - `3` második elem --> differenciál a második elem és az elsőkorlát különbsége
  - `8` felső korlát, elhagyható -> végtelenbe megy
- Kezdeti kifejezés:
  - 1 lehet egy programban
  - A programom értékét adja vissza
- Kiértékelési idő fontos szempont
- Hatékonyság is fontos
## Kiértékelés
- Szigorú (strict)
  - Sima behelyettesítés
- Lusta (Lazy)
