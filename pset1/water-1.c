#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("How many minutes do you take a shower?\n");
    
    int x = GetInt();
    int y = (1.5 * 128) / x;

    if (x > 0)
    {
        printf("You are using %d bottles of water!\n", y);
    }
    else
    {
        printf("Please enter a number.\n");
    }
}