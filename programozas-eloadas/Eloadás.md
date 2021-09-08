# Programozás 1. előadás jegyzete
- Készítő: Huszár Gergő
- Tárgy: Programozás, előadás

---
1. Bevezető
   1. Számonkérés
2. Programozás alapok
   1. Miből áll?
   2. Specifikáció
   3. Algoritmus
   4. Specifikáció és megvalósítás
   5. Stuktogramm
   6. Adatok
   7. Típusok
3. Jelölések
---
# Bevezetők
- http://progalap.elte.hu a tárgy hivatalos oldala
  - AZ összes ppt és tananyag itt lesz/van fenn
- Gyorsított tanterv
- Kezdés 8:30
- Lehet érdemesebb a ppt-t átfutni
## Számonkérés
- Januárban a vizsga
  - A módja még kérdéses
- A többi a gyakon elmondottak alapján
# Programozás alapok
## Miből áll?
1. Spekulálás
2. Tervezés
3. Kódolás
4. Tesztelés
5. Hibakeresés
6. Hibajavítás
7. Minőség vizsgálat, hatákonyság
     - A felhasználónak jó legyen használni
8. Dokumentálás
9. Használat, karbantartás
   - Legnagyobb költségek
   - További funkciók hozzáadása
## Specifikáció
- Célja
- Tulajdonság
  - Pontos
  - Tömör
  - Érthető
- Eszközei
  - Szöveges leírásű
    - NEm mindig tömör és pontos
  - Matek
    - Nem mindig érthető
  - Mindkettő szerepel
- Váza
  - Bemenet
    - Bemeneti adatok és várható típusuk
  - Kimenet
    - Kimeneti adatok és várható típusuk
  - Előfeltétel
    - Bemeneti adatokra vonatkozó feltételek
  - Utófeltétel
## Algoritmus
- 4 részből áll
  - adat deklarálás
  - adat beolvasás
  - eredmény kiszámítás
  - eredmény kiírás
## Specifikáció és megvalósítás
- Kell
  - Beolvasás
  - Eredményszámítás
  - Eredmény kiírás
## Stuktogramm
- Szekvencia
- Elágazás
- Ciklusok
## Adatok
- Konstans
  - Nem változtathatja meg értékét
- Változó
  - Változhat
  - Céljaik
    - Bemenetkor kap értéket
    - Eredmény során kap értéket
    - ...
- Értékadás
- Típusok
- Azonosító
  - Karakter kódolás (Milyen betüket, számokat használhat)
  - Maximális hossz
- Kezdőérték
  - Születéskor hozzárendelt érték
  - Nyelvek között változó ez az érték
    - Lehet pl.: 0, null stb.
## Típus
- Összetettség
  - strukturálatlan
  - strukturált
- Elemi típusok
  - Egész számok
    - Korlátozott halmaza az egész számoknak
      - Tól-ig érték
  - Valós számok
    - Veszélyes a hazsnálata
    - Nem mindig pontos
  - Logikai érték
    - 0 szám hamis
    - Nem 0 szám igaz
  - Karakter típus
    - ASCII kódtábla alapján
    - 0-255 db katakter fér el benne
    - Mivel csak az angol abc betűi voltak benne eleinte így a később hozzáadott más nyelvi jelek nem az abc szerinti megfelelő helyükre kerültek. --> a relációk pl.: magyar nyelvnél nem működnek helyesen
- Rekordok, struktúrák
  - Struktúrák
    - A részeknek neve van
  - Rekord
    - Új típust hozunk létre

## Ciklusok
- Típusok
  - Feltételes ciklusok
    - Előltesztelős
    - Hátúltesztelős
  - For ciklus
### Jelőlések
- K - karakterek halmaza
- S - szövegek halmaza
- R - természetes számok halmaza
- L - logikai értékeke halmaza