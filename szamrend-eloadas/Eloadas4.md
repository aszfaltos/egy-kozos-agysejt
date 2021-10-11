# Számítástechnikai rendszerek elődadás, 4. óra jegyzete
- Készítette: Huszár Gergő
- Tárgy: számítástechnikai rendszerek, elődadás

---
1.  Kimenet Bemenet áirányítások
2.  Szűrők
    1.  Fontosabb szűrők
    2.  Reguláris kifejezések, REGEXP
        1.  Bővítések
3.  Szövegszerkesztők
4.  Változok
---

# Kimenet Bemenet áirányítások
- stdin 0 - billenytűzet
- stdout 1 - monitor
- stderr 2 - monitor
- Átirányítások
  - `>` kimenet
  - `<` bemenet
  - hiba kimenet 2>, 2>>
  - <<
    -  Helyben megadott szöveg beirányítása
# Szűrők
- Parancs vs szűrő
  - Szűrő együttműködést biztosít
  - Az előző parancs kimenetét a szűrő tudja bemenetként fogadni
- Összekapcsolásuk jele a pipe `|`
  - Ez esteben az 1. hely a parancspozíció
## Fontosabb szűrők
- `tee`
  - olyasmi mintha 
- `tr`
  - karaktereket cserél egy szövegben
  - két paramétert és egy bemeneti szöveget vár
  - paraméterek: `mit cserél` `mire cserél` a szövegben lévő karakter helye alapján
- `cut`
  - mezőket, sorokat , oszlopokat lehet stdinputból kivágni
  - `-c` és `-f`, `-d` kapcsolok segítségével
- `grep`
  - kereső
## Reguláris kifejezések, REGEXP
- http://vbence.web.elte.hu/regex_leiras.html
- Üres sorok: `^$`
- Escape-elt akrakterek
  - \w alfanumerikus karakterek
  - \W nem alfanumerikus karakterek
  - \d számjegyek
  - \b helyköz
  - \s white space
### Bővítések
- | vagy egyik vagy másik oldalán lévő dolog teljesül
- + legalább 1-szer ismétlődik
- ?  0 v. 1 szer ismétlődik
- {n} - előző karakter n szer ismétlődik
  - {n,m} n és m közötti értékszer ismétlődik, n és m is bele esik 
- () kifejezés csoportot denifiál
# Szövegszerkesztők
- vi tradicionális szövegszerkesztő unix rendszereken
  - Ez minden unix rendszeren megtalálható
- nano, mcedit, joe stb.
# Változok
- Csak szöveges változók
- Típusok
  - Környezeti változó
- Definiáció
- `változó_neve=érték`
  - > az egyenlőség jelek között nem lehet helyköz!!!!
- hivatkozás `$` karakter segítségével
  - pl.: `$var`
- `unset` segítségével lehet változó törölni
- `${var}` A kapcsos zárójelek közötti név határozza meg a változó nevét
# Parancs behelyettesítés
- \` között parancsként van értelmezve a parancs karakterei
  - pl.: a = \`whoami\`