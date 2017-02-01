#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("minutes: ");
    int minutes = GetInt();
    int bottles = ((minutes*1.5) * 128) / 16;
    printf("bottles: %d \n", bottles);
    
}