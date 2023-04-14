#include <stdio.h>


void function(char *s)
{
    puts(s);
}

typedef void (*VoidF)(char* string);

int main()
{
    function("Direct call");

    VoidF f = function;
    f("Indirect call");
    (*f)("Indirect single dereference call");
    (**f)("Indirect double dereference call");

    VoidF reassign_0 = (*f);
    VoidF reassign_1 = (**f);
    VoidF reassign_2 = (***f);

    reassign_0("Reassign call from reassign_0");
    reassign_1("Reassign call from reassign_1");
    reassign_2("Reassign call from reassign_2");
    (*reassign_2)("Reassign call from reassign_0 dereferences");

}