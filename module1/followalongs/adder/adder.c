#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Type a interger: ");
    int x = GetInt();
    printf("Type another interger: ");
    int y = GetInt();
    
    printf("The sum of %d and %d is %d\n", x,y,x+y);
}