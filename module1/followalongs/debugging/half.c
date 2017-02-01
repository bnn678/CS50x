#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Please enter a number: ");
    float num = GetInt();
    
    num = num / 2;
    
    printf("Half of that number is %.3f.\n",num);
    return 0;
}