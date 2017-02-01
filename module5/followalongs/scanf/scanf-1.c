#include <stdio.h>

int main(void)
{
    char* s = NULL;
    printf("String please: ");
    scanf("%s", s);
    printf("Thanks for %s!\n", s);
}