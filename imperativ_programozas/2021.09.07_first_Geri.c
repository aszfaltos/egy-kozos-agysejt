#include <stdio.h>
/* beincludoljuk a foo.h-t amiben a fooo() függvény található 
include "path/file_name" itt meghatározod, hogy hol keresse 
include <file_name> egész rendszerben körbenéz ezért a fájlért
*/
#include "foo.h"

/*
    Egy függvény többször deklarálható, viszont csak egyszer definiálható!
*/

/*
 Ez oké
*/
void foo();
void foo();
void foo();
void foo();

/*
Ez nem oké, hibát fog dobni!

int foo()
{
    int a;
    ...
}

int foo()
{
    int b;
    ...
}
*/ 


void foo()
{
    printf("Hello world!\n");
}

int main()
{
    int a = 0;
    int b = 1;
    int c = 2;


    
    foo();

    /* Itt kétszer fog lefutni a foo() függvény! */
    foo(), foo();

    /* a foo.h ban lévő függvény futtatása */
    fooo();
    printf("A háromszög oldalai: %d, %d, %d; Kerülete: %d\n", a, b, c, a + b + c);

    printf("Adjon meg egy számot: ");
    scanf("%d", &a);
    printf("A beadott érték: %d\n", a);

    return 0;
}
