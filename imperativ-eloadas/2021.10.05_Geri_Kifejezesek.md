# Imperatív Programozás előadás jegyzete: 
- Készítő: Huszár Gergő
- Tárgy: Imperatív Programozás, előadás

---
1. Pure és impure
2. Kiértékelések
   1. Lusta, mohó
   2. Operandusok, függvények kiértékelése
   3. Szekvencia pont
---

# Pure és impure
- Impure 
  - Van mellék hatás
- Pure
  - Nincs mellékhatás
# Kiértékelések
- Számok esetén **precedencia** - kötési erősség
- Jobb- és balasszociatívitás
  - Azonos precedencia szint esetén lép színre
- Mellékhatások
  - Értékadás
    - C-ben fontos:
      - ++i 
        - Először növeljük az értékét, és utána olvassuk ki
      - i++
        - Először kiolvasuk az értéket utána növeljük
  - Vannak ilyen függvények is
## Lusta, mohó
- mohó
  - operandusokat értékeli ki mindig először utána jön az operátor
  - pl.: `+`, `-`
- lusta
  - Először az operátort értékeli ki
  - pl.: `&&`, `||`, `?:`
## Operandusok, függvények kiértékelése
- C-ben ennek sorrendje nincsen meghatározva
  - pl.: `a + b` kifejezésnél nem biztos, hogy az `a` értékét értékeli ki először
## Szekvencia pont
- Egy olyan pont mely teljesen szét tud választani két kifejezést
- pl:
  - forciklusban az utolsó részben
  - `for (;;itt)`
  - Veszző operátor
    -
      ```c
      int i = 1, v;
      v = (i++, ++i); /* Itt a v értéke 3 lesz*/
      ```
