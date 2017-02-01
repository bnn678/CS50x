#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int x;
    do
    {
        printf("How many orange slices do you want to eat? ");
        x = GetInt();
    }
    while (x < 1);
    
    int i = (x / 8.0);
    float f = ceil(i);
    printf("You should buy %f oranges!\n", f);
}