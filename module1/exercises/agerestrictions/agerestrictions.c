#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("How old are you: ");
    int age = GetInt();
    
    if( age < 16 )
    {
        printf("Not much to do.\n");
    }
    if( age >= 16 )
    {
        printf("You can drive!\n");
    }
    if( age >= 18 )
    {
        printf("You can vote!\n");
    }
    if( age >= 21 )
    {
        printf("You can drink!\n");
    }
}