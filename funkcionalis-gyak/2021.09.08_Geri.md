# Funkcionális prog. első gyakorlat
- Készítette: Huszár Gergő
- Tárgy: Funkcionális programozás, gyakorlat

---
1. Bevezető
2. Követelmények
3. Haskell
   1. Fájl betőltése
---
# Bevezető
- Nagy Gergely
- Elérhetőség: nagygeri97@gmail.com
- 8:30-as kezdés
- Tárgyinfók: http://lambda.inf.elte.hu
# Követelmények
- Max kb. 3 hiányzás
- Minden órára házi
  - https://tms.inf.elte.hu
- Röpik minden óra elején
  - Összes szerezhetó pont 50%-át kell elérni
- Utólsó héten "nagy" beadandó
  - 10 pont
  - beleszámít az  évvégi jegybe
- Vizsga
# Haskell
- deklaretív nyelv
- statikusan típusos
- szigorúan típusos
- hatványoszás jobbra köt
- a többi balra köt
- Add meg a típusát: `:t vlami`
- `:i (operátor)` infó egy operátorról 
  - pl.: 
  - ```haskell
    :i (+)
    ```
- `1 :: Int` véges nagy szám
- `1 :: Integer` végtelen nagy szám
- ``` 5 `div` 2 ``` vagy `mod 5 2`
- ``` 5 `mod` 2 ``` vagy `div 5 2`
- Nem egyenlő: `/=`
- Függvények alkalmazása a legerősebb operátor
- `1 + 2` azonos `(+) 1 2`
- Minden egyszer deklarálható, definiálni
- Infix függvények erőssége kb a szorzással azonos
- `not` 
  - True -> False és fordítva
  - prefix
## Fájl betőltése
1. Terminálon lépjünk be a fáhl mappájába
2. Irjuk be a `ghci` szöveget
3. Majd a `:l fájl_név` segítségével becsatóljuk
4. Ha változtatás történik újra kell tőlteni a modult! `:r`
