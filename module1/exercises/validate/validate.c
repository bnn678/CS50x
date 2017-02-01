#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x;
    do
    {
        printf("Give me an even interger PLEASE: ");
        x = GetInt();
    }
    while( x % 2 != 0);
    
    printf("Thank you!\n");
}