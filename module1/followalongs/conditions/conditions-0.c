#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Give me an int: ");
    int x = GetInt();
    
    if( x > 0 )
    {
        printf("You picked a positive int\n");
    }
    else
    {
        printf("You picked a negatvie int\n");
    }
}