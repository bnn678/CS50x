#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    printf("Change due: ");
    float input = GetFloat();
    
    while( input < 0 )
    {
        printf("That was not a valid entry. Try again: ");
        input = GetFloat();
    }
    
    int change = round(input*100);

    int coins_used = 0;
    
    while( change >= 25 )
    {
        change -= 25;
        coins_used += 1;
    }
    while( change >= 10 )
    {
        change -= 10;
        coins_used += 1;
    }
    while( change >= 5 )
    {
        change -= 5;
        coins_used += 1;
    }
    while( change >= 1 )
    {
        change -= 1;
        coins_used += 1;
    }
    
    printf("%i\n",coins_used);
}