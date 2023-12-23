#include <stdio.h>

void reverse(char x[])
{
    if(*x != '\0')
    {
        reverse(x+1);
    }
    printf("%c\n", *x);
}

int main()
{
    char x[] = "123";
    reverse(x);

    return 0;
}
