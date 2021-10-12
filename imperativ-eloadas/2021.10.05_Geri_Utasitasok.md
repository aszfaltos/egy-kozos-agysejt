# Imperatív Programozás előadás jegyzete: 
- Készítő: Huszár Gergő
- Tárgy: Imperatív Programozás, előadás

---
1. Egyzserű utasítások
   1. Változó deklaráció
   2. Értékadás-utasítás C-ben
   3. Értékadás pythonban
   4. Kifejezés-utasítás python
   5. Függvények C-ben
   6. Visszatérés
   7. Üres utasítás
2. Vezérlési szerkezetek
   1. Struktúrált programozás
   2. Szekvencia
   3. Vezérlési szerkezetek belseje
   4. Elágazás
---

# Egyzserű utasítások
## Változó deklaráció
- pythonban nincs
- c-ben minden első használat előtt
## Értékadás-utasítás C-ben
- `int a = 0;`
- stb..
- Pontosvessző a végén
## Értékadás pythonban
- utasítás, nem kifejezés
- szimúltán értékadás
  - a, b = b, a - két változó értékének felcserélése
- többszörös értékadás
  - a = b = 1
- ha t egy pár akkor mintaillesztés
  - a, b = t
## Kifejezés-utasítás python
- Függvényhívás
  - Mellékhatásos
    - Álltalában nincs visszatérési értéke
  - Tiszta
    - Mindig van visszatérési értéke
## Függvények C-ben
- A vissza térési értéket meg kell határozni
  - Ha nincs akkor `void` típusú a függvény
## Visszatérés
- return segítségével ha van neki visszatérési értéke
- Egyébként nem kell return
- Lehet több return is a függvényben
## Üres utasítás
- C: `;`
- Python: `pass`
# Vezérlési szerkezetek
## Struktúrált programozás
- Felépítése
  - Szekvencia
  - Elágazás
  - Cilus
- Mindent le lehet ezzel írni
## Szekvencia
- Utasítások egymás után írása
- Blokkutasítás C-ben
  - `{}` közötti utasítások
## Vezérlési szerkezetek belseje
- Python
  - Margó utasítás
- C-ben
  - Egy utasítás
  - Blokk utasítás
## Elágazás
- if (else)
- C-ben csellengő else
