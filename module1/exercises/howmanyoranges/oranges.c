#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    printf("How many orange slices do you want to eat: ");
    int slices = GetInt();
    
    float oranges = ceil(slices / 8.0);
    
    printf("You should buy %.1f oranges!\n",oranges);
}